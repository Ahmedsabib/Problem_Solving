#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 3e5 + 5;

int n, m;
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
    // a[start] = value;
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

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case " << cases + 1 << ":\n";
    memset(tree, 0, sizeof(tree));
    memset(a, 0, sizeof(a));
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      update(1, 0, n - 1 + m, i, 1);
    }
    int en = n;
    for (int i = 0; i < m; ++i) {
      char x;
      cin >> x;
      if (x == 'c') {
        int k;
        cin >> k;
        int low = 0, high = en - 1, ans = -1;
        while (low <= high) {
          int mid = low + (high - low)/2;
          int v = query(1, 0, n - 1 + m, 0, mid);
          if (v >= k) {
            if (v == k) ans = mid;
            high = mid - 1;
          }
          else low = mid + 1;
        }
        if (ans == -1) cout << "none\n";
        else {
          cout << a[ans] << '\n';
          update(1, 0, n - 1 + m, ans, 0);
          a[ans] = 0;
        }
      }
      else {
        int p;
        cin >> p;
        a[en] = p;
        update(1, 0, n - 1 + m, en, 1);
        ++en;
      }
    }
  }
}
