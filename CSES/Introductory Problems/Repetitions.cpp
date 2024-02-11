//CSES Problem Set - Repetitions
#include <bits/stdc++.h>
#define pb push_back
#define rep(i, a, n) for(int i = a; i < n; ++i)
#define per(i, a, n) for(int i = n-1; i >= a; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
void test_case(){
	string s;
	cin >> s;
	int n = s.size();
	int ans = 0, cnt = 1;
	rep(i, 0, n){
		if(s[i] == s[i+1]) ++cnt;
		else{
			ans = max(ans, cnt);
			cnt = 1;
		}
	}
	printf("%d\n", ans);
	
}
int main()
{
	test_case();
}
