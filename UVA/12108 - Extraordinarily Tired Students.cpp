#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>

using namespace std;

#define LL long long

int main() {
  int N, case_num = 1;
  while (scanf("%d", &N) == 1 && N) {
    vector<int> A(N), B(N), C(N), D(N);
    int sleep = 0, awake = 0, count = 1;
    for (int i = 0; i < N; ++i) {
      scanf("%d %d %d", &A[i], &B[i], &C[i]);
      D[i] = A[i] + B[i];
      count *= D[i];
    }
    int ans = -1;
    for (int it = 1; it <= count; ++it) {
      awake = 0, sleep = 0;
      for (int i = 0; i < N; ++i) {
        if (C[i] <= A[i]) {
          ++awake;
        }
        else {
          sleep++;
        }
      }
      if (awake == N) {
        ans = it;
        break;
      }
      for (int i = 0; i < N; ++i) {
        C[i]++;
        if (C[i] == D[i] + 1) {
          C[i] = 1;
        }
        else if (C[i] == A[i] + 1 && awake >= sleep) {
          C[i] = 1;
        }
      }
    }
    printf("Case %d: %d\n", case_num++, ans);
  }
  return 0;
}
