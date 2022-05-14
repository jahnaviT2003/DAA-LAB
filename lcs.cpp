#include <iostream>
#include <cstring>
using namespace std;

void LCS(char *S1, char *S2, int m, int n) {
  int LCS_table[m + 1][n + 1];

  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == 0 || j == 0)
        LCS_table[i][j] = 0;
      else if (S1[i - 1] == S2[j - 1])
        LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
      else
        LCS_table[i][j] = max(LCS_table[i - 1][j], LCS_table[i][j - 1]);
    }
  }

  int index = LCS_table[m][n];
  char LCS[index + 1];
  LCS[index] = '\0';

  int i = m, j = n;
  while (i > 0 && j > 0) {
    if (S1[i - 1] == S2[j]) {
      LCS[index - 1] = S1[i - 1];
      i--;
      j--;
      index--;
    }

    else if (LCS_table[i - 1][j] >= LCS_table[i][j - 1])
      i--;
    else
      j--;
  }
  cout << LCS;
}

int main() {
  char S1[100];
  char S2[100];
  cin>>S1>>S2;
  int x = strlen(S1);
  int y = strlen(S2);

  LCS(S1, S2, x, y);
}
