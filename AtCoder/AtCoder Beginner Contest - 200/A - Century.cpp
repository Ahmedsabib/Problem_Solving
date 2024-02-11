#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int64_t N; cin >> N;
	if(N%100 == 0) cout << N/100 << '\n';
	else cout << (N/100) + 1 << '\n';

    return 0;
}
