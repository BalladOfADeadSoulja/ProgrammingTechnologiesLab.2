#include <iostream>
using namespace std;

struct Node
{
    int data_int;
    double data_double;
    Node* next;
};

void addNode(Node** head, int newData, double newDoubleData)
{
    Node* newNode = (Node*)realloc(NULL, sizeof(Node));
    Node* last = *head;
    newNode->data_int = newData;
    newNode->data_double = newDoubleData;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = newNode;
    return;
}

void deleteNode(Node** head, int key)//удаляется сразу 2 элемента, как и добавляется по 2
{
    Node* temp = *head;
    Node* prev = NULL;

    if (temp != NULL && (temp->data_int == key || temp->data_double == key))
    {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && !(temp->data_int == key || temp->data_double == key))
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Element " << key << " not found in the list" << endl;
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void printList(Node* node)
{
    while (node != NULL)
    {
        if (node->data_int != -1)
        {
            cout << node->data_int << " -> ";
        }
        if (node->data_double != -1.0)
        {
            cout << node->data_double << " -> ";
        }
        node = node->next;
    }
    cout << "NULL" << endl;
    return;
}

int main()
{
    int choice;
    Node* head = NULL;
    int intElement;
    double doubleElement;
    do
    {
        cout << "1. Add element" << endl;
        cout << "2. Delete element" << endl;
        cout << "3. Show list" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter an integer element: ";
            cin >> intElement;
            cout << "Enter a double element: ";
            cin >> doubleElement;
            addNode(&head, intElement, doubleElement);
            break;
        }

        case 2:
        {
            int key;
            cout << "Enter element to delete: ";
            cin >> key;
            deleteNode(&head, key);
            break;
        }

        case 3:
        {
            cout << "Elements in the list:" << endl;
            printList(head);
            break;
        }

        case 4:
        {
            cout << "Exiting program." << endl;
            break;
        }

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    Node* temp = head;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}