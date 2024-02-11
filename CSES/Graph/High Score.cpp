#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e18;
const long long neg_inf = -1e18;

struct edge {
  long long from, to, weight;
};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<edge> graph;
  for (int i = 0; i < m; ++i) {
    edge x;
    cin >> x.from >> x.to >> x.weight;
    x.weight *= -1;
    graph.push_back(x);
  }
  vector<long long> dist(n + 1, inf);
  dist[1] = 0;
  for (int i = 0; i < n; ++i) {
    for (auto& x: graph) {
      long long u = x.from, v = x.to, w = x.weight;
      if (dist[u] == inf) {
        continue;
      }
      dist[v] = min(dist[v], dist[u] + w);
      dist[v] = max(dist[v], neg_inf);
    }
  }
  for (int i = 0; i < n; ++i) {
    for (auto& x: graph) {
      long long u = x.from, v = x.to, w = x.weight;
      if (dist[u] == inf) {
        continue;
      }
      dist[v] = max(dist[v], neg_inf);
      if (dist[v] > dist[u] + w) {
        dist[v] = neg_inf;
      }
    }
  }
  if (dist[n] == inf || dist[n] == neg_inf) {
    cout << "-1\n";
  }
  else {
    cout << -1 * dist[n] << '\n';
  }
  return 0;
}
