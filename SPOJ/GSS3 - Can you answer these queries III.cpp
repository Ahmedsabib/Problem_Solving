#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = (int)1e5 + 5;

struct node {
  int suf_sum, pref_sum, tot_sum, max_sum;
};

node a[maxn], tree[4 * maxn];

node combine(node x, node y) {
  node cur;
  cur.max_sum = max({x.max_sum, y.max_sum, x.suf_sum + y.pref_sum});
  cur.pref_sum = max({x.tot_sum + y.pref_sum, x.pref_sum});
  cur.suf_sum = max({y.tot_sum + x.suf_sum, y.suf_sum});
  cur.tot_sum = x.tot_sum + y.tot_sum;
  return cur;
}

void build(int nodee, int start, int end) {
  if (start == end) {
    tree[nodee] = a[start];
    return;
  }
  int mid = (start + end)/2;
  build(2 * nodee, start, mid);
  build(2 * nodee + 1, mid + 1, end);
  tree[nodee] = combine(tree[2 * nodee], tree[2 * nodee + 1]);
}

node query(int nodee, int start, int end, int l, int r) {
  if (l <= start && end <= r) {
    return tree[nodee];
  }
  int mid = (start + end)/2;
  if (r <= mid) return query(2 * nodee, start, mid, l, r);
  if (mid < l) return query(2 * nodee + 1, mid + 1, end, l, r);
  return combine(query(2 * nodee, start, mid, l, r), query(2 * nodee + 1, mid + 1, end, l, r));
}

void update(int nodee, int start, int end, int index, node value) {
  if (start == end) {
    // a[start] = value;
    tree[nodee] = value;
    return;
  }
  int mid = (start + end)/2;
  if (index <= mid) {
    update(2 * nodee, start, mid, index, value);
  }
  else {
    update(2 * nodee + 1, mid + 1, end, index, value);
  }
  tree[nodee] = combine(tree[2 * nodee], tree[2 * nodee + 1]);
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    a[i].max_sum = x;
    a[i].pref_sum = x;
    a[i].suf_sum = x;
    a[i].tot_sum = x;
  }
  build(1, 0, n - 1);
  int q;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    if (x == 0) {
      int ind, val;
      cin >> ind >> val;
      node nod;
      nod.max_sum = val;
      nod.pref_sum = val;
      nod.suf_sum = val;
      nod.tot_sum = val;
      update(1, 0, n - 1, ind - 1, nod);
      a[ind - 1] = nod;
    }
    else {
      int l, r;
      cin >> l >> r;
      --l; --r;
      node ans_nod = query(1, 0, n - 1, l, r);
      cout << ans_nod.max_sum << '\n';
    }
  }
  return 0;
}
