#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_N = 2e5 + 5;
const int LOG = 31;

int a[MAX_N];
int m[MAX_N][LOG];
int bin_log[MAX_N];

int query(int L, int R) {
  int len = R - L + 1;
  int k = bin_log[len];
  return min(m[L][k], m[R - (1 << k) + 1][k]);
}

int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  int n, q;
  cin >> n >> q;
  bin_log[1] = 0;
  for (int i = 2; i <= n; ++i) {
    bin_log[i] = bin_log[i/2] + 1;
  }
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    m[i][0] = a[i];
  }
  for (int k = 1; k < LOG; ++k) {
    for (int i = 0; i + (1 << k) - 1 < n; ++i) {
      m[i][k] = min(m[i][k - 1], m[i + (1 << (k - 1))][k - 1]);
    }
  }
  while (q--) {
    int L, R;
    cin >> L >> R;
    --L, --R;
    cout << query(L, R) << '\n';
  }
  return 0;
}
