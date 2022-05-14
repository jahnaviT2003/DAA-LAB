#include <iostream>  
using namespace std;  
int main()  
{  
int matrix_1[10][10],matrix_2[10][10],multiplication_matrix[10][10],r,c,i,j,k;    
cout << "\nNAME : JAHNAVI THONDEPU \n";
cout << "REGISTER NUMBER : 20BAI1150 \n";
cout << "\n";
cout<<"Enter the number of rows : ";    
cin>>r;    
cout<<"Enter the number of columns : ";    
cin>>c;    
cout<<"Enter the first matrix elements : \n";    
for(i=0;i<r;i++)    
{    
    for(j=0;j<c;j++)    
    {    
        cin>>matrix_1[i][j];  
    }    
}    
cout<<"enter the second matrix elements : \n";    
for(i=0;i<r;i++)    
{    
    for(j=0;j<c;j++)    
    {    
        cin>>matrix_2[i][j];    
    }    
}    
cout<<"MULTIPLICATION MATRIX : \n";    
for(i=0;i<r;i++)    
{    
    for(j=0;j<c;j++)    
    {    
        multiplication_matrix[i][j]=0;    
        for(k=0;k<c;k++)    
        {    
            multiplication_matrix[i][j]+=matrix_1[i][k]*matrix_2[k][j];    
        }    
    }    
}    
 
for(i=0;i<r;i++)    
{    
    for(j=0;j<c;j++)    
    {    
        cout<<multiplication_matrix[i][j]<<" ";    
    }    
    cout<<"\n";    
}    
return 0;  
}  