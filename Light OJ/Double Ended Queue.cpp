#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int T, cases = 1;
  cin >> T;
  while (T--) {
    cout << "Case " << cases++ << ":\n";
    int N, M;
    cin >> N >> M;
    deque<int> S;
    for (int i = 0; i < M; ++i) {
      string s;
      cin >> s;
      if ((s == "pushLeft" || s == "pushRight") && (int)S.size() >= N) {
        int y;
        cin >> y;
        cout << "The queue is full\n";
      }
      else if ((s == "popLeft" || s == "popRight") && (int)S.size() == 0) {
        cout << "The queue is empty \n";
      }
      else if (s == "pushLeft") {
        int y;
        cin >> y;
        S.push_front(y);
        cout << "Pushed in left: " << y << '\n';
      }
      else if (s == "pushRight") {
        int y;
        cin >> y;
        S.push_back(y);
        cout << "Pushed in right: " << y << '\n';
      }
      else if (s == "popLeft") {
        int p = S.front();
        S.pop_front();
        cout << "Popped from left: " << p << '\n';
      }
      else if (s == "popRight") {
        int p = S.back();
        S.pop_back();
        cout << "Popped from right: " << p << '\n';
      }
    }
  }
  return 0;
}
