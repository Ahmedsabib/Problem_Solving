#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int T; cin >> T;
    for(int testCase = 1; testCase <= T; ++testCase){
        
        double A, B, C, N; cin >> A >> B >> C >> N;
        double ratio =  N/(N+1);
        cout << "Case " << testCase << ": " << fixed << setprecision(6) <<  A*sqrt(ratio) << '\n';
    }
    
    return 0;
}
