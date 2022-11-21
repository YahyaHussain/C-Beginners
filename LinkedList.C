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
// Position of an element
void positionOf();
// Element found at position
void elementAt();
// Reverse List
void reverseList();

int main(void) {
  int choice;
  int n;
  do {
    printf("\nChoose from following:\n1 - Insert node\n2 - Remove node\n3 - "
           "Display list\n4 - Size of list\n5 - Position of an element\n6 - "
           "Element at position\n7 - Reverse List\n8 - Exit\n");
    scanf("%d", &choice);
    switch (choice) {
    case 1: {
      int choose;
      do {
        printf("\nChoose from following:\n1 - Insert at beginning\n2 - Insert "
               "at specified position\n3 - Insert at end\n");
        scanf("%d", &choose);
        switch (choose) {
        case 1:
          insertAtHead();
          break;
        case 2:
          insertAtPosition();
          break;
        case 3:
          insertAtEnd();
          break;
        default:
          printf("\nInvalid choice!\n");
        }
      } while (choose > 3);
    } break;
    case 2:
      removeNode();
      break;
    case 3:
      display();
      break;
    case 4: {
      int size = sizeOfList();
      printf("\nSize of list: %d\n", size);
    } break;
    case 5:
      positionOf();
      break;
    case 6:
      elementAt();
      break;
    case 7:
      reverseList();
      break;
    case 8:
      printf("\nExited!\n");
      break;
    default:
      printf("\nInvalid Choice!\n");
    }
  } while (choice != 8);
  return 0;
}

void insertAtHead() {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  if (temp == NULL) {
    printf("\nMemory not allocated.\n");
    return;
  }
  printf("\nEnter data: ");
  scanf("%d", &temp->data);
  temp->next = NULL;
  if (head == NULL) {
    head = temp;
  } else {
    temp->next = head;
    head = temp;
  }
  printf("\nElement inserted successfully.\n");
}

void insertAtPosition() {
  int position;
  printf("\nEnter position to insert: ");
  scanf("%d", &position);
  if ((position > sizeOfList() + 1) || (position <= 0)) {
    printf("\nInvalid positon.\n");
    return;
  } else if (position == 1 || head == NULL) {
    insertAtHead();
    return;
  } else {
    struct node *currNode = head;
    for (int i = 2; i < position && currNode != NULL; i++) {
      currNode = currNode->next;
    }
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
      printf("\nMemory not allocated.\n");
      return;
    }
    printf("\nEnter data: ");
    scanf("%d", &temp->data);
    temp->next = currNode->next;
    currNode->next = temp;
    printf("\nElement inserted successfully.\n");
  }
}

void insertAtEnd() {
  if (head == NULL) {
    insertAtHead();
    return;
  }
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  if (temp == NULL) {
    printf("\nMemory not allocated.\n");
    return;
  }
  printf("\nEnter data: ");
  scanf("%d", &temp->data);
  temp->next = NULL;
  struct node *currNode = head;
  while (currNode->next != NULL) {
    currNode = currNode->next;
  }
  currNode->next = temp;
  printf("\nElement inserted successfully.\n");
}

void removeNode() {
  if (head == NULL) {
    printf("\nList is empty.\n");
    return;
  }
  if (head->next == NULL) {
    head = NULL;
    printf("\nElement deleted successfully.\n");
    return;
  }
  int position;
  printf("\nËnter the postion to remove: ");
  scanf("%d", &position);
  if (position > sizeOfList() || position <= 0) {
    printf("\nInvalid position!\n");
    return;
  } else {
    if (position == 1) {
      head = head->next;
      printf("\nElement deleted successfully.\n");
      return;
    }
    struct node *currNode = head;
    for (int i = 2; i < position; i++) {
      currNode = currNode->next;
    }
    currNode->next = currNode->next->next;
    printf("\nElement deleted successfully.\n");
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

void positionOf() {
  if (head == NULL) {
    printf("\nList is empty.\n");
    return;
  }
  int element;
  printf("\nEnter the element to get position: ");
  scanf("%d", &element);
  struct node *currNode = head;
  int position = 1;
  while (currNode != NULL) {
    if (element == currNode->data) {
      printf("\n%d found at position %d\n", element, position);
      return;
    }
    currNode = currNode->next;
    position++;
  }

  if (currNode == NULL) {
    printf("\n%d is not in the list.\n", element);
  }
}

void elementAt() {
  if (head == NULL) {
    printf("\nList is empty.\n");
    return;
  }
  int position;
  printf("\nEnter position to get element: ");
  scanf("%d", &position);
  if (position > sizeOfList() || position <= 0) {
    printf("\nSpecified position doesn't exist.\n");
    return;
  }
  int i = position;
  struct node *currNode = head;
  while (currNode != NULL && --i) {
    currNode = currNode->next;
  }
  printf("\n%d found at position %d\n", currNode->data, position);
}

void reverseList() {
  if (head == NULL) {
    printf("\nReverse List:\n[ ]\n");
    return;
  }
  struct node *currNode = head;
  struct node *next = NULL;
  struct node *prev = NULL;
  while (currNode != NULL) {
    next = currNode->next;
    currNode->next = prev;
    prev = currNode;
    currNode = next;
  }
  head = prev;

  currNode = head;
  printf("\nReverse list:\n[ ");
  while (currNode != NULL) {
    printf("%d ", currNode->data);
    currNode = currNode->next;
  }
  printf("]\n");
}
