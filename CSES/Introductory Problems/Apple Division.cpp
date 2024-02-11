#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long N; cin >> N;
	long long A[N];
	long long sum = 0;
	for(int i = 0 ; i < N; ++i){
		cin >> A[i];
		sum += A[i];
	}
	long long ans = 1e9 + 7;
	for(int i = 0; i < (1 << N); ++i){
		long long c = 0;
		for(int j = 0; j < N; ++j){
			if((1 << j) & i) c += A[j];
		}
		ans = min(ans, abs(sum - 2*c));
	}
	cout << ans << '\n';
	
	return 0;
}
