#include <bits/stdc++.h>
using namespace std;
// Time Complextity O(sqrt(n))
vector<long long> divisors(long long n) {
  vector<long long> p;
  for (int i = 1; i <= sqrt(n); ++i) {
    if (n%i == 0) {
      if (n/i == i) {
        p.push_back(i);
        continue;
      }
      else {
        p.push_back(n/i);
        p.push_back(i);
      }
    }
  }
  return p;
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int tc;
  cin >> tc;
  for (int cs = 0; cs < tc; ++cs) {
    cout << "Case " << cs + 1 << ": ";
    long long p, l;
    cin >> p >> l;
    long long q = p - l;
    vector<long long> div = divisors(q);
    sort(div.begin(), div.end());
    vector<long long> ans;
    for (int i = 0; i < (int)div.size(); ++i) {
      if (div[i] <= l) {
        continue;
      }
      ans.push_back(div[i]);
    }
    if ((int)ans.size() == 0) {
      cout << "impossible\n";
    }
    else {
      for (int i = 0; i < (int)ans.size(); ++i) {
        cout << ans[i] << ' ';
      }
      cout << '\n';
    }
  }
  return 0;
}
