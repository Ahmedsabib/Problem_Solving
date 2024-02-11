#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	for(int testCase = 1; testCase <= T; ++testCase){
		
		int64_t A[3];
		for(int i = 0; i < 3; ++i){
			cin >> A[i];
		}
		sort(A, A+3);
		string ans;
		if(A[0]*A[0] + A[1]*A[1] == A[2]*A[2]){
			ans = "yes";
		} else{
			ans = "no";
		}
		cout << "Case " << testCase << ": " << ans << '\n';
	}
	
	return 0;
}
