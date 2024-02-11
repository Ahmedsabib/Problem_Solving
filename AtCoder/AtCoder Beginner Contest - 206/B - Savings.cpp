#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int64_t N; cin >> N;
    int64_t i = 0;
    while(N > 0){
        N -= ++i;
    }
    cout << i << '\n';
    
    return 0;
}
