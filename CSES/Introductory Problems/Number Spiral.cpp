#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--){
  	long long y, x;
  	cin >> y >> x;
  	if(x > y){
  	 if(x&1){
  	  cout << (x*x)-y+1;
  	 }
  	 else{
  	  --x;
  	  cout << (x*x)+y;
  	 }
  	}
  	else{
  	 if(y%2 == 0){
  	  cout << (y*y)-x+1;
  	 }
  	 else{
  	  --y;
  	  cout << (y*y)+x;
  	 }
  	}
  	cout << '\n';
  }
  return 0;
}
