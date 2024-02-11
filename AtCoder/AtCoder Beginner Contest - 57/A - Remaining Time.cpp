#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int A, B; cin >> A >> B;
    A += B;
    cout << A%24 << '\n';
    
    return 0;
}
