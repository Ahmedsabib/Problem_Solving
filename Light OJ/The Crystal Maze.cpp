#include <bits/stdc++.h>

using namespace std;

const int maxn = 505;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n, m, query, gem = 0;
char grid[maxn][maxn];
int visited[maxn][maxn], cost[maxn][maxn];

bool check(int x, int y) {
  return (x >= 0 && x < n && y < m && y >= 0 && grid[x][y] != '#');
}

void dfs(int x, int y) {
  if (grid[x][y] == 'C') {
    ++gem;
  }
  visited[x][y] = 1;
  for (int i = 0; i < 4; ++i) {
    int new_x = x + dx[i];
    int new_y = y + dy[i];
    if (check(new_x, new_y) && !visited[new_x][new_y]) {
      dfs(new_x, new_y);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case " << cases + 1 << ":\n";
    memset(cost,-1,sizeof(cost));
    cin >> n >> m >> query;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> grid[i][j];
      }
    }
    while (query--) {
      memset(visited,0,sizeof(visited));
      gem = 0;
      int x, y;
      cin >> x >> y;
      if (cost[x - 1][y - 1] == -1) {
        dfs(x - 1, y - 1);
        cost[x - 1][y - 1] = gem;
        cout << gem << '\n';
        for (int i = 0; i < n; ++i) {
          for (int j = 0; j < m; ++j) {
            if (visited[i][j]) {
              cost[i][j] = gem;
            }
          }
        }
      }
      else {
        cout << cost[x - 1][y - 1] << '\n';
      }
    }
  }
  return 0;
}
