#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

vector<int> graph[maxn];
int visited[maxn];

void dfs(int node) {
  visited[node] = 1;
  for (auto& edge: graph[node]) {
    if (!visited[edge]) {
      dfs(edge);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  if (m > n) {
    cout << "NO\n";
    return 0;
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (!visited[i]) {
      dfs(i);
      ++ans;
    }
  }
  cout << (ans == 1? "YES" : "NO") << '\n';
  return 0;
}
