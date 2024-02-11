#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int x, N; cin >> x >> N;
    set<int64_t> lights;
    multiset<int64_t> distance;
    lights.insert(0), lights.insert(x);
    distance.insert(x);
    for(int i  = 0; i < N; ++i) {
    	int x; cin >> x;
    	auto it1 = lights.upper_bound(x);
    	auto it2 = it1;
    	it2--;
    	distance.erase(distance.find(*it1 - *it2));
    	distance.insert(x-*it2);
    	distance.insert(*it1-x);
    	lights.insert(x);	
    	auto ans = distance.end();
    	--ans;
    	cout << *ans << ' ';
    }
    cout << '\n';
    
    return 0;
}
