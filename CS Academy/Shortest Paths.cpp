#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1e5 + 5;
vector<int> adj[maxn];
queue<int> q;
bool visited[maxn];
vector<int> distances(maxn, -1);
void bfs(int node) {
  visited[node] = true;
  distances[node] = 0;
  q.push(node);
  while (!q.empty()) {
    int s = q.front();
    q.pop();
    for (auto& x: adj[s]) {
      if (!visited[x]) {
        visited[x] = true;
        distances[x] = distances[s] + 1;
        q.push(x);
      }
    }
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    // adj[y].push_back(x);
  }
  bfs(k);
  for (int i = 1; i <= n; ++i) {
    cout << distances[i] << ' ';
  }
  cout << '\n';
  return 0;
}
