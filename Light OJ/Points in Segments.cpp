#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int tc;
  cin >> tc;
  for (int cs = 0; cs < tc; ++cs) {
    cout << "Case " << cs + 1 << ":\n";
    long long n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    while (q--) {
      long long x, y;
      cin >> x >> y;
      long long c = lower_bound(a.begin(), a.end(), x) - a.begin();
      long long d = upper_bound(a.begin(), a.end(), y) - a.begin();
      cout << d - c << '\n';
    }
  }
  return 0;
}
