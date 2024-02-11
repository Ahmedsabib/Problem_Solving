#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1e6 + 5;
int su[maxn];
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  for (int i = 2; i <= maxn; ++i) {
    if (su[i]) {
      continue;
    }
    for (int j = i + i; j <= maxn; j += i) {
      su[j] = 1;
    }
  }
  int tc;
  cin >> tc;
  for (int cs = 0; cs < tc; ++cs) {
    long long n;
    cin >> n;
    long long ans = 0;
    while (n--) {
      int t;
      cin >> t;
      for (int i = t + 1; ; ++i) {
        if (!su[i]) {
          ans += i;
          break;
        }
      }
    }
    cout << "Case " << cs + 1 << ": " << ans << " Xukha\n";
  }
  return 0;
}
