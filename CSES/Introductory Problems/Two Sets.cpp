#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  string ans = "";
  vector<int>a, b;
  int sum = 0;
  vector<int>c(n+1);
  for(int i = 1; i <= n; ++i){
   c[i] = i;
   sum += i;
  }
  if(sum % 2 == 0){
   if(n%4 == 0){
    ans = "YES";
    for(int i = 1; i <= n/4; ++i){
     a.push_back(i);
    }
    for(int i = 0; i < n/4; ++i){
     a.push_back(c[n-i]);
    }
    for(int i = n/4 +1; i < a[a.size()-1]; ++i){
     b.push_back(i);
    }
   }
   else if(n%4 == 3){
    ans = "YES";
    vector<int>arr;
    for(int i = 4; i < n+1; ++i){
     arr.push_back(i);
    }
    a.push_back(1), a.push_back(2), b.push_back(3);
    for(int i = 0; i < (n-3)/4; ++i){
     a.push_back(arr[i]);
     a.push_back(arr[arr.size()-1-i]);
    }
    for(int i = 4+(n-3)/4; i <= n-(n-3)/4; ++i){
     b.push_back(i);
    }
   }
   else ans = "NO";
  }
  else ans = "NO";
  if(ans == "YES"){
   cout << ans << '\n';
   cout << a.size() << '\n';
   for(int i: a) cout << i << ' ';
   cout << '\n';
   cout << b.size() << '\n';
   for(int i: b) cout << i << ' ';
   cout << '\n';
  }
  else if(ans == "NO") cout << ans << '\n';
  return 0;
}
