#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 2e5 + 5;

int n, q, timer = 0;
int a[maxn], tin[maxn], tout[maxn], euler[4 * maxn], tree[4 * maxn];
vector<int> g[maxn];

void euler_tour(int node, int par) {
  tin[node] = timer;
  euler[timer++] = a[node];
  for (auto& edges: g[node]) {
    if (edges != par) euler_tour(edges, node);
  }
  tout[node] = timer;
  euler[timer++] = -1 * a[node];
}

void build(int node, int start, int end) {
  if (start == end) {
    tree[node] = euler[start];
    return;
  }
  int mid = (start + end)/2;
  build(2 * node, start, mid);
  build(2 * node + 1, mid + 1, end);
  tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(int node, int start, int end, int l, int r) {
  if (start > r || end < l) return 0;
  if (l <= start && end <= r) return tree[node];
  int mid = (start + end)/2;
  int q1 = query(2 * node, start, mid, l, r);
  int q2 = query(2 * node + 1, mid + 1, end, l, r);
  return q1 + q2;
}

void update(int node, int start, int end, int index, int value) {
  if (start == end) {
    tree[node] = value;
    return;
  }
  int mid = (start + end)/2;
  if (index <= mid) update(2 * node, start, mid, index, value);
  else update(2 * node + 1, mid + 1, end, index, value);
  tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  cin >> n >> q;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  euler_tour(1, -1);
  build(1, 0, timer - 1);
  while (q--) {
    int x;
    cin >> x;
    if (x == 1) {
      int u, v;
      cin >> u >> v;
      update(1, 0, timer - 1, tin[u], v);
      update(1, 0, timer - 1, tout[u], -v);
    }
    else {
      int v;
      cin >> v;
      int ans = query(1, 0, timer - 1, 0, tin[v]);
      cout << ans << '\n';
    }
  }
  return 0;
}
