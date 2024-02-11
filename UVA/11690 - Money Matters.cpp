#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)5e4 + 5;
vector<long long> graph[maxn];
bool visited[maxn];
long long a[maxn];
long long cnt = 0;
void dfs(long long node) {
  visited[node] = true;
  cnt += a[node];
  for (auto& edges: graph[node]) {
    if (!visited[edges]) {
      dfs(edges);
    }
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int tc;
  cin >> tc;
  for (int cs = 0; cs < tc; ++cs) {
    memset(visited, false, sizeof(visited));
    memset(graph, 0, sizeof(graph));
    long long n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
      long long u, v;
      cin >> u >> v;
      graph[u].push_back(v);
      graph[v].push_back(u);
    }
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      if (!visited[i]) {
        cnt = 0;
        dfs(i);
        if (cnt != 0) {
          ok = false;
          break;
        }
      }
    }
    cout << (ok ? "POSSIBLE\n" : "IMPOSSIBLE\n");
  }
  return 0;
}
