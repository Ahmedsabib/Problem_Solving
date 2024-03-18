#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 2e5 + 5;

int n, visited[maxn], dist[maxn];
vector<int> graph[maxn];

void bfs(int node) {
  queue<int> q;
  q.push(node);
  dist[node] = 0;
  visited[node] = 1;
  while (!q.empty()) {
    int top = q.front();
    q.pop();
    for (auto& edges: graph[top]) {
      if (!visited[edges]) {
        visited[edges] = 1;
        dist[edges] = dist[top] + 1;
        q.push(edges);
      }
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  bfs(0);
  int maxi = 0, longest_node = 0;
  for (int i = 0; i < n; ++i) {
    if (dist[i] > maxi) {
      maxi = dist[i];
      longest_node = i;
    }
  }
  memset(visited, 0, sizeof(visited));
  memset(dist, 0, sizeof(dist));
  bfs(longest_node);
  maxi = 0;
  for (int i = 0; i < n; ++i) {
    maxi = max(maxi, dist[i]);
  }
  cout << maxi << '\n';
  return 0;
}
