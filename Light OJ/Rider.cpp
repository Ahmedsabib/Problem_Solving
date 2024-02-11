#include <bits/stdc++.h>

using namespace std;

const int maxn = 105;

int dx[] = {+1,+1,+2,+2,-1,-1,-2,-2};
int dy[] = {+2,-2,+1,-1,+2,-2,+1,-1};

int m, n;
char str[15][15];
int steps[maxn], dist[maxn][15][15];

bool valid(int x, int y) {
  if (x >= 0 && x < m && y >= 0 && y < n) {
    return true;
  }
  else {
    return false;
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case "<< cases + 1 << ": ";
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
      cin >> str[i];
    }
    vector<pair<int, int>> knights;
    int cnt = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (str[i][j] >= '1' && str[i][j] <= '9') {
          steps[cnt++] = str[i][j] - '0';
          knights.push_back({i, j});
        }
      }
    }
    for (int i = 0; i < (int)knights.size(); ++i) {
      for (int j = 0; j < m; ++j) {
        for (int k = 0; k < n; ++k) {
          dist[i][j][k] = 1e9;
        }
      }
      queue<pair<int, pair<int, pair<int, int>>>> q;
      q.push({1, {steps[i] - 1, {knights[i].first, knights[i].second}}});
      dist[i][knights[i].first][knights[i].second] = 0;
      while (!q.empty()) {
        pair<int, pair<int, pair<int, int>>> pr = q.front();
        q.pop();
        int d = pr.first;
        int s = pr.second.first;
        int x = pr.second.second.first;
        int y = pr.second.second.second;
        for (int j = 0; j < 8; ++j) {
          int xx = x + dx[j];
          int yy = y + dy[j];
          if (valid(xx, yy)) {
            if (d < dist[i][xx][yy]) {
              dist[i][xx][yy] = d;
              if (s == 0) {
                q.push({d + 1, {steps[i] - 1, {xx, yy}}});
              }
              else {
                q.push({d, {s - 1, {xx, yy}}});
              }
            }
          }
        }
      }
    }
    long long ans = 1e9;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        long long maxi = 0;
        for (int k = 0; k < (int)knights.size(); ++k) {
          maxi += dist[k][i][j];
        }
        ans = min(ans, maxi);
      }
    }
    if (ans == 1e9) {
      ans = -1;
    }
    cout << ans << '\n';
  }
  return 0;
}
