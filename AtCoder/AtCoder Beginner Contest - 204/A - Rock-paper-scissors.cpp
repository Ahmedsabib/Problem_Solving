#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int a, b; cin >> a >> b;
    if(a == b){
        cout << a << '\n';
    } else{
        if(a != 1 && b!= 1) cout << 1 << '\n';
        else if(a != 0 && b!= 0) cout << 0 << '\n';
        else cout << 2 << '\n';
    }
    
    return 0;
}
