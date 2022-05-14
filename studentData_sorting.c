#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

static void string_insertion_sort (const char ** arr, int n)
{
    int i,j;
    for (j = 1; j < n; j++) {
	const char * p;
	p = arr[j];
	for (i = j - 1; i >= 0; i--) {
	    if (strcasecmp (arr[i], p) < 0) 
        {
		    break;
	    }
	    arr[i + 1] = arr[i];
	}
	arr[i + 1] = p;
    }
}

void print_result_regno (int arr[], int n)
{
    printf("\nSorted Sequence of Registration Numbers : \n");
    for (int i=0; i<n; i++)
    {
        printf("Student %d Register Number : %d \n",i+1, arr[i]);
    }
    printf("\n");
}
static void print_result_name (const char ** arr, int n)
{
    printf("Sorted Sequence of Names : \n");
    for (int i = 0; i < n; i++) 
    {
        printf("Student %d Name : %s \n",i+1, arr[i]);
    }
    printf("\n");
}
void print_result_marks (int arr[], int n)
{
    printf("Sorted Sequence of Marks : \n");
    for (int i=0; i<n; i++)
    {
        printf("Student %d Marks : %d \n",i+1, arr[i]);
    }
    printf("\n");
}
int main ()
{
    int arr_size;

    printf("Enter the size of the Array : ");
    scanf("%d",&arr_size);
    const char *name[arr_size];
    int reg_no[arr_size], marks[arr_size];
    size_t malloc_size = 100;

    for (int i = 0; i < arr_size; i++) 
    {
        name[i] = malloc(malloc_size * sizeof(char)); 
        printf("Enter Student %d Register Number : ", i+1);
        scanf("%d",&reg_no[i]);
        printf("Enter Student %d Name : ", i+1);
        scanf("%99s", name[i]); 
        printf("Enter Student %d Marks : ", i+1);
        scanf("%d",&marks[i]);

    }

    insertion_sort (reg_no, arr_size);
    string_insertion_sort (name, arr_size);
    insertion_sort (marks, arr_size);

    print_result_regno (reg_no, arr_size);
    print_result_name (name, arr_size);
    print_result_marks (marks, arr_size);
    return 0;
}