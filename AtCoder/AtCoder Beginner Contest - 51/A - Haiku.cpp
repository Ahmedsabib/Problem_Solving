#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string S;
  cin >> S;
  for(int i = 0; i < S.size(); ++i){
   if(S[i] == ',') S[i] = ' ';
  }
  cout << S << '\n';
  return 0;
}
