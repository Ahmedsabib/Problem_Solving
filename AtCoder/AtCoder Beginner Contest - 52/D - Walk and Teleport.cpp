#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long N, A, B; cin >> N >> A >> B;
	int Arr[N];
	for(int i = 0; i < N; ++i){
		cin >> Arr[i];
	}
	long long ans = 0;
	for(int i = 1; i < N; ++i){
		long long diff = abs(Arr[i-1]-Arr[i]);
		ans += min(diff*A, B);
	}
	cout << ans << '\n';
	return 0;
}
