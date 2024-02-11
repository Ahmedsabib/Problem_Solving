#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	double N, K; cin >> N >> K;
	double ans = 100 - ((K/N)*100);
	cout << setprecision(15) << ans << '\n';
	return 0;
}
