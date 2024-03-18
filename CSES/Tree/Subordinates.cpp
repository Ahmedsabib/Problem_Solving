#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 2e5 + 5;

int n;
int subtree[maxn], depth[maxn];
vector<int> graph[maxn];

void dfs(int node) {
  subtree[node] = 1;
  for (auto& edges: graph[node]) {
    depth[edges] = depth[node] + 1;
    dfs(edges);
    subtree[node] += subtree[edges];
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  cin >> n;
  for (int i = 1; i < n; ++i) {
    int u;
    cin >> u;
    --u;
    graph[u].push_back(i);
  }
  dfs(0);
  for (int i = 0; i < n; ++i) {
    cout << subtree[i] - 1 << " \n"[i == n - 1];
  }
  return 0;
}
