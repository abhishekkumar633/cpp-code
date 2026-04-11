#include <stdio.h>
#include <stdlib.h>
typedef struct DoublyLinkedList {
    int data;
    struct DoublyLinkedList* next;
    struct DoublyLinkedList* prev;
} DList;
int countElements(DList*);
DList* createNode(int data) {
    DList* newNode = (DList*)malloc(sizeof(DList));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
DList* createList(DList* head) {
    int data, choice;
    DList* tail = NULL;
    do {
        printf("Enter data: ");
        scanf("%d", &data);
        DList* newNode = createNode(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        printf("Enter 1 to insert more data: ");
        scanf("%d", &choice);
    } while (choice == 1);
    return head;
}
void printList(DList* node) {
    while (node != NULL) {
        printf("%d <-> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}
DList* insertAtFirst(DList* head, int data) {
    DList* newNode = createNode(data);
    if (head != NULL) {
        newNode->next = head;
        head->prev = newNode;
    }
    return newNode;
}
DList* insertAtLast(DList* head, int data) {
    DList* newNode = createNode(data);
    if (head == NULL) return newNode;
    DList* current = head;
    while (current->next != NULL) current = current->next;
    current->next = newNode;
    newNode->prev = current;
    return head;
}
DList* insertAtPosition(DList* head, int data, int position) {
    int length = countElements(head);
    if (position < 1 || position > length + 1) {
        printf("Invalid position. Please enter a position between 1 and %d.\n", length + 1);
        return head;
    }
    if (position == 1) return insertAtFirst(head, data);
    if (position == length + 1) return insertAtLast(head, data);
    DList* newNode = createNode(data);
    DList* current = head;
    for (int i = 1; i < position - 1 && current != NULL; i++) current = current->next;
    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL) current->next->prev = newNode;
    current->next = newNode;
    return head;
}
DList* insertAfter(DList* head, int target, int data) {
    DList* current = head;
    int found = 0;
    while (current != NULL) {
        if (current->data == target) {
            found = 1;
            DList* newNode = createNode(data);
            newNode->next = current->next;
            newNode->prev = current;
            if (current->next != NULL) current->next->prev = newNode;
            current->next = newNode;
            current = newNode;
        }
        current = current->next;
    }
    if (!found)
        printf("The target data %d was not found in the list.\n", target);
    return head;
}

DList* deleteFirst(DList* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    DList* temp = head;
    head = head->next;
    if (head != NULL) head->prev = NULL;
    free(temp);
    return head;
}
DList* deleteLast(DList* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    DList* current = head;
    while (current->next != NULL) current = current->next;
    current->prev->next = NULL;
    free(current);
    return head;
}
DList* deleteAtPosition(DList* head, int position) {
    int length = countElements(head);
    if (position < 1 || position > length) {
        printf("Invalid position. Please enter a position between 1 and %d.\n", length);
        return head;
    }
    if (position == 1) return deleteFirst(head);
    if (position == length) return deleteLast(head);
    DList* current = head;
    for (int i = 1; i < position && current != NULL; i++) current = current->next;
    current->prev->next = current->next;
    if (current->next != NULL) current->next->prev = current->prev;
    free(current);
    return head;
}
DList* deleteData(DList* head, int target) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    if (head->data == target) return deleteFirst(head);
    DList* current = head;
    while (current->next != NULL && current->next->data != target) current = current->next;
    if (current->next == NULL) {
        printf("Data not found.\n");
        return head;
    }
    DList* temp = current->next;
    current->next = temp->next;
    if (temp->next != NULL) temp->next->prev = current;
    free(temp);
    return head;
}
int countElements(DList* head) {
    int count = 0;
    DList* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}
int searchPresence(DList* head, int target) {
    DList* current = head;
    while (current != NULL) {
        if (current->data == target) return 1;
        current = current->next;
    }
    return 0;
}
int searchPosition(DList* head, int target) {
    DList* current = head;
    int position = 1;
    while (current != NULL) {
        if (current->data == target) return position;
        current = current->next;
        position++;
    }
    return -1;
}
int countOccurrence(DList* head, int target) {
    int count = 0;
    DList* current = head;
    while (current != NULL) {
        if (current->data == target) count++;
        current = current->next;
    }
    return count;
}
DList* sortList(DList* head) {
    if (head == NULL) return NULL;
    DList* current = head;
    DList* index = NULL;
    int temp;
    while (current != NULL) {
        index = current->next;
        while (index != NULL) {
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    }
    return head;
}
DList* reverseList(DList* head) {
    DList* current = head;
    DList* temp = NULL;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL) head = temp->prev;
    return head;
}
int main() {
    DList* head = NULL;
    int choice, ch, data, position, target;
    while (1) {
        printf("Menu:\n");
        printf("1->Create new list\n2->Print list\n3->INSERT\n");
        printf("4->DELETE\n5->Count nodes\n6->SEARCH\n");
        printf("7->Sort list\n8->Reverse list\n9->EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                head = createList(head);
                break;
            case 2:
                printList(head);
                break;
            case 3:
                printf("1->Insert at the first node\n2->Insert at the last node\n");
                printf("3->Insert into a given position\n4->Insert after a given data\n");
                printf("Enter your choice: ");
                scanf("%d", &ch);
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                switch (ch) {
                    case 1:
                        head = insertAtFirst(head, data);
                        break;
                    case 2:
                        head = insertAtLast(head, data);
                        break;
                    case 3:
                        printf("Enter the position: ");
                        scanf("%d", &position);
                        head = insertAtPosition(head, data, position);
                        break;
                    case 4:
                        printf("Enter the target data after which new data is to be inserted: ");
                        scanf("%d", &target);
                        head = insertAfter(head, target, data);
                        break;
                    default:
                        printf("Invalid choice.\n");
                        break;
                }
                break;
            case 4:
                printf("1->Delete the first node\n2->Delete the last node\n");
                printf("3->Delete from a given position\n4->Delete a given data\n");
                printf("Enter your choice: ");
                scanf("%d", &ch);
                switch (ch) {
                    case 1:
                        head = deleteFirst(head);
                        break;
                    case 2:
                        head = deleteLast(head);
                        break;
                    case 3:
                        printf("Enter the position: ");
                        scanf("%d", &position);
                        head = deleteAtPosition(head, position);
                        break;
                    case 4:
                        printf("Enter the data to be deleted: ");
                        scanf("%d", &target);
                        head = deleteData(head, target);
                        break;
                    default:
                        printf("Invalid choice.\n");
                        break;
                }
                break;
            case 5:
                printf("Number of elements in the list: %d\n", countElements(head));
                break;
            case 6:
                printf("1->Search to detect presence\n2->Search to find the position\n");
                printf("3->Search to find the occurrence count\n");
                printf("Enter your choice: ");
                scanf("%d", &ch);
                printf("Enter the data to search: ");
                scanf("%d", &target);
                switch (ch) {
                    case 1:
                        if (searchPresence(head, target))
                            printf("Data %d is present in the list.\n", target);
                        else
                            printf("Data %d is not found in the list.\n", target);
                        break;
                    case 2:
                        position = searchPosition(head, target);
                        if (position != -1)
                            printf("Data %d is found at position %d.\n", target, position);
                        else
                            printf("Data %d is not found in the list.\n", target);
                        break;
                    case 3:
                        printf("Data %d occurs %d times in the list.\n", target, countOccurrence(head, target));
                        break;
                    default:
                        printf("Invalid choice.\n");
                        break;
                }
                break;
            case 7:
                head = sortList(head);
                printf("List sorted.\n");
                break;
            case 8:
                head = reverseList(head);
                printf("List reversed.\n");
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}