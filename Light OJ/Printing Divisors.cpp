#include <bits/stdc++.h>
using namespace std;
const int limit = 1e5 + 7;
vector<long long> lp(limit + 1);
vector<long long> primes;
void linear_sieve() {
  for (int i = 2; i <= limit; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      primes.push_back(i);
    }
    for (int j = 0; j < (int)primes.size() && primes[j] <= lp[i] && i * primes[j] <= limit; ++j) {
      lp[i * primes[j]] = primes[j];
    }
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  linear_sieve();
  int tc;
  cin >> tc;
  for (int cs = 0; cs < tc; ++cs) {
    cout << "Case " << cs + 1 << ": \n";
    long long n;
    cin >> n;
    int len = (int)primes.size();
    vector<pair<long long, long long>> factor;
    for (int i = 0; i < len && primes[i] * primes[i] <= n; ++i) {
      if (n%primes[i]) {
        continue;
      }
      long long cnt = 0;
      while (n%primes[i] == 0) {
        ++cnt;
        n /= primes[i];
      }
      factor.push_back({primes[i], cnt});
    }
    if (n > 1) {
      factor.push_back({n, 1});
    }
    sort(factor.begin(), factor.end());
    vector<long long> ans;
    ans.push_back(1);
    for (auto& x: factor) {
      long long value = x.first;
      long long ind = x.second;
      long long init = 1;
      vector<long long> temp;
      int ans_len = (int)ans.size();
      for (int i = 0; i <= ind; ++i) {
        if (i&1) {
          for (int j = ans_len - 1; j >= 0; --j) {
            temp.push_back(ans[j] * init);
          }
        }
        else {
          for (int j = 0; j < ans_len; ++j) {
            temp.push_back(ans[j] * init);
          }
        }
        init *= value;
      }
      ans = temp;
    }
    for (int i = 0; i < (int)ans.size(); ++i) {
      cout << ans[i] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
