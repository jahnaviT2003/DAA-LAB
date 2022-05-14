#include<iostream>
using namespace std;
class bin
{
    int n,k;
public:
    void read_inputs()
    {
        cin>>n;
        cin>>k;
    }
    int compute();
    void display_result()
    {
        cout<<compute();
    }
    int mim(int x, int y)
    {
        if(x > y)
            return y;
        else 
            return x;
    }
};
int bin::compute()
{
    int i,j;
    int p[20][20];
    for(i=0;i<=n;i++)
      {
          for(j=0;j<=mim(i,k);j++)
        {
            if(j==0||j==i)
            {
                p[i][j]=1;
            }
            else
                p[i][j]=p[i-1][j-1]+p[i-1][j];  
        }
}
    return p[n][k];
}
int main()
{
    bin Binomial;
    Binomial.read_inputs(); 
    Binomial.compute(); 
    Binomial.display_result(); 
    return 0;
}