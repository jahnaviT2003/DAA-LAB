#include <iostream>
#include <string>

using namespace std;

int main()
{
  int arr[40];
  int pp=0;
    string pattern;
    string text;
    cout<<"Enter the pattern"<<endl;
    cin>>pattern;
    cout<<"Enter the Text"<<endl;
    cin>>text;
    int f1=0;
    if(pattern==text)
    {
      cout<<"yess"<<endl;
  }
    for(int i=0;i<text.length();i++)
    {
        int pattern_length=pattern.length();
        string r = text.substr(i, pattern_length);
        if(r==pattern)
        {
          f1=1;
          cout<<"String Found at iteration :"<<i<<endl;
          arr[pp]=i;
          pp=pp+1;
          
    }
        
    }
    if(f1==0)
    {
      cout<<"-1"<<endl;
  }
    int flag=0;
    int diff=arr[1]-arr[0];
    for(int i=0;i<pp-1;i++)
    {
      int diff_i=arr[i+1]-arr[i];
      cout<<"Diff_i : "<<diff_i<<endl;
      if(diff!=diff_i)
      {
        flag=1;
    }
  }
  if(flag==0)
  {
    cout<<"Arthemetic text"<<endl;
  }
  else
  {
    cout<<"Non Athematic text"<<endl;
  }

    return 0;
}