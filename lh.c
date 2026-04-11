#include <stdio.h>
#include <stdlib.h>
typedef struct LinkedList {
    int data;
    struct LinkedList* next;
} LList;
int countElements(LList*);
LList* createNode(int data) {
    LList* newNode = (LList*)malloc(sizeof(LList));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
LList* createList(LList* head) {
    int data, choice;
    LList* tail = NULL;
    do {
        printf("Enter data: ");
        scanf("%d", &data);
        LList* newNode = createNode(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        printf("Enter 1 to insert more data: ");
        scanf("%d", &choice);
    } while (choice == 1);
    return head;
}
void printList(LList* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");  
}
LList* insertAtFirst(LList* head, int data) {
    LList* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}
LList* insertAtLast(LList* head, int data) {
    LList* newNode = createNode(data);
    if (head == NULL) return newNode;
    LList* current = head;
    while (current->next != NULL) current = current->next;
    current->next = newNode;
    return head;
}
LList* insertAtPosition(LList* head, int data, int position) {
    int length = countElements(head);
    if (position < 1 || position > length + 1) {
        printf("Invalid position. Please enter a position between 1 and %d.\n", length + 1);
        return head;
    }
    if (position == 1) return insertAtFirst(head, data);
    if (position == length + 1) return insertAtLast(head, data);
    LList* newNode = createNode(data);
    LList* current = head;
    for (int i = 1; i < position - 1 && current != NULL; i++)   current = current->next;
    newNode->next = current->next;
    current->next = newNode;
    return head;
}
LList* insertAfter(LList* head, int target, int new_data) {
    LList* current = head;
    int found = 0;
    while (current != NULL) {
        if (current->data == target) {
            found = 1;
            LList* newNode = createNode(new_data);
            newNode->next = current->next;
            current->next = newNode;
            current = newNode;
        }
        current = current->next;
    }
    if (!found)
        printf("The target data %d was not found in the list.\n", target);
    return head;
}
LList* deleteFirst(LList* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    LList* temp = head;
    head = head->next;
    free(temp);
    return head;
}
LList* deleteLast(LList* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    LList* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    return head;
}
LList* deleteAtPosition(LList* head, int position) {
    int length = countElements(head);
    if (position < 1 || position > length) {
        printf("Invalid position. Please enter a position between 1 and %d.\n", length);
        return head;
    }
    if (position == 1)  return deleteFirst(head);
    if (position == length) return deleteLast(head);
    LList* current = head;
    LList* previous = NULL;
    for (int i = 1; i < position && current != NULL; i++) {
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
    free(current);
    return head;
}
LList* deleteData(LList* head, int target) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    if (head->data == target)   return deleteFirst(head);
    LList* current = head;
    while (current->next != NULL && current->next->data != target)  current = current->next;
    if (current->next == NULL) {
        printf("Data not found.\n");
        return head;
    }
    LList* temp = current->next;
    current->next = temp->next;
    free(temp);
    return head;
}
int countElements(LList* head) {
    int count = 0;
    LList* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}
int searchPresence(LList* head, int target) {
    LList* current = head;
    while (current != NULL) {
        if (current->data == target)   return 1;
                                     
        current = current->next;
    }
    return 0;
}
int searchPosition(LList* head, int target) {
    LList* current = head;
    int position = 1;
    while (current != NULL) {
        if (current->data == target)    return position;
        current = current->next;
        position++;  
    }
    return -1;
}
int countOccurrence(LList* head, int target) {
    int count = 0;
    LList* current = head;
    while (current != NULL) {
        if (current->data == target) count++;
        current = current->next;
    }
    return count;
}
LList* sortList(LList* head) {
    if (head == NULL) return NULL;
    LList* current = head;
    LList* index = NULL;
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
LList* reverseList(LList* head) {
    LList* prev = NULL;
    LList* current = head;
    LList* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
int main() {
    LList* head = NULL;
    int choice,ch,data, position, target;
    while (1) {
        printf("\nMenu:\n");
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