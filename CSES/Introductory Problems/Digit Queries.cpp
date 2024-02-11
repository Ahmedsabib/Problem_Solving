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

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    long long k;
    scanf("%lld", &k);
    long long n = 1, sum = 0;
    do {
      sum = sum + 9 * n * binpow(10, n - 1);
      ++n;
    } while (k >= sum);
    --n;
    long long away = (sum - k)/n;
    long long remainder = (sum - k)%n;
    long long number = (binpow(10, n) - 1) - away;
    string result = to_string(number);
    printf("%c\n", result[(int)result.size() - 1 - remainder]);
  }
  return 0;
}
