#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long N; cin >> N;
  unordered_set<long long>S;
  for(long long i = 2; i * i <= N; ++i){
   long long x = i;
   while(x * i <= N){
    S.insert(x * i);
    x *= i;
   }
  }
  cout << N - S.size() << '\n';
  return 0;
}
