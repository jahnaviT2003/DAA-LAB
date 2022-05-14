#include <iostream>
#include <cstring>
using namespace std;
 
void Array(char* pat, int M, int* lps);

void KMP(char* pat, char* txt, int n1, int n2)
{
    int z=0;
    int arr[3];
    int M = strlen(pat);
    int N = strlen(txt);
    int lps[M];
    Array(pat, M, lps);
 
    int i = 0; 
    int j = 0; 
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
        if (j == M) {
            arr[z] = i-j;
            z++;
            j = lps[j - 1];
        }
        else if (i < N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    int s, s1;
    s = arr[0];
    s1 = arr[2];
    
    if(s == 0 && s1 == (n1 - n2)) {
        cout<<"\nYES"<<endl;
    } else {
        cout<<"\nNO"<<endl;
    }
    
}
void Array(char* pat, int M, int* lps)
{
    int len = 0;
 
    lps[0] = 0; 
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else 
        {
            if (len != 0) {
                len = lps[len - 1];
            }
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
 
int main()
{
    int n1, n2;
    cout<<"Enter the size of T: \n";
    cin>>n1;
    cout<<"Enter the size of P: \n";
    cin>>n2;
    char T[n1], P[n2];
    cout<<"Enter Text T: \n";
    cin>>T;
    cout<<"Enter pattern P: \n";
    cin>>P;
    KMP(P,T,n1,n2);
    return 0;
}