#include <bits/stdc++.h>

long long N, row, col, temp, r, v;

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	for(int i = 1; i <= T; ++i) {
		cin >> N;
		r = ceill(sqrt(N*1.0));
		v = r*r - N;
		if(r > v){
		 row = r;
		 col = v+1;
		}
		else{
		 col = r;
		 row = N - (r-1)*(r-1);
		}
		if(r%2 == 0){
		 temp = col;
		 col = row;
		 row = temp;
		}
		cout << "Case " << i << ": " << col << ' ' << row << '\n';
	}
	return 0;
}
