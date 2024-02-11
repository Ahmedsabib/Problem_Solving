#include <bits/stdc++.h>

using namespace std;

int query(int i, int bit[], int n) {
  int ans = 0;
  while (i > 0) {
    ans += bit[i];
    i -= i & (-i);
  }
  return ans;
}

void update(int i, int val, int bit[], int n) {
  while (i <= n) {
    bit[i] += val;
    i += i & (-i);
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    int n, q;
    cin >> n >> q;
    int bit[n + 10] = {0};
    while (q--) {
      int l, r, val;
      cin >> l >> r >> val;
      ++l;
      ++r;
      update(l, val, bit, n); // A[L..] +val
      update(r + 1, -val, bit, n); // A[R + 1..] -val
      // A[L..R] +val
    }
    int qq;
    cin >> qq;
    while(qq--) {
      int x;
      cin >> x;
      ++x;
      cout << query(x, bit, n) << '\n';
    }
  }
  return 0;
}
