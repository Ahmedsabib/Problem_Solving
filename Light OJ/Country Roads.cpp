#include <bits/stdc++.h>

using namespace std;

const int maxn = 505;
const int inf = (int)1e9 + 7;

int n, m, t, max_cost;
vector<int> graph[maxn];
int cost[maxn][maxn], dist[maxn];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  // At first we must take the minimum distance of the copied roads
  // For this, we will check it while taking inputs
  // Then, we need to traverse every possible roads by brute force
  // And, update the values with the minimum value of the highest road

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case " << cases + 1 << ":\n";
    cin >> n >> m;
    max_cost = 0;
    memset(graph, 0, sizeof(graph));
    memset(cost, 0, sizeof(cost));
    for (int i = 0; i < n; ++i) {
      dist[i] = inf;
    }
    for (int i = 0; i < m; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      if (cost[u][v]) {
        cost[u][v] = min(cost[u][v], w);
        cost[v][u] = min(cost[v][u], w);
      }
      else {
        graph[u].push_back(v);
        graph[v].push_back(u);
        cost[u][v] = w;
        cost[v][u] = w;
      }
    }
    cin >> t;
    queue<int> q;
    q.push(t);
    dist[t] = 0;
    while (!q.empty()) {
      int top = q.front();
      q.pop();
      for (int i = 0; i < (int)graph[top].size(); ++i) {
        int x = graph[top][i];
        max_cost = max(dist[top], cost[x][top]);
        if (max_cost < dist[x]) {
          dist[x] = max_cost;
          q.push(x);
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      if (dist[i] == inf) {
        cout << "Impossible\n";
      }
      else {
        cout << dist[i] << '\n';
      }
    }
  }
  return 0;
}
