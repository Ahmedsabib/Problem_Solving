#include <bits/stdc++.h>

using namespace std;

int64_t ans[3];

void extended_gcd(int64_t a, int64_t b){

    if(b == 0){
        ans[0] = a;
        ans[1] = 1;
        ans[2] = 0;
        return;
    }
    extended_gcd(b, a%b);
    int64_t x = ans[1];
    ans[0] = ans[0];
    ans[1] = ans[2];
    ans[2] = (x - (a/b)*ans[2]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t A, B;
    while(cin >> A >> B){
        
        extended_gcd(A, B);
        cout << ans[1] << ' ' << ans[2] << ' ' << ans[0] << '\n';
    }

    return 0;
}
