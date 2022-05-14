#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int arr[], int n)
{
    int i,j,key;
    for (j = 1; j < n; j++) {
        key = arr[j];
        i = j- 1;

        while (i >= 0 && arr[i] > key) {
        	 arr[i + 1] = arr[i];
            i = i - 1;
        }
        arr[i + 1] = key;
    }
}

void print_result(int arr[], int n)
{
    printf("Sorted Array : ");
	printf("{");

    for (int i = 0; i < n-1; i++)
	{
		printf("%d, ",arr[i]);
	}
	int l;
  	l=arr[n-1];
  	printf("%d}",l);
}

int main()
{
    int array_A[100],n;
    printf("Enter the size of an array : ");
    scanf("%d",&n);
    
    printf("Enter the elements of the array : ");
    for(int i=0;i<n;i++)
    {
    	scanf("%d",&array_A[i]);
	}
    
    insertion_sort(array_A, n);
    print_result(array_A, n);
}