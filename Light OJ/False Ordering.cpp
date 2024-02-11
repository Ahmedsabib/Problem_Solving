#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<long long, long long> x, pair<long long, long long> y) {
  if (x.first != y.first) {
    return x.first < y.first;
  }
  return x.second > y.second;
}
// Time Complextity O(sqrt(n))
long long divisors(long long n) {
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
  return (int)p.size();
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int tc;
  cin >> tc;
  for (int cs = 0; cs < tc; ++cs) {
    cout << "Case " << cs + 1 << ": ";
    long long n;
    cin >> n;
    vector<pair<long long, long long>> a;
    for (int i = 1; i <= 1000; ++i) {
      a.push_back({divisors(i), i});
    }
    sort(a.begin(), a.end(), cmp);
    cout << a[n - 1].second << '\n';  
  }
  return 0;
}
