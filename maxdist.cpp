#include <iostream>
#include <algorithm>
using namespace std;

int Min_arr(int arr[], int low, int high)
{
    int i,min;
    min = arr[low];
    for(i=low; i<=high; i++)
    {
        if(arr[i]<min)
        {
            min = a[i];
        }
    }
    return min;
}
int Max_arr(int arr[], int low, int high)
{
    int i,max;
    max = arr[low];
    for(i=low; i<=high; i++)
    {
        if(arr[i]>max)
        {
            max = a[i];
        }
    }
    return max;
}
int divide_and_conquer(int arr[], int low, int high)
{
    if(low>=high)
        return 0;

    int mid = (low+high)/2;
    int left_partition = divide_and_conquer(arr,low,mid);
    int right_partition = divide_and_conquer(arr,mid+1,high);
    int left = Min_arr(arr,low,mid); 
    int right = Max_arr(arr,mid+1,high);
    return max(max(left_partition, right_partition), (right - left));
}

int main() 
{
    int arr_size;
    cin>>arr_size;
    int array[arr_size];

    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    
    int max_dist = divide_and_conquer(array, 0, arr_size-1);
    cout <<max_dist<<endl;
    return 0;
}