#include <stdio.h>
#include <stdlib.h>

int main(void)	{
	int n, i;
	printf("Enter no.of elements: ");
	scanf("%d", &n);
	
	int *arr = (int *)malloc(n * sizeof(int));
	
	printf("Enter elements into array:\n");
	for (i = 0; i < n; i++)	{
		scanf("%d", &arr[i]);
	}
	
	printf("Array:\n");
	for (i = 0; i < n; i++)	{
		printf("%d ", arr[i]);
	}
	
	int insertNo;
	printf("\nEnter no.of elements to add to array: ");
	scanf("%d", &insertNo);
	
	arr = (int *)realloc(arr, (n + insertNo) * sizeof(int));
	int *insertElements = (int *)malloc(insertNo * sizeof(int *));
	
	printf("Enter elements to add:\n");
	for (i = 0; i < insertNo; i++)	{
		scanf("%d", &insertElements[i]);
	}
	
	int *insertAtIndex = (int *)malloc(insertNo * sizeof(int *));
	
	printf("Enter index at which you want to add the elements:\n");
	for (i = 0; i < insertNo; i++)	{
		scanf("%d", &insertAtIndex[i]);
	}
	
	for (i = 0; i < insertNo; i++)	{
		printf("\nInsert %d at index %d", insertElements[i], insertAtIndex[i]);
	}
	
	for (i = 0; i < insertNo; i++)	{
		int j;
		for (j = 0; j < (n + insertNo); j++)	{
			if (insertAtIndex[i] == j)	{
				int k;
				for (k = (n + i + 1); k >= insertAtIndex[i]; k--)	{
					arr[k] = arr[k - 1];
				}
				arr[insertAtIndex[i]] = insertElements[i];
			}
		}
	}
	
	printf("\nAfter inserting:\n");
	for (i = 0; i < (n + insertNo); i++)	{
		printf("%d ", arr[i]);
	}
	
	return 0;
}
