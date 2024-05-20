#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 3e5 + 9;

// Time complexity - O(1)
// Space complexity - O(n)
struct DSU {
  vector<int> par, rnk, sz;
  int c;
  DSU(int n) : par(n + 1), rnk(n + 1, 0), sz(n + 1, 1), c(n) {
    for (int i = 1; i <= n; ++i) {
      par[i] = i;
    }
  }
  int find(int i) {
    return (par[i] == i ? i : (par[i] = find(par[i])));
  }
  bool same(int i, int j) {
    return find(i) == find(j);
  }
  int get_size(int i) {
    return sz[find(i)];
  }
  int count() {
    return c;    //connected components
  }
  // Path compression
  // O(1)
  int merge(int i, int j) {
    if ((i = find(i)) == (j = find(j))) {
      return -1;
    }
    else {
      --c;
    }
    if (rnk[i] > rnk[j]) {
      swap(i, j);
    }
    par[i] = j;
    sz[j] += sz[i];
    if (rnk[i] == rnk[j]) {
      rnk[j]++;
    }
    return j;
  }
};

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int n, m;
  cin >> n >> m;
  DSU dsu(n + 1);
  int cnt = n, ans = 1;
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    if (!dsu.same(x, y)) {
      dsu.merge(x, y);
      ans = max(ans, dsu.sz[dsu.find(x)]);
      --cnt;
    }
    cout << cnt << ' ' << ans << '\n'; 
  }
  return 0;
}
