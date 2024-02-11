#include <bits/stdc++.h>
 
using namespace std;
  
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long N;
  cin >> N;
  long long cnt = 0;
  for(int i = 5; i <= N; i *= 5){
   cnt += N/i;
  }
  cout << cnt << '\n';
  return 0;
} 
