#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 1e5 + 5;

int tree[4 * maxn][3], lazy[4 * maxn];

void lazy_propagation(int node, int start, int end) {
  if (start != end) {
    lazy[node * 2] = (lazy[node] + lazy[node * 2])%3;
    lazy[node * 2 + 1] = (lazy[node] + lazy[node * 2 + 1])%3;
  }
  if (lazy[node] == 1) {
    tree[node][2] = tree[node][1];
    tree[node][1] = tree[node][0];
    tree[node][0] = (end - start) + 1 - tree[node][1] - tree[node][2];
  }
  if (lazy[node] == 2) {
    tree[node][1] = tree[node][2];
    tree[node][2] = tree[node][0];
    tree[node][0] = (end - start) + 1 - tree[node][1] - tree[node][2];
  }
  lazy[node] = 0;
}

void build(int node, int start, int end) {
  tree[node][0] = (end - start) + 1;
  tree[node][1] = 0;
  tree[node][2] = 0;
  lazy[node] = 0;
  if (start == end) {
    tree[node][0] = 1;
    return;
  }
  int mid = (start + end)/2;
  build(2 * node, start, mid);
  build(2 * node + 1, mid + 1, end);
}

void update(int node, int start, int end, int l, int r) {
  if (lazy[node] != 0) lazy_propagation(node, start, end);
  if (start > end || start > r || end < l) return;
  if (start >= l && end <= r) {
    if (start != end) {
      lazy[node * 2] = (lazy[node * 2] + 1)%3;
      lazy[node * 2 + 1] = (lazy[node * 2 + 1] + 1)%3;
    }
    tree[node][2] = tree[node][1];
    tree[node][1] = tree[node][0];
    tree[node][0] = (end - start) + 1 - tree[node][1] - tree[node][2];
    return;
  }
  int mid = (start + end)/2;
  update(node * 2, start, mid, l, r);
  update(node * 2 + 1, mid + 1, end, l, r);
  for (int i = 0; i < 3; ++i) {
    tree[node][i] = tree[node * 2][i] + tree[node * 2 + 1][i];
  }
}

int query(int node, int start, int end, int l, int r) {
  if (lazy[node] != 0) lazy_propagation(node, start, end);
  if (start > end || start > r || end < l) return 0;
  if (start >= l && end <= r) return tree[node][0];
  int mid = (start + end)/2;
  int p1 = query(node * 2, start, mid, l, r);
  int p2 = query(node * 2 + 1, mid + 1, end, l, r);
  for (int i = 0; i < 3; ++i) {
    tree[node][i] = tree[node * 2][i] + tree[node * 2 + 1][i];
  }
  return (p1 + p2);
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case " << cases + 1 << ":\n";
    int n, m;
    cin >> n >> m;
    build(1, 0, n - 1);
    for (int i = 0; i < m; ++i) {
      int type, l, r;
      cin >> type >> l >> r;
      if (type == 0) update(1, 0, n - 1, l, r);
      else cout << query(1, 0, n - 1, l, r) << '\n';
    }
  }
  return 0;
}
