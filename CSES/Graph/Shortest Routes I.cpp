#include <bits/stdc++.h>

using namespace std;

const int maxn = (int)2e5 + 5;
const long long inf = 1e18;

vector<pair<long long, long long>> adj[maxn];
long long d[maxn];
long long n, m;

void dijkstra(int node) {
  for (int i = 0; i < n; ++i) {
    d[i] = inf;
  }
  d[node] = 0;
  priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;
  q.push({0, node});
  while (!q.empty()) {
    long long v = q.top().second;
    long long d_v = q.top().first;
    q.pop();
    if (d_v != d[v]) {
      continue;
    }
    for (auto& edges: adj[v]) {
      long long adj_node = edges.first;
      long long edge_cost = edges.second;
      if (d[v] + edge_cost < d[adj_node]) {
        d[adj_node] = d[v] + edge_cost;
        q.push({d[adj_node], adj_node});
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u - 1].push_back({v - 1, w});
  }
  int source = 0;
  dijkstra(source);
  for (int i = 0; i < n; ++i) {
    cout << d[i] << ' ';
  }
  cout << '\n';
  return 0;
}
