#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case " << cases + 1 << ": ";
    int ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    int dx = ax + cx - bx, dy = ay + cy - by;
    int area = 0.5 * (((ax * by) + (bx * cy) + (cx * dy) + (dx * ay)) - ((ay * bx) + (by * cx) + (cy * dx) + (dy * ax)));
    if (area < 0) {
      area *= -1;
    }
    cout << dx << ' ' << dy << ' ' << area << '\n';
  }
  return 0;
}
