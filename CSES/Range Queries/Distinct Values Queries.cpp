#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
const int maxn = 2e5 + 5;
 
int a[maxn], tree[4 * maxn];
 
int query(int node, int start, int end, int l, int r) {
  if (start > r || end < l) {     // start...end l....r
    return 0;
  }
  if (l <= start && end <= r) {   // l..start end...r
    return tree[node];
  }
  // start.. l end.... r or l... start r... end
  int mid = (start + end)/2;
  int q1 = query(2 * node, start, mid, l, r);
  int q2 = query(2 * node + 1, mid + 1, end, l, r);
  return q1 + q2;
}
 
void update(int node, int start, int end, int index, int value) {
  if (start == end) {
    a[start] = value;
    tree[node] = value;
    return;
  }
  int mid = (start + end)/2;
  if (index <= mid) {
    update(2 * node, start, mid, index, value);
  }
  else {
    update(2 * node + 1, mid + 1, end, index, value);
  }
  tree[node] = tree[2 * node] + tree[2 * node + 1];
}
 
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
 
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<vector<pair<int, int>>> queries(n);
  for (int i = 0; i < q; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    queries[u].push_back({v, i});
  }
  map<int, int> last_index;
  vector<int> ans(q, -1);
  for (int i = n - 1; i >= 0; --i) {
    int x = a[i];
    if (last_index.count(x) > 0) update(1, 0, n - 1, last_index[x], 0);
    last_index[x] = i;
    update(1, 0, n - 1, i, 1);
    for (auto& it: queries[i]) {
      ans[it.second] = query(1, 0, n - 1, 0, it.first);
    }
  }
  for (auto& x: ans) cout << x << ' ';
  cout << '\n';
  return 0;
}
