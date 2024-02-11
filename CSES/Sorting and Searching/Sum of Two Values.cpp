#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int64_t N, M; cin >> N >> M;
    vector<pair<int64_t, int64_t>>A(N);
    for(int i = 0; i < N; ++i){
    	int64_t x; cin >> x;
    	A[i].first = x;
    	A[i].second = i;
    }
    sort(A.begin(), A.end());
    int64_t i = 0, j = N-1;
    while(i < j){
    	if(A[i].first + A[j].first > M){
    		--j;
    	}else if(A[i].first + A[j].first < M){
    		++i;
    	} else{
    		cout << A[i].second+1 << ' ' << A[j].second+1 << '\n';
    		return 0;
    	}
    }
    cout << "IMPOSSIBLE" << '\n';

    return 0;
}
