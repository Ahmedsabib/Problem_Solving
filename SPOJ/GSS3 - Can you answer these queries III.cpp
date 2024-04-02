#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 1e5 + 5;

struct data_list {
  int suf, pref, sum, seg;
};

int a[maxn];
data_list tree[4 * maxn];

data_list make_data(int val) {
  data_list res;
  res.suf = val;
  res.pref = val;
  res.sum = val;
  res.seg = val;
  return res;
}

data_list combine(data_list l, data_list r) {
  data_list res;
  res.pref = max(l.pref, l.sum + r.pref);
  res.suf = max(r.suf, r.sum + l.suf);
  res.sum = l.sum + r.sum;
  res.seg = max({l.seg, r.seg, l.suf + r.pref});
  return res;
}

void build(int node, int start, int end) {
  if (start == end) {
    tree[node] = make_data(a[start]);
    return;
  }
  int mid = (start + end)/2;
  build(2 * node, start, mid);
  build(2 * node + 1, mid + 1, end);
  tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
}

data_list query(int node, int start, int end, int l, int r) {
  if (end < l || start > r) return make_data(-1e9);
  if (l <= start && end <= r) return tree[node];
  int mid = (start + end)/2;
  data_list q1 = query(2 * node, start, mid, l, r);
  data_list q2 = query(2 * node + 1, mid + 1, end, l, r);
  return combine(q1, q2);
}

void update(int node, int start, int end, int ind, int val) {
  if (start == end) {
    a[start] = val;
    tree[node] = make_data(val);
    return;
  }
  int mid = (start + end)/2;
  if (ind <= mid) update(2 * node, start, mid, ind, val);
  else update(2 * node + 1, mid + 1, end, ind, val);
  tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int n, q;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  build(1, 0, n - 1);
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    if (x == 0) {
      int ind, val;
      cin >> ind >> val;
      update(1, 0, n - 1, ind - 1, val);
    }
    else {
      int l, r;
      cin >> l >> r;
      --l; --r;
      cout << query(1, 0, n - 1, l, r).seg << '\n';
    }
  }
  return 0;
}
