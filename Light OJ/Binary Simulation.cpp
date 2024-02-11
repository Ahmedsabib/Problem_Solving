#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

bool tree[4 * maxn];

void update(int node, int start, int end, int l, int r) {
  if (start == l && end == r) {
    tree[node] = !tree[node];
    return;
  }
  int mid = (start + end)/2;
  if (r <= mid) {
    update(2 * node, start, mid, l, r);
  }
  else if (mid < l) {
    update(2 * node + 1, mid + 1, end, l, r);
  }
  else {
    update(2 * node, start, mid, l, mid);
    update(2 * node + 1, mid + 1, end, mid + 1, r);
  }
}

int query(int node, int start, int end, int index) {
  if (start == index && end == index) {
    return tree[node];
  }
  if (tree[node]) {
    tree[2 * node] = !tree[2 * node];
    tree[2 * node + 1] = !tree[2 * node + 1];
    tree[node] = 0;
  }
  int mid = (start + end)/2;
  if (index <= mid) {
    return query(node * 2, start, mid, index);
  }
  else {
    return query(2 * node + 1, mid + 1, end, index);
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case " << cases + 1 << ":\n";
    memset(tree, 0, sizeof(tree));
    string s;
    cin >> s;
    int n = (int)s.size();
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') {
        update(1, 1, n, i + 1, i + 1);
      }
    }
    int q;
    cin >> q;
    while (q--) {
      char x;
      cin >> x;
      if (x == 'I') {
        int l, r;
        cin >> l >> r;
        update(1, 1, n, l, r);
      }
      else if (x == 'Q') {
        int l;
        cin >> l;
        cout << query(1, 1, n, l) << '\n';
      }
    }
  }
  return 0;
}
