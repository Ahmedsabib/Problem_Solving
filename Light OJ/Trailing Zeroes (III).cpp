#include <bits/stdc++.h>
using namespace std;
const long long limit = 1e18;
long long count_trailing_zeros(long long n) {
  long long cnt = 0;
  for (long long i = 5; i <= n; i *= 5) {
      cnt += n/i;
  }
  return cnt;
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int tc;
  cin >> tc;
  for (int cs = 0; cs < tc; ++cs) {
    cout << "Case " << cs + 1 << ": ";
    long long n;
    cin >> n;
    long long low = 1, high = limit, ans = -1;
    while (low <= high) {
      long long mid = low + (high - low)/2;
      long long cnt = count_trailing_zeros(mid);
      if (cnt > n) {
        high = mid - 1;
      }
      else if (n > cnt) {
        low = mid + 1;
      }
      else {
        ans = mid;
        high = mid - 1;
      }
    }
    if (ans == -1) {
      cout << "impossible\n";
    }
    else {
      cout << ans << '\n';
    }
  }
  return 0;
}
