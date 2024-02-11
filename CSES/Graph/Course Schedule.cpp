#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

int n, m, cycle_start, cycle_end;
vector<int> graph[maxn];
int visited[maxn], color[maxn] = {0}, parent[maxn] = {-1};
stack<int> nodes_path;

void dfs(int node) {
  visited[node] = 1;
  for (auto& edges: graph[node]) {
    if (!visited[edges]) {
      dfs(edges);
    }
  }
  nodes_path.push(node);
}

bool cycle_found(int node) {
  color[node] = 1;
  for (auto& edges: graph[node]) {
    if (color[edges] == 0) {
      parent[edges] = node;
      if (cycle_found(edges)) {
        return true;
      }
    }
    else if (color[edges] == 1) {
      cycle_end = node;
      cycle_start = edges;
      return true;
    }
  }
  color[node] = 2;
  return false;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
  }
  cycle_start = -1;
  for (int i = 1; i <= n; ++i) {
    if (color[i] == 0 && cycle_found(i)) {
      break;
    }
  }
  if (cycle_start != -1) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    if (!visited[i]) {
      dfs(i);
    }
  }
  while (!nodes_path.empty()) {
    cout << nodes_path.top() << ' ';
    nodes_path.pop();
  }
  cout << '\n';
  return 0;
}
