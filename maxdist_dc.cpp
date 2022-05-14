#include<iostream>
using namespace std;
 

    int max_diff = 0;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if(j > i)
            {
                int dist=arr[j]-arr[i];
                if(dist>max_diff)
                {
                    max_diff=dist;
                }
            }
        }
    }
}
 
int main()
{
    int arr_size;
    cin>>arr_size;
    int array[arr_size];
    for(int i=0; i<arr_size; i++)
    {
        cin>>array[i];
    }
    int max_dist = max_distance(array, arr_size);
    cout << max_dist;
    return 0;
}