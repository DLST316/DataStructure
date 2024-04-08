#include <stdio.h>
#include <string.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtHead(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void insertAtTail(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        struct Node* current = temp;
        temp = temp->next;
        free(current);
    }
}

void InsertionSort(struct Node* head) {
    struct Node* current = head;
    struct Node* sorted = NULL;
    
    while (current != NULL) {
        struct Node* next = current->next;
        
        if (sorted == NULL || sorted->data >= current->data) {
            current->next = sorted;
            current->prev = NULL;
            
            if (sorted != NULL) {
                sorted->prev = current;
            }
            
            sorted = current;
        } else {
            struct Node* temp = sorted;
            
            while (temp->next != NULL && temp->next->data < current->data) {
                temp = temp->next;
            }
            
            current->next = temp->next;
            current->prev = temp;
            
            if (temp->next != NULL) {
                temp->next->prev = current;
            }
            
            temp->next = current;
        }
        
        current = next;
    }
    
    head = sorted;
}

void InsertionSort(int arr[], int n) 
{
    int i, key, j;
    for (i = 1; i < n; i++) 
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() 
{
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    InsertionSort(arr, n);
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}