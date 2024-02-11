#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1e5 + 7;
vector<long long> graph[maxn];
vector<long long> a;
bool visited[maxn];
long long cnt = 0;
void dfs(long long node) {
  visited[node] = true;
  ++cnt;
  for (auto& edges: graph[node]) {
    if (!visited[edges]) {
      dfs(edges);
    }
  }
}
int main(int argc, char const *argv[]) {
  long long n, m;
  cin >> n >> m;
  long long tot = (n * (n - 1))/2;
  for (int i = 0; i < m; ++i) {
    long long u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      cnt = 0;
      dfs(i);
      tot -= (cnt * (cnt - 1)/2);
    }
  }
  cout << tot << '\n';
  return 0;
}
