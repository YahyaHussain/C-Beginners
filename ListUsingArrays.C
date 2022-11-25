#include <stdio.h>
#include <stdlib.h>

int *arr;
int size;
int *head = NULL;

void insertElements();
void removeElements();
void display();
int sizeOfList();
void indexOf();
void elementAt();
void reverseList();

int main(void) {
  int choice;
  do {
    printf("\nChoose from following:\n1 - Insert\n2 - Remove\n3 - Display list\n4 - Size of list\n5 - Index of an element\n6 - Element at index\n7 - Reverse List\n8 - Exit\n");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      insertElements();
      break;
    case 2:
      removeElements();
      break;
    case 3:
      display();
      break;
    case 4: {
      printf("\nSize of list: %d\n", sizeOfList());
    } break;
    case 5:
      indexOf();
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

void insertElements() {
  if (head == NULL) {
    printf("\nEnter no.of elements: ");
    scanf("%d", &size);

    arr = (int *)malloc(size * sizeof(int));

    printf("Enter elements into list:\n");
    for (int i = 0; i < sizeOfList(); i++) {
      scanf("%d", &arr[i]);
    }
    head = &arr[0];
    printf("\nElement inserted successfully.\n");
    return;
  }

  int choice;
  do {
    printf("\n1 - Insert by overwriting\n2 - Allocate new memory\n3 - exit\n");
    scanf("%d", &choice);
    switch (choice) {
    case 1: {
      int insertNo;
      printf("\nEnter no.of elements to add to list: ");
      scanf("%d", &insertNo);

      if (insertNo > sizeOfList()) {
        printf("\nInvalid input.\nMax insertions: %d\n", sizeOfList());
        break;
      }

      int *insertElements = (int *)malloc(insertNo * sizeof(int *));

      printf("\nEnter elements to add to list:\n");
      for (int i = 0; i < insertNo; i++) {
        scanf("%d", &insertElements[i]);
      }

      int *insertAtIndex = (int *)malloc(insertNo * sizeof(int *));

      printf("\nEnter index at which you want to add the elements into the list:\n");
      for (int i = 0; i < insertNo; i++) {
        scanf("%d", &insertAtIndex[i]);

        if (insertAtIndex[i] >= sizeOfList()) {
          printf("\nInvalid index.\nMax index: %d.\n", (sizeOfList() - 1));
          --i;
          continue;
        }
      }

      for (int i = 0; i < insertNo; i++) {
        for (int j = 0; j < sizeOfList(); j++) {
          if (j == insertAtIndex[i]) {
            arr[j] = insertElements[i];
          }
        }
      }
      free(insertElements);
      free(insertAtIndex);
      head = &arr[0];
      printf("\nElement inserted successfully.\n");
      return;
    } break;

    case 2: {
      int insertNo;
      printf("\nEnter no.of elements to add to list: ");
      scanf("%d", &insertNo);
      size += insertNo;

      int *insertElements = (int *)malloc(insertNo * sizeof(int));
      arr = (int *)realloc(arr, size * sizeof(int));

      printf("\nEnter elements to add to list:\n");
      for (int i = 0; i < insertNo; i++) {
        scanf("%d", &insertElements[i]);
      }

      int *insertAtIndex = (int *)malloc(insertNo * sizeof(int));

      printf("\nEnter index at which you want to add the elements into the list:\n");
      for (int i = 0; i < insertNo; i++) {
        scanf("%d", &insertAtIndex[i]);

        if (insertAtIndex[i] >= sizeOfList()) {
          printf("\nInvalid index.\nMax index: %d.\n", (sizeOfList() - 1));
          --i;
          continue;
        }
      }

      for (int i = 0; i < insertNo; i++) {
        for (int j = 0; j < sizeOfList(); j++) {
          if (insertAtIndex[i] == j) {
            for (int k = (sizeOfList() + i + 1); k >= insertAtIndex[i]; k--) {
              arr[k] = arr[k - 1];
            }
            arr[insertAtIndex[i]] = insertElements[i];
          }
        }
      }
      insertElements = NULL;
      insertAtIndex = NULL;
      head = &arr[0];
      printf("\nElement inserted successfully.\n");
      return;
    } break;

    case 3:
      printf("\nËxited!\n");
      break;

    default:
      printf("\nInvalid Choice!\n");
    }
  } while (choice != 3);
}

void removeElements() {
  if (head == NULL) {
    printf("\nList is empty.\n");
    return;
  }
  int removeNo;
  printf("\nEnter no.of elements to remove from list: ");
  scanf("%d", &removeNo);

  if (removeNo == 0) {
    return;
  } else if (removeNo < 0 || removeNo > sizeOfList()) {
    printf("\nInvalid input.\n");
    return;
  }

  int choice;
  do {
    printf("\n1 - Remove by index\n2 - Remove by element\n3 - Exit\n");
    scanf("%d", &choice);
    switch (choice) {
    case 1: {
      int *removeFromIndex = (int *)malloc(removeNo * sizeof(int *));

      printf("\nEnter index to remove elements from the list:\n");
      for (int i = 0; i < removeNo; i++) {
        scanf("%d", &removeFromIndex[i]);

        if (removeFromIndex[i] >= sizeOfList()) {
          printf("\nInvalid index.\nMax index: %d.\n", (sizeOfList() - 1));
          i--;
          continue;
        }
      }

      for (int i = 0; i < removeNo; i++) {
        removeFromIndex[i] -= i;
        for (int j = 0; j < sizeOfList(); j++) {
          if (j == removeFromIndex[i]) {
            for (int k = removeFromIndex[i]; k < sizeOfList() - 1; k++) {
              arr[k] = arr[k + 1];
            }
            size--;
          }
        }
      }
      arr = (int *)realloc(arr, size * sizeof(int));
      head = &arr[0];
      free(removeFromIndex);
      printf("\nElement deleted successfully.\n");
      return;
    } break;

    case 2: {
      int *removeElements = (int *)malloc(removeNo * sizeof(int *));
      printf("\nEnter elements to be removed from list:\n");
      for (int i = 0; i < removeNo; i++) {
        scanf("%d", &removeElements[i]);
      }

      for (int i = 0; i < removeNo; i++) {
        for (int j = 0; j < sizeOfList(); j++) {
          if (removeElements[i] == arr[j]) {
            for (int k = j; k < sizeOfList() - 1; k++) {
              arr[k] = arr[k + 1];
            }
            size--;
            break;
          }
        }
      }
      head = &arr[0];
      free(removeElements);
      printf("\nElement deleted successfully.\n");
      return;
    } break;

    case 3:
      printf("\nExited!\n");
      break;
    default:
      printf("\nInvalid Choice!\n");
    }
  } while (choice != 3);
}

void display() {
  if (head == NULL) {
    printf("\nList:\n[ ]\n");
    return;
  }
  printf("\nList:\n[ ");
  for (int i = 0; i < sizeOfList(); i++) {
    printf("%d ", arr[i]);
  }
  printf("]\n");
}

int sizeOfList() { return size; }

void indexOf() {
  if (head == NULL) {
    printf("\nList is empty.\n");
    return;
  }
  int element;
  printf("\nEnter element to get index: ");
  scanf("%d", &element);
  for (int i = 0; i < sizeOfList(); i++) {
    if (element == arr[i]) {
      printf("\n%d found at index: %d\n", element, i);
      return;
    }
  }
  printf("\n%d not in list\n", element);
}

void elementAt() {
  if (head == NULL) {
    printf("\nList is empty.\n");
    return;
  }
  int index;
  printf("\nEnter index to get number: \n");
  scanf("%d", &index);
  if (index >= sizeOfList() || index < 0) {
    printf("\nSpecified index doesn\'t exist.\n");
    return;
  }
  printf("\nElement at index %d: %d\n", index, arr[index]);
}

void reverseList() {
  if (head == NULL) {
    printf("\nReverse list:\n[ ]\n");
    return;
  }
  printf("\nReverse list:\n[ ");
  for (int i = sizeOfList() - 1; i >= 0; i--) {
    printf("%d ", arr[i]);
  }
  printf("]\n");
  return;
}
