#include <bits/stdc++.h>
using namespace std;
vector<long long> answer;
bool check(long long x, vector<long long> a, long long n, long long k) {
  vector<long long> b;
  long long res = 0, campsite = 0;
  for (int i = 0; i < n; ++i) {
    res += a[i];
    if (res > x) {
      b.push_back(res - a[i]);
      ++campsite;
      if (campsite > k) {
        return false;
      }
      res = a[i];
    }
  }
  b.push_back(res);
  answer = b;
  return true;
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int tc;
  cin >> tc;
  for (int cs = 0; cs < tc; ++cs) {
    cout << "Case " << cs + 1 << ": ";
    answer.clear();
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n + 1);
    for (int i = 0; i < n + 1; ++i) {
      cin >> a[i];
    }
    long long low = *max_element(a.begin(), a.end());
    long long high = accumulate(a.begin(), a.end(), 0LL);
    long long ans = 0;
    while (low <= high) {
      long long mid = low + (high - low)/2;
      if (check(mid, a, n + 1, k)) {
        ans = mid;
        high = mid - 1;
      }
      else {
        low = mid + 1;
      }
    }
    cout << ans << '\n';
    long long d = k + 1 - (int)answer.size();
    vector<long long> v;
    while (d > 0) {
      long long x = a.back();
      a.pop_back();
      v.push_back(x);
      answer.back() -= x;
      if (answer.back() == 0) {
        answer.pop_back();
      }
      else {
        d--;
      }
    }
    reverse(v.begin(), v.end());
    for (auto& x: v) {
      answer.push_back(x);
    }
    for (auto& x: answer) {
      cout << x << '\n';
    }
  }
  return 0;
}
