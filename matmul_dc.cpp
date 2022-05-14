#include<iostream>
#include<vector>
using namespace std;

int scadds=0, scmuls=0;
void read_matrix(vector<vector<int> >&mat,int n)
{
    int i,j,ele;
    for(i=0;i<n;i++)
    {
        vector<int> row;
        for(j=0;j<n;j++)
        {
            cin>>ele;
            row.push_back(ele);
        }
        mat.push_back(row);
    }
}
void print_matrix(vector<vector<int> > mul_matrix)
{
    int n = mul_matrix.size();
    cout << "\nMULTIPLICATION MATRIX : " << endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<mul_matrix[i][j]<<"\t";
        cout<<"\n";
    }
}
 
void square_matrix_multiply_recursive(vector<vector<int> > &mat1,vector<vector<int> > &mat2, vector<vector<int> > &mat3, int top1, int left1, int top2, int left2, int size)
{       
    if (size==1)
    {
        if (mat3[top1][left2])
         scadds++;
        mat3[top1][left2] += mat1[top1][left1] * mat2[top2][left2];
        scmuls++;
    }
    else
    {
        square_matrix_multiply_recursive(mat1,mat2,mat3,top1,left1,top2,left2,size/2);
        square_matrix_multiply_recursive(mat1,mat2,mat3,top1,left1+size/2,top2+size/2,left2,size/2);


        square_matrix_multiply_recursive(mat1,mat2,mat3,top1,left1,top2,left2+size/2,size/2);
        square_matrix_multiply_recursive(mat1,mat2,mat3,top1,left1+size/2,top2+size/2,left2+size/2,size/2);


        square_matrix_multiply_recursive(mat1,mat2,mat3,top1+size/2,left1,top2,left2,size/2);
        square_matrix_multiply_recursive(mat1,mat2,mat3,top1+size/2,left1+size/2,top2+size/2,left2,size/2);


        square_matrix_multiply_recursive(mat1,mat2,mat3,top1+size/2,left1,top2,left2+size/2,size/2);
        square_matrix_multiply_recursive(mat1,mat2,mat3,top1+size/2,left1+size/2,top2+size/2,left2+size/2,size/2);

    }
}
int main()
{
    vector<vector<int> > matrix_1,matrix_2;
    int i,j,n;
    cout << "\nNAME : JAHNAVI THONDEPU \n";
    cout << "REGISTER NUMBER : 20BAI1150 \n";
    cout << "\n";
    cout << "Enter the number of rows and columns of the matrix : " << endl;
    cin>>n;
    cout << "Enter Matrix-1 : " << endl;
    read_matrix(matrix_1,n);
    cout << "Enter Matrix-2 : " << endl;
    read_matrix(matrix_2,n);

    vector< vector<int> > matrix_3(n, vector<int>(n,0));    

    square_matrix_multiply_recursive(matrix_1,matrix_2,matrix_3,0,0,0,0,n);
    
    print_matrix(matrix_3);

    return 0;
}