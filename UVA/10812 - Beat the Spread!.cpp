#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int N; cin >> N;
    vector<int>A(N), B(N);
    for(int i = 0; i < N; ++i){
        cin >> A[i] >> B[i];
    }
    for(int i = 0; i < N; ++i){
        if(A[i] < B[i]){
            cout << "impossible" << '\n';
        }
        else{
            int ok = 0;
            for(int j = A[i]; j >= 0; --j){
                for(int k = j+1; k >= 0; --k){
                    if((j+k) == A[i] && (j-k) == B[i]){
                        cout << j << ' ' << k << '\n';
                        ok = 1;
                        break;
                    }
                }
                if(ok) break;
            }
            if(!ok) cout << "impossible" << '\n';
        }
    }
    
    return 0;
}
