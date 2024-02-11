#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long MOD = 1e9+7;
	long long N; cin >> N;
	map<long long, long long> mp;
	for(int i = 2; i <= N; ++i){
		long long t = i;
		long long d = 2;
		while(t > 1){
			while(t%d == 0){
				mp[d]++;
				t /= d;
			}
			++d;
		}
	}
	long long res = 1;
	for(int i = 2; i <= N; ++i){
		res *= (mp[i] + 1);
		res %= MOD;
	}
	cout << res << '\n';
	return 0;
}
