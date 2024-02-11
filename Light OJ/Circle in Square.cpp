#include <bits/stdc++.h>

const double PI = 2*acos(0.0);

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	for(int testCase = 1; testCase <= T; ++testCase){
		
		double N; cin >> N;
		double area = PI*N*N;
		double square_area = (N+N)*(N+N);
		double ans = square_area - area;
		cout << "Case " << testCase << ": " << fixed << setprecision(2) << ans << '\n';
	}
	
	return 0;
}
