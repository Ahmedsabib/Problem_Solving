#include <bits/stdc++.h>

using namespace std;

const int maxn = 1005;

vector<int> graph[maxn];
int a[maxn], visited[maxn];
int tot = 0, cnt = 0;

void dfs(int node) {
  visited[node] = 1;
  tot += a[node];
  ++cnt;
  for (auto& edges: graph[node]) {
    if (!visited[edges]) {
      dfs(edges);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case " << cases + 1 << ": ";
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      graph[u].push_back(v);
      graph[v].push_back(u);
    }
    set<int> s;
    int ok = 0;
    for (int i = 1; i <= n; ++i) {
      if (!visited[i]) {
        tot = 0, cnt = 0;
        dfs(i);
        if (tot%cnt != 0) {
          ok = 1;
          break;
        }
        s.insert(tot/cnt);
      }
    }
    if ((int)s.size() > 1 || ok) {
      cout << "No\n";
    }
    else {
      cout << "Yes\n";
    }
    for (int i = 0; i < maxn; ++i) {
      graph[i].clear();
      visited[i] = 0;
    }
  }
  return 0;
}
