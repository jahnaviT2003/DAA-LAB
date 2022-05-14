#include<bits/stdc++.h>
using namespace std;

string CommonPrefixUtil(string str1, string str2)
{
    string result;
    int n1 = str1.length(), n2 = str2.length();
    
    for (int i=0, j=0; i<=n1-1&&j<=n2-1; i++,j++)
    {
        if (str1[i] != str2[j])
            break;
        result.push_back(str1[i]);
    }

    return (result);
}
string commonPrefix (string arr[], int n)
{
    string prefix =  arr[0];

    for (int i=1; i<=n-1; i++)
        prefix = CommonPrefixUtil(prefix, arr[i]);

    return (prefix);
}
int main()
{
    int p;
    printf("Enter the number of strings: ");
    scanf("%d", &p);
    string arr[p];
    printf("\n");
    printf("Enter the strings:");
    for(int x = 0; x<p;x++)
        cin>>arr[x];
    int n = sizeof(arr) / sizeof(arr[0]);

    string ans = commonPrefix(arr, n);

    if (ans.length())
        printf("The longest common prefix = %s",ans.c_str());
    else
        printf("-1");
}