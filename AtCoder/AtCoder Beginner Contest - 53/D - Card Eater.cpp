#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long N; cin >> N;
	long long A[N];
	set<long long>S;
	for(int i = 0; i < N; ++i){
		cin >> A[i];
		S.insert(A[i]);
	}
	long long ans = S.size();
	if(ans%2 == 0) --ans;
	cout << ans << '\n';
	return 0;
}
