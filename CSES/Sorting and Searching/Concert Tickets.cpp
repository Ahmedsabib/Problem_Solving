#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	long long N, M; std::cin >> N >> M;
	std::vector<long long> A(N), B(M);
	multiset<int, greater<int>>S;
	for(int i = 0; i < N; ++i){
		std::cin >> A[i];
		S.insert(A[i]);
	}
	for(int j = 0; j < M; ++j){
		std::cin >> B[j];
		auto it = S.lower_bound(B[j]);
		if(it == S.end()){
			std::cout << -1 << '\n';
		} else{
			std::cout << *it << '\n';
			S.erase(it);
		}
	}

	return 0;
}
