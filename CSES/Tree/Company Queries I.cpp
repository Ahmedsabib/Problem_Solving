#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 2e5 + 5;
const int l = 18;

int n, q;
int upper_level[maxn][l];

int jump(int x, int d) {
  for (int i = 0; i < l; ++i) {
    if ((d >> i) & 1) x = upper_level[x][i];
  }
  return x? x : -1;
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  cin >> n >> q;
  for (int i = 2; i <= n; ++i) {
    int x;
    cin >> x;
    upper_level[i][0] = x;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < l; ++j) {
      upper_level[i][j] = upper_level[upper_level[i][j - 1]][j - 1];
    }
  }
  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << jump(a, b) << '\n';
  }
  return 0;
}
