#include <bits/stdc++.h>
using namespace std;
const int maxn = 25;
char s[maxn][maxn];
bool visited[maxn][maxn];
int h, w, ans = 0;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool check(int x, int y) {
  if (x >= 0 && x < h && y >= 0 && y < w && s[x][y] != '#' && !visited[x][y]) {
    return true;
  }
  else {
    return false;
  }
}
void dfs(int x, int y) {
  visited[x][y] = true;
  ++ans;
  for (int k = 0; k < 4; ++k) {
    int i = x + dx[k];
    int j = y + dy[k];
    if (check(i, j)) {
      dfs(i, j);
    }
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int tc;
  cin >> tc;
  for (int cs = 0; cs < tc; ++cs) {
    cout << "Case " << cs + 1 << ": ";
    for (int i = 0; i < maxn; ++i) {
      for (int j = 0; j < maxn; ++j) {
        visited[i][j] = false;
      }
    }
    ans = 0;
    cin >> w >> h;
    for (int i = 0; i < h; ++i) {
      cin >> s[i];
    }
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (s[i][j] == '@') {
          dfs(i, j);
          break;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
