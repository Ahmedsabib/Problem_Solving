#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long N; cin >> N;
  int pos = -1;
  for(int i = 0; ; ++i){
   if(i*(i+1)/2 >= N){ 
    pos = i; 
    break;
   }
  }
  cout << pos << '\n';
  return 0;
}
