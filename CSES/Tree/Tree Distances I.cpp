#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 3e5 + 5;

int t, n;
int longest_node = 0, max_dist = 0, cases = 1;
int a[N], visited[N], dist[N], dist_a[N], dist_b[N];
vector<int> graph[N];

void bfs(int node) {
  queue<int> q;
  q.push(node);
  visited[node] = 1;
  dist[node] = 0;
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
  cin >> n;
  memset(visited, 0, sizeof(visited));
  memset(dist, 0, sizeof(dist));
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  bfs(0);
  max_dist = 0, longest_node = 0;
  for (int i = 0; i < n; ++i) {
    if (max_dist < dist[i]) {
      max_dist = dist[i];
      longest_node = i;
    }
  }
  memset(visited, 0, sizeof(visited));
  memset(dist, 0, sizeof(dist));
  bfs(longest_node);
  max_dist = 0, longest_node = 0;
  for (int i = 0; i < n; ++i) {
    if (max_dist < dist[i]) {
      max_dist = dist[i];
      longest_node = i;
    }
  }
  for (int i = 0; i < n; ++i) dist_a[i] = dist[i];
  memset(visited, 0, sizeof(visited));
  memset(dist, 0, sizeof(dist));
  bfs(longest_node);
  max_dist = 0, longest_node = 0;
  for (int i = 0; i < n; ++i) {
    if (max_dist < dist[i]) {
      max_dist = dist[i];
      longest_node = i;
    }
  }
  for (int i = 0; i < n; ++i) dist_b[i] = dist[i];
  max_dist = 0;  
  for (int i = 0; i < n; ++i) {
    max_dist = max(dist_a[i], dist_b[i]);
    cout << max_dist << ' ';
  }
  cout << '\n';
  return 0;
}
