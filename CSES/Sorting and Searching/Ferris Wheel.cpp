#include<bits/stdc++.h>
 
int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
 
	long long N, M; cin >> N >> M;
	std::vector<int> A(N);
	for(int i = 0; i < N; ++i){
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	int i = 0, j = N-1;
	long long cnt = N;
	while(i < j){
		if(A[i]+A[j] <= M){
			--cnt;
			++i;
			--j;
		}
		else --j;
	}
	cout << cnt << '\n';
 
	return 0;
}
