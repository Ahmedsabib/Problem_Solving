#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int N; cin >> N;
    vector<int>A(N);
    int sum = 0;
    for(int i = 0; i < N; ++i){
        cin >> A[i];
        if(A[i] > 10) sum += (A[i]-10);
    }
    cout << sum << '\n';
    
    return 0;
}
