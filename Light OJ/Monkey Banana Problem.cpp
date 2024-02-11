#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case " << cases + 1 << ": ";
    int n;
    cin >> n;
    int grid[2 * n - 1][n];
    int max_banana[2 * n - 1][n];
    memset(grid, 0, sizeof(grid));
    memset(max_banana, 0, sizeof(max_banana));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= i; ++j) {
        cin >> grid[i][j];
      }
    }
    int d = 1;
    for (int i = n; i < 2 * n - 1; ++i) {
      for (int j = d; j < n; ++j) {
        cin >> grid[i][j];
      }
      ++d;
    }
    max_banana[0][0] = grid[0][0];
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j <= i; ++j) {
        if (j == 0) {
          max_banana[i][j] = max_banana[i - 1][j] + grid[i][j];
        }
        else {
          max_banana[i][j] = max(max_banana[i - 1][j - 1], max_banana[i - 1][j]) + grid[i][j];
        }
      }
    }
    d = 1;
    for (int i = n; i < 2 * n - 1; ++i) {
      for (int j = d; j < n; ++j) {
        max_banana[i][j] = max(max_banana[i - 1][j - 1], max_banana[i - 1][j]) + grid[i][j];
      }
      ++d;
    }
    cout << max_banana[2 * n - 2][n - 1] << '\n';
  }
  return 0;
}
