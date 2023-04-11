#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <cstdlib>
using namespace std;

// Определяем емкость queue по умолчанию
#define SIZE 1000

// Класс для хранения queue
class Queue
{
    double* arr;       // массив для хранения элементов queue
    int capacity;   // максимальная емкость queue
    int front;      // front указывает на передний элемент в queue (если есть)
    int rear;       // задняя часть указывает на последний элемент в queue
    int count;      // текущий размер queue

public:
    Queue(int size = SIZE);     // конструктор
    ~Queue();                   // деструктор

    int dequeue();
    void enqueue(double x);
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
};

// Конструктор для инициализации queue
Queue::Queue(int size)
{
    arr = new double[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

// Деструктор для освобождения памяти, выделенной для queue
Queue::~Queue() {
    delete[] arr;
}

// Вспомогательная функция для удаления переднего элемента из очереди
int Queue::dequeue()
{
    // проверка на опустошение queue
    if (isEmpty())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    double x = arr[front];
    cout << "Removing " << x << endl;

    front = (front + 1) % capacity;
    count--;

    return x;
}

// Вспомогательная функция для добавления элемента в queue
void Queue::enqueue(double item)
{
    // проверка на переполнение queue
    if (isFull())
    {
        cout << "Overflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    cout << "Inserting " << item << endl;

    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
}

// Вспомогательная функция для возврата первого элемента queue
int Queue::peek()
{
    if (isEmpty())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    return arr[front];
}

// Вспомогательная функция для возврата размера queue
int Queue::size() {
    return count;
}

// Вспомогательная функция для проверки, пуста ли queue или нет
bool Queue::isEmpty() {
    return (size() == 0);
}

// Вспомогательная функция для проверки того, заполнена ли queue или нет
bool Queue::isFull() {
    return (size() == capacity);
}

int main()
{
    // создаем queue емкостью n
    int movie_num;
    cout << "Enter count queue:\n";
    int n; cin >> n;
begin2:
    Queue q(n);
    cout << &n << '\n';

    cout << "Enter a number...\n";
    cout << "1 - enter in queue\n";
    cout << "2 - queue status\n";
    cout << "3 - delete in queue\n";
    cout << "4 - change count queue\n";
    cout << "5 - exit\n";

begin:
    cin >> movie_num;
    switch (movie_num)
    {
    case 1:
        double num1; double num2;
        cout << "Enter a count:\n";
        cin >> num1; cin >> num2;
        q.enqueue(num1);
        q.enqueue(num2);
        cout << &num1 << '\t' << &num2 << '\n';
        goto begin;
    case 2:
        cout << "The front element is " << q.peek() << '\n';
        goto begin;
    case 3:
        q.dequeue();
        if (q.isEmpty()) {
            cout << "The queue is empty\n";
        }
        else {
            cout << "The queue is not empty\n";
        }
        goto begin;
    case 4:
        //изменение размера очереди
        cout << "Enter a new count for Queue:\n";
        int* size2;
        size2 = (int*)malloc(n);
        if (!size2)
        {
            printf("Allocation error.");
            exit(1);
        }
        cin >> n;
        size2 = (int*)realloc(size2, n);
        if (!size2)
        {
            printf("Allocation error.");
            exit(1);
        }
        *size2 = n;
        free(size2);
        goto begin2;
    case 5:
        break;
    }
    return 0;
}