#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9 + 7;
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  long long n, m;
  cin >> n >> m;
  vector<vector<long long>> graph;
  for (int i = 0; i < m; ++i) {
    long long a, b, c;
    cin >> a >> b >> c;
    graph.push_back({a, b, c});
  }
  vector<long long> relax(n + 1);
  for (int i = 1; i <= n; ++i) {
    relax[i] = -1;
  }
  vector<long long> dist(n + 1);
  dist[0] = 0;
  long long c;
  for (int i = 0; i < n - 1; ++i) {
    c = -1;
    for (auto& x: graph) {
      long long u, v, w;
      u = x[0];
      v = x[1];
      w = x[2];
      if (dist[u] + w < dist[v] && dist[u] != inf) {
        dist[v] = w + dist[u];
        relax[v] = u;
        c = v;
      }
    }
  }
  if (c == -1) {
    cout << "NO\n";
  }
  else {
    cout << "YES\n";
    for (int i = 1; i <= n; ++i) {
      c = relax[c];
    }
    vector<long long> cycle;
    for (int i = c; ; i = relax[i]) {
      cycle.push_back(i);
      if (i == c && (int)cycle.size() > 1) {
        break;
      }
    }
    reverse(cycle.begin(), cycle.end());
    for (int i = 0; i <  (int)cycle.size(); ++i) {
      cout << cycle[i] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
