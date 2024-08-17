#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int N;
    cin >> N;
    vector<int> pref(N + 1);
 
    for (int i = 2; i <= N; ++i) {
        int num = i, cnt = 0;
 
        while (num%2 == 0) {
            num /= 2;
            ++cnt;
        }
 
        pref[i] += cnt;
        pref[i] += pref[i - 1];
    }
 
    int ans = 0;
 
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
 
        if (pref[N - 1] - pref[i] - pref[N - i - 1] == 0) ans ^= val;
    }
 
    cout << ans << '\n';
 
    return 0;
}
