#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	for(int i = 1; i <= T; ++i) {
		long long N, M; cin >> N >> M;
		if(N == 1 or M == 1) cout << "Case " << i << ": " << max(M, N) << '\n';
		else if(N == 2 or M == 2) cout << "Case " << i << ": " << ((M*N)/8)*4 + ((M*N)%8 > 4? 4 : (M*N)%8) << '\n'; 
		else cout << "Case " << i << ": " << ((N*M)+1)/2 << '\n';
	}
	return 0;
}
