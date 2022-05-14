#include <iostream>
#include<stdlib.h>
#include <stack>
using namespace std;
struct Min_Stack
{
    stack<int> s;
    int min_Element;
    
    void get_Min()
    {
        if (s.empty())
            cout << "Stack is empty\n";
        else
            cout <<"Minimum Element in the stack is: "<< min_Element << "\n";
    }
    void pop()
    {
        if (s.empty())
        {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Top Most Element Removed: ";
        int x = s.top();
        s.pop();
        if (x < min_Element)
        {
            cout << min_Element << "\n";
            min_Element = 2*min_Element - x;
        }

        else
            cout << x << "\n";
    }
    void push(int ele)
    {
        if (s.empty())
        {
            min_Element = ele;
            s.push(ele);
            return;
        }
        else if (ele < min_Element)
        {
            s.push(2*ele - min_Element);
            min_Element = ele;
        }
        else
           s.push(ele);
    }
};

int main()
{
    int n;
    cin>>n;
    Min_Stack s;
    for(int i =0; i<n; i++){
        int ele;
        cin>>ele;
        s.push(ele);
    }
    s.get_Min();
    return 0;
}
