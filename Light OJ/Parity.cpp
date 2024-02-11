#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case " << cases + 1 << ": ";
    long long n;
    cin >> n;
    long long x = __builtin_popcount(n);
    cout << (x&1? "odd\n" : "even\n");
  }
  return 0;
}
