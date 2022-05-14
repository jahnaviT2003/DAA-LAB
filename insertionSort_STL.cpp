#include <iostream>
#include <vector>
using namespace std;

void insertion_sort(std::vector<int>& arr_A)
{
    for(std::size_t j = 1; j < arr_A.size(); j++)
    {
      int key = arr_A[j];
      int i = j-1;

      while(i >= 0 && arr_A[i] > key)
      {
         arr_A[i+1] = arr_A[i];
         i--;
      }
      arr_A[i+1] = key;
    }
     
}

 void print(std::vector<int>& arr_A) 
{
    cout<<"Sorted Array : "<<endl;
    for(unsigned i = 0; i < arr_A.size(); i++)
    {
         std::cout << arr_A[i] << " ";
    }
    std::cout << "\n";
}

int main()
{
    int n,a,x;
    vector<int> array_A;

    cout<<"Enter the size of the Array : ";
    cin>>n;
    cout<<"Enter the elements of the Array : "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        array_A.push_back(x);
    }
    insertion_sort(array_A);
    print(array_A);
}
