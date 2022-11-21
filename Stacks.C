#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};
struct node *top = NULL;

// Insert function
void push();
// Remove function
void pop();
// Size of function
int sizeOfStack();
// Display stack function
void display();
// Position of an element
void positionOf();
// Element found at position
void elementAt();

int main(void) {
  int choice;
  int n;
  do {
    printf("\nChoose from following:\n1 - Push an element\n2 - Pop an element\n3 - Display stack\n4 - Size of stack\n5 - Position of an element\n6 - Element at position\n7 - Exit\n");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      push();
      break;
    case 2:
      pop();
      break;
    case 3:
      display();
      break;
    case 4: {
      int size = sizeOfStack();
      printf("\nSize of stack: %d\n", size);
    } break;
    case 5:
      positionOf();
      break;
    case 6:
      elementAt();
      break;
    case 7:
      printf("\nExited!\n");
      break;
    default:
      printf("\nInvalid Choice!\n");
    }
  } while (choice != 7);
  return 0;
}

void push() {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  if (temp == NULL) {
    printf("\nStack Overflow.\n");
    return;
  }
  printf("\nEnter data: ");
  scanf("%d", &temp->data);
  temp->next = NULL;
  if (top == NULL) {
    top = temp;
  } else {
    temp->next = top;
    top = temp;
  }
  printf("\nElement inserted successfully.\n");
}

void pop() {
  if (top == NULL) {
    printf("\nStack Underflow.\n");
    return;
  }
  top = top->next;
  printf("\nElement deleted successfully.\n");
}

int sizeOfStack() {
  int size = 0;
  if (top == NULL) {
    return size;
  }
  struct node *currNode = top;
  while (currNode != NULL) {
    size++;
    currNode = currNode->next;
  }
  return size;
}

void display() {
  if (top == NULL) {
    printf("\nStack:\n[ ]\n");
    return;
  } else {
    struct node *currNode = top;
    printf("\nStack:\n[ ");
    while (currNode != NULL) {
      printf("%d ", currNode->data);
      currNode = currNode->next;
    }
    printf("]\n");
  }
}

void positionOf() {
  if (top == NULL) {
    printf("\nStack is empty.\n");
    return;
  }
  int element;
  printf("\nEnter the element to get position: ");
  scanf("%d", &element);
  struct node *currNode = top;
  int position = 1;
  while (currNode != NULL) {
    if (element == currNode->data) {
      printf("\n%d found at position %d\n", element, position);
      return;
    }
    position++;
    currNode = currNode->next;
  }
  if (currNode == NULL) {
    printf("\n%d is not in the stack.\n", element);
  }
}

void elementAt() {
  if (top == NULL) {
    printf("\nStack is empty.\n");
    return;
  }
  int position;
  printf("\nEnter position to get element: ");
  scanf("%d", &position);
  if (position > sizeOfStack() || position <= 0) {
    printf("\nSpecified position doesn't exist.\n");
    return;
  }
  int i = position;
  struct node *currNode = top;
  while (currNode != NULL && --i) {
    currNode = currNode->next;
  }
  printf("\n%d found at position %d\n", currNode->data, position);
}
