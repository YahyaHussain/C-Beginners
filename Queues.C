#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;

// Insert function
void enQueue();
// Remove function
void deQueue();
// Size of function
int sizeOfQueue();
// Display queue function
void display();
// Position of an element
void positionOf();
// Element found at position
void elementAt();

int main(void) {
  int choice;
  int n;
  do {
    printf("\nChoose from following:\n1 - Insert into queue\n2 - Remove from queue\n3 - Display queue\n4 - Size of queue\n5 - Position of an element\n6 - Element at position\n7 - Exit\n");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      enQueue();
      break;
    case 2:
      deQueue();
      break;
    case 3:
      display();
      break;
    case 4: {
      int size = sizeOfQueue();
      printf("\nSize of queue: %d\n", size);
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

void enQueue() {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  if (temp == NULL) {
    printf("\nMemory not allocated.\n");
    return;
  }
  printf("\nEnter data: ");
  scanf("%d", &temp->data);
  temp->next = NULL;
  if (front == NULL && rear == NULL) {
    rear = temp;
    front = rear;
    return;
  }
  rear->next = temp;
  rear = temp;
  printf("\nElement inserted successfully.\n");
}

void deQueue() {
  if (front == NULL && rear == NULL) {
    printf("\nInvalid deletion.\n");
    return;
  }
  if (front->next == NULL) {
    front = NULL;
    rear = NULL;
  } else {
    front = front->next;
  }
  printf("\nElement deleted successfully.\n");
}

int sizeOfQueue() {
  int size = 0;
  if (front == NULL && rear == NULL) {
    return size;
  }
  struct node *currNode = front;
  while (currNode != NULL) {
    size++;
    currNode = currNode->next;
  }
  return size;
}

void display() {
  if (front == NULL && rear == NULL) {
    printf("\nQueue:\n[ ]\n");
    return;
  } else {
    struct node *currNode = front;
    printf("\nQueue:\n[ ");
    while (currNode != NULL) {
      printf("%d ", currNode->data);
      currNode = currNode->next;
    }
    printf("]\n");
  }
}

void positionOf() {
  if (front == NULL && rear == NULL) {
    printf("\nQueue is empty.\n");
    return;
  }
  int element;
  printf("\nEnter the element to get position: ");
  scanf("%d", &element);
  struct node *currNode = front;
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
    printf("\n%d is not in the Queue.\n", element);
  }
}

void elementAt() {
  if (front == NULL && rear == NULL) {
    printf("\nQueue is empty.\n");
    return;
  }
  int position;
  printf("\nEnter position to get element: ");
  scanf("%d", &position);
  if (position > sizeOfQueue() || position <= 0) {
    printf("\nSpecified position doesn't exist.\n");
    return;
  }
  int i = position;
  struct node *currNode = front;
  while (currNode != NULL && --i) {
    currNode = currNode->next;
  }
  printf("\n%d found at position %d\n", currNode->data, position);
}
