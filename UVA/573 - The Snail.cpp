#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int h, u, d, f;
    while(cin >> h >> u >> d >> f){

        if(!h) return 0;
        double distance_min = u*(f/100.0), initial_height = 0, ok = 0, height = u;
        int days = 0;
        while(true){
            ++days;
            initial_height += height;
            if(initial_height > h) break;
            initial_height -= d;
            if(initial_height < 0){
                ok = 1;
                break;
            }
            height -= distance_min;
            if(height < 0) height = 0;
        }
        if(ok) cout << "failure on day " << days << '\n';
        else cout << "success on day " << days << '\n';
    }
    
    return 0;
}
