#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int64_t N, M; cin >> N >> M;
    vector<pair<int64_t, int64_t>>v(N);
    for(int i = 0; i < N; ++i){
    	cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    int64_t ans = 0;
    for(int i = 0; i < N; ++i){
    	int64_t distance = v[i].first - ans;
    	if(distance <= M){
    		M -= distance;
    		M += v[i].second;
    		ans = v[i].first;
    	}
    	else{
    		break;
    	}
    }
    ans += M;
    cout << ans << '\n';

    return 0;
}
