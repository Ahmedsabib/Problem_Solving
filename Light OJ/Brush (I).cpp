#include <bits/stdc++.h>

const int MAX = 1e6+7;
int64_t freq[MAX];

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	for(int testCase = 1; testCase <= T; ++testCase){
		
		int64_t N; cin >> N;
		int64_t sum = 0;
		for(int i = 0; i < N; ++i){
			int64_t x; cin >> x;
			if(x > 0) sum += x;
		}
		cout << "Case " << testCase << ": " << sum << '\n';
	}
	
	return 0;
}
