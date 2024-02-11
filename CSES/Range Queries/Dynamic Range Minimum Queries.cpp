#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
const int maxn = 3e5 + 5;
 
int n, q;
int tree[4 * maxn], a[maxn];
 
void build(int node, int start, int end) {
  if (start == end) {
    tree[node] = a[start];
    return;
  }
  int mid = (start + end)/2;
  build(2 * node, start, mid);
  build(2 * node + 1, mid + 1, end);
  tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}
 
int query(int node, int start, int end, int l, int r) {
  if (start > r || end < l) return INT_MAX;
  if (l <= start && end <= r) return tree[node];
  int mid = (start + end)/2;
  int q1 = query(2 * node, start, mid, l, r);
  int q2 = query(2 * node + 1, mid + 1, end, l, r);
  return min(q1, q2);
}
 
void update(int node, int start, int end, int index, int value) {
  if (start == end) {
    a[start] = value;
    tree[node] = value;
    return;
  }
  int mid = (start + end)/2;
  if (index <= mid) update(2 * node, start, mid, index, value);
  else update(2 * node + 1, mid + 1, end, index, value);
  tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}
 
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
 
  cin >> n >> q;
  for (int i = 0; i < n; ++i) cin >> a[i];
  build(1, 0, n - 1);
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int ind, val;
      cin >> ind >> val;
      ind--;
      update(1, 0, n - 1, ind, val);
    }
    else {
      int l, r;
      cin >> l >> r;
      --l, --r;
      cout << query(1, 0, n - 1, l, r) << '\n';
    }
  }
  return 0;
}
