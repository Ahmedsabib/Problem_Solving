#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 2e5 + 5;

int n, ans = 0;
int visited[maxn];
vector<int> graph[maxn];

void dfs(int node, int parent) {
  for (auto& edges: graph[node]) {
    if (edges != parent) {
      dfs(edges, node);
      if (!visited[edges] && !visited[node]) {
        visited[edges] = 1;
        visited[node] = 1;
        ans++;
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
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  dfs(1, 0);
  cout << ans << '\n';
  return 0;
}
