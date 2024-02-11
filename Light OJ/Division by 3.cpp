#include <bits/stdc++.h>

using namespace std;

long long check(long long n) {
  if (n == 0) {
    return 0;
  }
  long long cnt = 0;
  if (n%3 == 0) {
    cnt = n/3;
  }
  else {
    cnt = (n/3) + 1;
  }
  return n - cnt;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case " << cases + 1 << ": ";
    long long n, m;
    cin >> n >> m;
    cout << check(m) - check(n - 1) << '\n';
  }
  return 0;
}
