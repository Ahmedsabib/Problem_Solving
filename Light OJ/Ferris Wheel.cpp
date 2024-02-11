#include <bits/stdc++.h>

using namespace std;

bool fully_visited(int vis[30][30], int M, int person) {
  for (int i = 0; i < M; ++i) {
    if (vis[person][i] == 0) {
      return false;
    }
  }
  return true;
}

int select_person(list<int> ls, int vis[30][30], int lowest_seat) {
  for (list<int>::iterator it = ls.begin(); it != ls.end(); ++it) {
    if (vis[*it][lowest_seat] == 0) {
      return *it;
    }
  }
  return 0;
}

bool wheel_occupied(int wheel[], int M) {
  for (int i = 0; i < M; ++i) {
    if (wheel[i] > 0) {
      return true;
    }
  }
  return false;
}

int main() {
  int T, cases = 1;
  scanf("%d", &T);
  while (T--) {
    int N, M;
    scanf("%d %d", &N, &M);
    list<int> ls;
    for (int i = 1; i <= N; ++i) {
      ls.push_back(i);
    }
    int vis[30][30] = {};
    int wheel[M + 2] = {};
    int lowest_seat = 0, done = 0, ans = 0;
    do {
      lowest_seat = (lowest_seat + 1)%M;
      if (wheel[lowest_seat] != 0) {
        if (fully_visited(vis, M, wheel[lowest_seat])) {
          ++done;
          wheel[lowest_seat] = 0;
        }
        else {
          ls.push_back(wheel[lowest_seat]);
          wheel[lowest_seat] = 0;
        }
      }
      int new_person = 0;
      new_person = select_person(ls, vis, lowest_seat);
      ls.remove(new_person);
      wheel[lowest_seat] = new_person;
      if (new_person != 0) {
        vis[new_person][lowest_seat] = 1;
      }
      ++ans;
    } while (wheel_occupied(wheel, M) || (done < N));
    printf("Case %d: %d\n", cases++, ans * 5);
  }
  return 0;
}
