#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
const int maxn = 4e5 + 5;
 
int n, q, bit[maxn];
vector<int> res;
 
void update(int ind, int value) {
  while (ind < maxn) {
    bit[ind] += value;
    ind += (ind & (-ind));
  }
}
 
void add(int x, int value) {
  int ind = upper_bound(res.begin(), res.end(), x) - res.begin();
  update(ind, value);
}
 
int sum(int ind) {
  int ans = 0;
  while (ind > 0) {
    ans += bit[ind];
    ind -= ind & (-ind);
  }
  return ans;
}
 
int query(int x) {
  int ind = upper_bound(res.begin(), res.end(), x) - res.begin();
  return sum(ind);
}
 
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
 
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  res = a;
  vector<array<int, 3>> cur;
  for (int i = 0; i < q; ++i) {
    char x;
    int u, v;
    cin >> x >> u >> v;
    cur.push_back({x == '?', u, v});
    if (x == '!') res.push_back(v);
  }
  sort(res.begin(), res.end());
  res.erase(unique(res.begin(), res.end()), res.end());
  for (int i = 0; i < n; ++i) add(a[i], 1);
  for (auto& x: cur) {
    x[1]--;
    if (x[0] == 0) {
      add(a[x[1]], -1);
      a[x[1]] = x[2];
      add(a[x[1]], 1);
    }
    else {
      cout << query(x[2]) - query(x[1]) << '\n';
    }
  }
  return 0;
}
