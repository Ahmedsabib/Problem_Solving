#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 2e5 + 5;
const int inf = 1e18;

pair<int, int> tree[4 * maxn];
int a[maxn];

void build(int node, int start, int end) {
  if (start == end) {
    tree[node].first = a[start];
    tree[node].second = a[start];
    return;
  }
  int mid = (start + end)/2;
  build(2 * node, start, mid);
  build(2 * node + 1, mid + 1, end);
  tree[node].first = max(tree[2 * node].first, tree[2 * node + 1].first);
  tree[node].second = min(tree[2 * node].second, tree[2 * node + 1].second);
}

pair<int, int> query(int node, int start, int end, int l, int r) {
  if (start > r || end < l) {
    return {0, inf};
  }
  if (l <= start && end <= r) {
    return tree[node];
  }
  int mid = (start + end)/2;
  pair<int, int> q1 = query(2 * node, start, mid, l, r);
  pair<int, int> q2 = query(2 * node + 1, mid + 1, end, l, r);
  return {max(q1.first, q2.first), min(q1.second, q2.second)};
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case " << cases + 1 << ": ";
    int n, d;
    cin >> n >> d;
    for (int i = 0; i < n; ++i) cin >> a[i];
    build(1, 0, n - 1);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int start = i, end = min(i + d - 1, n);
      pair<int, int> pq = query(1, 0, n - 1, start, end);
      ans = max(ans, pq.first - pq.second);
    }
    cout << ans << '\n';
    for (int i = 0; i < 4 * maxn; ++i) {
      tree[i].first = 0;
      tree[i].second = 0;
    }
  }
  return 0;
}
