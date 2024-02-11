#include<bits/stdc++.h>
 
int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
 
	long long N; cin >> N;
	set<long long> S;
	for(int i = 0; i < N; ++i){
		long long x; cin >> x;
		S.insert(x);
	}
	cout << S.size() << '\n';
 
	return 0;
}
