#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1000;
vector<int> graph[maxn];
int ans;
void shortest_cylcle(int n) {
  ans = 1e9;
  for (int i = 0; i < n; ++i) {
    vector<int> dist(n, 1e9);
    vector<int> parent(n, -1);
    queue<int> q;
    dist[i] = 0;
    q.push(i);
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (auto& edge: graph[x]) {
        if (dist[edge] == 1e9) {
          dist[edge] = dist[x] + 1;
          parent[edge] = x;
          q.push(edge);
        }
        else if (parent[x] != edge) {
          ans = min(ans, dist[x] + dist[edge] + 1);
        }
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
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
      graph[i].clear();
    }
    for (int i = 0; i < m; ++i) {
      int x, y;
      cin >> x >> y;
      graph[x].push_back(y);
      graph[y].push_back(x);
    }
    shortest_cylcle(n);
    if (ans == 1e9) {
      cout << "impossible\n";
    }
    else {
      cout << ans << '\n';
    }
  }
  return 0;
}
