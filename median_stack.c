#include <bits/stdc++.h>
using namespace std;


stack<int> sortStack2(stack<int> input)
{
    stack<int> tmpStack;
 
    while (!input.empty())
    {
        int tmp = input.top();
        input.pop();
        
        while (!tmpStack.empty() &&
                tmpStack.top() < tmp)
        {
            input.push(tmpStack.top());
            tmpStack.pop();
        }
        tmpStack.push(tmp);
    }
    return tmpStack;
}
void sortStack1(int arr[], int n)
{
    stack<int> input;
    for (int i=0; i<n; i++)
       input.push(arr[i]);
    stack<int> tmpStack = sortStack2(input);
    
    for (int i=0; i<n; i++)
    {
        arr[i] = tmpStack.top();
        tmpStack.pop();
    }
}
void median(int arr[], int size)
{
    if(size%2 == 1){
        int v;
        v=(size+1)/2;
        cout<<"\nMedian is: "<<arr[v-1];
    }
    else{
        float a, b, sum;
        a=arr[(size)/2];
        b=arr[(size/2)-1];
        sum=(a+b)/2;
        cout<<"\nMedian is: %0.2f"<< sum;
    }
}
int main()
{
    int p;
    printf("Enter number of elements: ");
    scanf("%d", &p);
    int arr[p];
    printf("Input %d values: \n", p);                                               
    for(int i=0; i<p; i++)                                                                                                                                          
        scanf("%d", &arr[i]);
    int n = sizeof(arr)/sizeof(arr[0]);
    
    sortStack1(arr, n);
    printf("Stack after sorting in ascending order: \n");
    for (int i=0; i<n; i++)
       printf("%d ", arr[i]);
       
    median(arr, p);
}