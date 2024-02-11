#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string S; cin >> S;
  map<char, string> mp;
  for(char c: S){
   if(mp.count(c)) mp[c] += c;
   else mp[c] = c;
  }
  string first = "", last = "", ok = "";
  for(auto c: mp){
   if(c.second.size()%2 == 1 and ok != ""){
    cout << "NO SOLUTION" << '\n';
    return 0;
   }
   else if(c.second.size()%2 == 1){
    ok = c.second;
   }
   else{
    first = c.second.substr(0, c.second.size()/2) + first;
    last += c.second.substr(0, c.second.size()/2);
   }
  }
  cout << last + ok + first << '\n';
  return 0;
} 
