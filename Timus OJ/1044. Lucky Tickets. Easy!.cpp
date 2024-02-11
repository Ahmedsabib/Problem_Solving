#include <bits/stdc++.h>
using namespace std;
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b&1) {
      res = res * a;
    }
    a = a * a;
    b >>= 1;
  }
  return res;
}
long long digit_sum(long long n) {
  long long sum = 0;
  while (n > 0) {
    int res = n%10;
    sum += res;
    n /= 10;
  }
  return sum;
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  long long n;
  cin >> n;
  vector<long long> cnt(36);
  for (int i = 0; i < binpow(10, n/2); ++i) {
    long long val = digit_sum(i);
    cnt[val]++;
  }
  long long ans = 0;
  for (int i = 0; i < binpow(10, n/2); ++i) {
    long long val = digit_sum(i);
    ans += cnt[val];
  }
  cout << ans << '\n';
  return 0;
}
