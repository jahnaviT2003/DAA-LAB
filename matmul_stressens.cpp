// Program to implement matrix multiplication using divide and conquer

#include<iostream>

using std::cout;
using std::cin;

int** matrix_multiplication(int A[][4],int B[][4], int n)
{
 int C[4][4],C11[4][4], C12[4][4], C21[4][4], C22[4][4],A11[4][4],B11[4][4], A12[4][4],B12[4][4],A21[4][4],B21[4][4],A22[4][4],B22[4][4];

 int i=1,j=1;

 while(i<=n/2)
 {
     while(j<=n/2)
     {
         A11[i][j]=A[i][j];
         B11[i][j]=B[i][j];
         A21[i][j]=A[i+(n/2)][j];
         B21[i][j]=B[i+(n/2)][j];
         A12[i][j]=A[i][j+(n/2)];
         B12[i][j]=B[i][j+(n/2)];
         A22[i][j]=A[i+(n/2)][j+(n/2)];
         B22[i][j]=B[i+(n/2)][j+(n/2)];

         j++;
    }

 i++;
 j=1;
}

 if(n<=2)
 {
   for(i=1;i<=n/2;i++)
   {

     for(j=1;j<=n/2;j++)
     {


  C[i][j]= A11[i][j]*B11[i][j]+A12[i][j]*B21[i][j];
  C[i+(n/2)][j]= A11[i][j]*B12[i][j]+A12[i][j]*B22[i][j];
  C[i][j+(n/2)]= A21[i][j]*B11[i][j]+A22[i][j]*B21[i][j];
  C[i+(n/2)][j+(n/2)]= A21[i][j]*B12[i][j]+A22[i][j]*B22[i][j];

 }
   }
 }
 else{

 C11[4][4]= matrix_multiplication(A11,B11,n/2)+matrix_multiplication(A12,B21,n/2);
 C12[4][4]= matrix_multiplication(A11,B12,n/2)+matrix_multiplication(A12,B22,n/2);
 C21[4][4]= matrix_multiplication(A21,B11,n/2)+matrix_multiplication(A22,B21,n/2);
 C22[4][4]= matrix_multiplication(A21,B12,n/2)+matrix_multiplication(A22,B22,n/2);

 }


 return C;
}


int main()
{
 int n,i,j;
 int** result;
 
 int A[4][4],B[4][4];
 cout<<"Enter the elements for"<<n<<"x"<<n<<" A matrix n";
 for(i=1;i<=4;i++)
 {
    cout<<"n";
    for(j=1;j<=n;j++)

      cin>>A[i][j];
 }

  cout<<"Enter the elements for"<<n<<"x"<<n<<" B matrix n";
 for(i=1;i<=n;i++)
 {
    cout<<"n";
    for(j=1;j<=n;j++)

      cin>>B[i][j];
 }

 result=matrix_multiplication(A,B,4);
 cout<<"n The resultant matrix C is :";
 for(i=0;i<n;i++)
 {
    cout<<"n";
    for(j=0;j<n;j++)

      cin>>result[i][j];
 }
 return 0;
}
