#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	string S, W; cin >> S >> W;
	int N = S.size() + W.size();
	string T;
	int j = 0, k = 0;
	for(int i = 0; i < N; ++i){
	 if(i%2 != 0){
	  T += W[j];
	  ++j;
	 }
	 else{
	  T += S[k];
	  ++k;
	 }
	}
	cout << T << '\n';
	return 0;
}
