#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  for(int i = 0; i < (1 << N); ++i){
   int val = i ^ (i >> 1);
   bitset<32>r(val);
   string S = r.to_string();
   cout << S.substr(32-N) << '\n';
  }
  return 0;
}
