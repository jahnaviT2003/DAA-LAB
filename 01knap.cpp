#include <iostream>
#include <climits>
using namespace std;
int knapSack(int v[], int w[], int n, int W) {
   if (W < 0)
      return INT_MIN;
   if (n < 0 || W == 0)
      return 0;
   int in = v[n] + knapSack(v, w, n - 1, W - w[n]);
   int ex = knapSack(v, w, n - 1, W);
   return max (in, ex);
}
int main() {
   int n, W;
   cin >> n;
   int w[n], p[n];
   for (int i = 0; i < n; i++) {
      cin >> w[i];
      cin >> p[i];
   }
   cin >> W;
   cout << knapSack(w, p, n, W);
   return 0;
}