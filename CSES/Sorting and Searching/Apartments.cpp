#include<bits/stdc++.h>
 
int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
 
	long long N, M, K; cin >> N >> M >> K;
	std::vector<long long> A(N),  B(M);
	for(int i = 0; i < N; ++i){
		cin >> A[i];
	}
	for(int j = 0; j < M; ++j){
		cin >> B[j];
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	long long cnt = 0;
	long long i = 0, j = 0;
	while(i < N && j < M){
		if(A[i]-K > B[j]) ++j;
		else if(A[i]+K < B[j]) ++i;
		else{
			++i;
			++j;
			++cnt;
		}
	}
	cout << cnt << '\n';
 
	return 0;
}
