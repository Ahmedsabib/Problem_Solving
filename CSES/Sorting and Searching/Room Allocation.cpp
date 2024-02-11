#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)2e5 + 5;
long long n;
long long ans[maxn];
vector<pair<pair<long long, long long>, long long>> p(maxn);
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  cin >> n;
  p.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i].first.first >> p[i].first.second;
    p[i].second = i;
  }
  sort(p.begin(), p.end());
  priority_queue<pair<long long, long long>> pq;
  long long r = 0;
  for (int i = 0; i < n; ++i) {
    if (pq.empty()) {
      ++r;
      pq.push(make_pair(-p[i].first.second, r));
      ans[p[i].second] = r;
    }
    else {
      pair<long long, long long> m = pq.top();
      if (-m.first < p[i].first.first) {
        pq.pop();
        pq.push(make_pair(-p[i].first.second, m.second));
        ans[p[i].second] = m.second;
      }
      else {
        ++r;
        pq.push(make_pair(-p[i].first.second, r));
        ans[p[i].second] = r;
      }
    }
    r = max(r, (long long)(pq.size()));
  }
  cout << r << '\n';
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
  return 0;
}
