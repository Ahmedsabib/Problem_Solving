#include <bits/stdc++.h>
using namespace std;
long long n, m;
vector<long long> a;
bool good(long long x) {
  long long cur = 0, group = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] > x) {
      return false;
    }
    if (cur + a[i] > x) {
      group++;
      cur = 0;      
    }
    cur += a[i];
  }
  if (cur) {
    ++group;
  }
  return group <= m;
}
void test_case() {
  scanf("%lld %lld", &n, &m);
  a.resize(n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
  }
  long long low = 0, high = 1e18;
  while (low+1 < high) {
    long long mid = low + (high - low)/2;
    if (good(mid)) {
      high = mid;
    }
    else {
      low = mid;
    }
  }
  printf("%lld\n", high);
}
int main(int argc, char const *argv[]) {
  int t = 1;
  // scanf("%d", &t);
  while (t--) {
    test_case();
  }
  return 0;
}
