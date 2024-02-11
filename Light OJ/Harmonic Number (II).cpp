#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int tc;
  cin >> tc;
  for (int cs = 0; cs < tc; ++cs) {
    cout << "Case " << cs + 1 << ": \n";
    long long n;
    cin >> n;
    long long ans = 0;
    for (long long i = 1; i <= sqrt(n); ++i) {
      ans += n/i;
    }
    ans *= 2;
    ans -= ((int)sqrt(n) * (int)sqrt(n));
    cout << ans << '\n';
  }
  return 0;
}
