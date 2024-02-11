#include <bits/stdc++.h>
using namespace std;
long long find(long long n, long long k) {
  if (n == 1) {
    return 1;
  }
  else if (k <= (n + 1)/2) {
    if (2 * k > n) {
      return (2 * k)%n;
    }
    else {
      return 2 * k;
    }
  }
  long long x = find(n/2, k - (n + 1)/2);
  if (n%2 == 1) {
    return 2 * x + 1;
  }
  else {
    return 2 * x - 1;
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int tc;
  cin >> tc;
  for (int cs = 0; cs < tc; ++cs) {
    long long n, k;
    cin >> n >> k;
    cout << find(n, k) << '\n';
  }
  return 0;
}
