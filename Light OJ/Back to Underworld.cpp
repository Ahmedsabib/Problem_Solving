#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)2e4 + 5;
vector<long long> adj[maxn];
bool visited[maxn];
long long color[maxn];
long long bfs(long long node) {
  long long vampire = 0, lykan = 0;
  visited[node] = true;
  queue<long long> q;
  q.push(node);
  ++vampire;
  color[node] = 1;
  while (!q.empty()) {
    long long y = q.front();
    q.pop();
    for (auto& x: adj[y]) {
      if (!visited[x]) {
        visited[x] = true;
        q.push(x);
        if (color[y] == 1) {
          color[x] = 0;
          ++lykan;
        }
        else {
          color[x] = 1;
          ++vampire;
        }
      }
    }
  }
  return max(vampire, lykan);
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int tc;
  cin >> tc;
  for (int cs = 0; cs < tc; ++cs) {
    cout << "Case " << cs + 1 << ": ";
    for (int i = 0; i < maxn; ++i) {
      adj[i].clear();
      visited[i] = false;
    }
    long long n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      long long x, y;
      cin >> x >> y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    long long ans = 0;
    for (int i = 0; i < maxn; ++i) {
      if (!visited[i] && !adj[i].empty()) {
        ans += bfs(i);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
