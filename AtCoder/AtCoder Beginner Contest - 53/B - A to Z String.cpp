#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string S; cin >> S;
	int N = S.size();
	int a = 1e9+7, b = 0;
	for(int i = 0; i < N; ++i){
		if(S[i] == 'A') a = min(a, i);
		if(S[i] == 'Z') b = max(b, i);
	}
	int ans = b - a + 1;
	cout << ans << '\n';
	return 0;
}
