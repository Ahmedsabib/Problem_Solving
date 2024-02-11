#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int N; cin >> N;
    vector<pair<int,int>> A(N);
    for(int i = 0; i < N; ++i){
    	int x, y; cin >> x >> y;
    	A.push_back(make_pair(x, 1));
    	A.push_back(make_pair(y, -1));
    }
    sort(A.begin(), A.end());
    int best = 0, sum = 0;
    for(int i = 0; i < A.size(); ++i){
    	sum += A[i].second;
    	best = max(best, sum);
    }
    cout << best << '\n';
    
    return 0;
}
