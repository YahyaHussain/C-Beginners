#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};
struct node *head = NULL;

// Insert functions
void insertAtHead();
void insertAtPosition();
void insertAtEnd();
// Remove function
void removeNode();
// Size of function
int sizeOfList();
// Display list function
void display();

int main(void) {
  int choice = 0;
  int n;
  do  {
    printf("\nChoose from following:\n1 - Insert node\n2 - Remove node\n3 - Display list\n4 - Size of list\n5 - Exit\n");
    scanf("%d", &choice);
    switch (choice) {
      case 1: {
        int choose;
        do  {
          printf("\nChoose from following:\n1 - Insert at beginning\n2 - Insert at specified position\n3 - Insert at end\n");
          scanf("%d", &choose);
          switch (choose) {
            case 1:
              insertAtHead();
              printf("\nElement inserted successfully.\n");
            break;
            case 2:
              insertAtPosition();
              printf("\nElement inserted successfully.\n");
            break;
            case 3:
              insertAtEnd();
              printf("\nElement inserted successfully.\n");
            break;
            default:
              printf("\nInvalid choice!\n");
          }
        }  while (choose > 3);
      } break;
      case 2:
        removeNode();
        printf("\nElement deleted successfully.\n");
      break;
      case 3:
        display();
      break;
      case 4:  {
        int size = sizeOfList();
        printf("\nSize of list: %d\n", size);
      } break;
      case 5:
        printf("\nExited!\n");
        break;
      default:
        printf("\nInvalid Choice!\n");
    }
  }  while (choice != 5);
  return 0;
}

void insertAtHead() {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  printf("\nEnter data: ");
  scanf("%d", &temp->data);
  temp->next = NULL;
  if (head == NULL) {
    head = temp;
  } else {
    temp->next = head;
    head = temp;
  }
}

void insertAtPosition() {
  int position;
  printf("\nEnter position to insert: ");
  scanf("%d", &position);
  if (position == 1 || head == NULL) {
    insertAtHead();
    return;
  } else {
    struct node *currNode = head;
    for (int i = 2; i < position && currNode != NULL; i++) {
      currNode = currNode->next;
    }
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter data: ");
    scanf("%d", &temp->data);
    temp->next = currNode->next;
    currNode->next = temp;
  }
}

void insertAtEnd() {
  if (head == NULL)  {
    insertAtHead();
    return;
  }
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  printf("\nEnter data: ");
  scanf("%d", &temp->data);
  temp->next = NULL;
  struct node *currNode = head;
  while (currNode->next != NULL) {
    currNode = currNode->next;
  }
  currNode->next = temp;
}

void removeNode()  {
  int position;
  printf("\nËnter the postion to remove: ");
  scanf("%d", &position);
  if (position > sizeOfList())  {
    printf("\nInvalid position!\n");
    return;
  }
  else if (position == 1 && head->next == NULL)  {
    head = NULL;
  }
  else  {
    if (position == 1)  {
      head = head->next;
      return;
    }
    struct node *currNode = head;
    for (int i = 2; i < position; i++)  {
      currNode = currNode->next;
    }
    currNode->next = currNode->next->next;
  }
}

int sizeOfList() {
  int size = 0;
  if (head == NULL) {
    return size;
  }
  struct node *currNode = head;
  while (currNode != NULL) {
    size++;
    currNode = currNode->next;
  }
  return size;
}

void display() {
  if (head == NULL) {
    printf("\nList:\n[ ]\n");
    return;
  } else {
    struct node *currNode = head;
    printf("\nList:\n[ ");
    while (currNode != NULL) {
      printf("%d ", currNode->data);
      currNode = currNode->next;
    }
    printf("]\n");
  }
}
