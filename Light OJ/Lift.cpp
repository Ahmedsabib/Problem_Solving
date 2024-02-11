#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case " << cases + 1 << ": ";
    int n, m;
    cin >> n >> m;
    int x = abs(m - n) * 4; // lift spending time on going the floor
    int y = 3 * 3; // door opens and closes 3 times
    int z = 5 * 2; // time to get on and get off on the lift
    cout << (x + y + z) + (n * 4) << '\n'; // total
  }
  return 0;
}
