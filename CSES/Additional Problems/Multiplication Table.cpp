#include <bits/stdc++.h>
using namespace std;
long long n;
bool good(long long x) {
  long long res = 0;
  for (long long i = 1; i <= n; ++i) {
    res += min(n, x/i);
  }
  return res < (n*n+1)/2;
}
void test_case() {
  scanf("%lld", &n);
  long long low = 0, high = n*n;
  while (low + 1 < high) {
    long long mid = low + (high - low)/2;
    if (good(mid)) {
      low = mid;
    }
    else {
      high = mid;
    }
  }
  printf("%lld\n", low + 1);
}
int main(int argc, char const *argv[]) {
  int t = 1;
  // scanf("%d", &t);
  while (t--) {
    test_case();
  }
  return 0;
}
