#include <bits/stdc++.h>

using namespace std;

vector<int> adj[150];
int status[150], A[30], freq[150], vis[150], c, N;

void BFS(int X, int ch) {
  queue<int> Q;
  Q.push(X);
  for (int i = 0; i <= N * N; ++i) {
    vis[i] = 0;
    freq[i] = 0;
  }
  vis[X] = 1;
  while (!Q.empty()) {
    int S = Q.front();
    Q.pop();
    for (int j = 0; j < (int)adj[S].size(); ++j) {
      int v = adj[S][j];
      // If not visited and not -1 and not greater than the next letter
      if (!vis[v] && status[v] != -1 && status[v] <= ch) {
        if (status[v] == ch) { // If (find the letter)
          c = freq[S] + 1;
          return;
        }
        else {
          freq[v] = freq[S] + 1;
        }
        Q.push(v);
        vis[v] = 1;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int T, cs = 1;
  cin >> T;
  while (T--) {
    cout << "Case " << cs++ << ": ";
    cin >> N;
    int cnt = 0, m = 0;
    for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= N; ++j) {
        char ch;
        cin >> ch;
        ++cnt;
        if (ch == '.') {
          status[cnt] = 0;
        }
        else if (ch == '#') {
          status[cnt] = -1;
        }
        else {
          int X = (ch - 'A') + 1;
          m = max(m, X); // Highest Letter
          status[cnt] = X;
          A[X] = cnt; // Saving the position of the letter
        }
        if (i > 1) {
          adj[cnt].push_back(cnt - N);
          adj[cnt - N].push_back(cnt);
        }
        if (j > 1) {
          adj[cnt].push_back(cnt - 1);
          adj[cnt - 1].push_back(cnt);
        }
      }
    }
    int ok = 0, ans = 0;
    for (int i = 1; i <= m - 1; ++i) {
      c = 0;
      BFS(A[i], i + 1); // BFS for every letter except the last one
      if (c == 0) {    // If (Fail to get next letter) 
        ok = 1;
      }
      else {
        ans += c;
      }
    }
    if (ok) {
      cout << "Impossible\n";
    }
    else {
      cout << ans << '\n';
    }
    for (int i = 0; i <= N * N; ++i) {
      adj[i].clear();
    }
  }
  return 0;
}
