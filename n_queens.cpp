#include<iostream>
using namespace std;
#define N 4
void printBoard(int board[N][N]) {
   for (int i = N-1; i >= 0; i--) {
      for (int j = 0; j < N; j++)
         cout << board[i][j] << " ";
         cout << endl;
   }
}
bool isValid(int board[N][N], int row, int col) {
   for (int i = 0; i < col; i++) 
      if (board[row][i])
         return false;
   for (int i=row, j=col; i>=0 && j>=0; i--, j--)
      if (board[i][j]) 
         return false;
   for (int i=row, j=col; j>=0 && i<N; i++, j--)
      if (board[i][j]) 
         return false;
   return true;
}
bool solveNQueen(int board[N][N], int col) {
   if (col >= N) 
      return true;
   for (int i = 0; i < N; i++) { 
      if (isValid(board, i, col) ) {
         board[i][col] = 1;
         if ( solveNQueen(board, col + 1)) 
            return true;
         board[i][col] = 0; 
      }
   }
   return false; 
}
bool checkSolution() {
   int board[N][N];
   for(int i = 0; i<N; i++)
   for(int j = 0; j<N; j++)
   board[i][j] = 0; 
   if ( solveNQueen(board, 0) == false ) { 
      cout << "Solution does not exist";
      return false;
   }
   printBoard(board);
   return true;
}
int main() {
   checkSolution();
}


#include <iostream>
using namespace std;
#define pdd pair<double, double>

void lineFromPoints(pdd P, pdd Q, int s, int v)
{
    int ans;
	double a = Q.second - P.second;
	double b = P.first - Q.first;
	double c = a * (P.first) + b * (P.second);
	ans = a*s + b*v-(c); 
	if(ans==0) {
	    cout<<"yes";
	}
	else 
	    cout<<"no";
}
int main()
{
    int n1, n2, n3, n4, n5, n6;
    cin>>n1>>n2>>n3>>n4>>n5>>n6;
	pdd P = make_pair(n1, n2);
	pdd Q = make_pair(n3, n4);
	lineFromPoints(P, Q, n5, n6 );
	return 0;
}




#include <iostream>
using namespace std;

int main()
{
    int size; 
    cin>>size;
    int arr[size][size];
    for (int i = 0; i < size; i++)                 
    {
        for (int j = 0; j < size; j++)
        {
            cin>>arr[i][j];
        }   
    }
    int x=0, y=0;
    int flag = 0;
    for(int i = 0; i<size; i++) {
            
            if(arr[x][y] == 1) {
                flag++;
                break;
            }
            x++;
            y++;
        }
    if(flag == 0) {
        cout<<"yes\n";
    }
    else
        cout<<"no\n";

    
    for(int i = 0; i < size; i++) {
        int count = 0;
        for(int j = 0; j < size; j++) {
            if(arr[i][j] == 1) {
                count++;
            }
        }
        cout<<count<<" ";
    }
}




