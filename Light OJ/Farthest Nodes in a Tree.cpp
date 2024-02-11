#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)3e4 + 6;
int n;
vector<int> adj[maxn], weight[maxn];
bool visited[maxn];
int dist[maxn];
void bfs(int node) {
  queue<int> q;
  visited[node] = true;
  q.push(node);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = 0; i < (int)adj[x].size(); ++i) {
      int edges = adj[x][i];
      if (!visited[edges]) {
        visited[edges] = true;
        dist[edges] = dist[x] + weight[x][i];
        q.push(edges);
      }
    }
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int tc;
  cin >> tc;
  for (int cs = 0; cs < tc; ++cs) {
    cout << "Case " << cs + 1 << ": ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
      adj[i].clear();
      weight[i].clear();
    }
    for (int i = 0; i < n; ++i) {
      visited[i] = false;
      dist[i] = 0;
    }
    for (int i = 0; i < n - 1; ++i) {
      int x, y, z;
      cin >> x >> y >> z;
      adj[x].push_back(y);
      adj[y].push_back(x);
      weight[x].push_back(z);
      weight[y].push_back(z);
    }
    bfs(0);
    int maxi = -1, needed_node;
    for (int i = 0; i < n; ++i) {
      if (maxi < dist[i]) {
        maxi = dist[i];
        needed_node = i;
      }
    }
    for (int i = 0; i < n; ++i) {
      visited[i] = false;
      dist[i] = 0;
    }
    bfs(needed_node);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans = max(ans, dist[i]);
    }
    cout << ans << '\n';
  }
  return 0;
}
