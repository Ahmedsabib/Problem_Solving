#include <bits/stdc++.h>
using namespace std;

map<string, map<string, string>> dir;

void direction() {
    dir["+z"]["+y"] = "+z";
    dir["+z"]["-y"] = "+z";
    dir["+z"]["+z"] = "-x";
    dir["+z"]["-z"] = "+x";
    dir["-z"]["+y"] = "-z";
    dir["-z"]["-y"] = "-z";
    dir["-z"]["+z"] = "+x";
    dir["-z"]["-z"] = "-x";
    dir["+y"]["+y"] = "-x";
    dir["+y"]["-y"] = "+x";
    dir["+y"]["+z"] = "+y";
    dir["+y"]["-z"] = "+y";
    dir["-y"]["+y"] = "+x";
    dir["-y"]["-y"] = "-x";
    dir["-y"]["+z"] = "-y";
    dir["-y"]["-z"] = "-y";
    dir["+x"]["+y"] = "+y";
    dir["+x"]["-y"] = "-y";
    dir["+x"]["+z"] = "+z";
    dir["+x"]["-z"] = "-z";
    dir["-x"]["+y"] = "-y";
    dir["-x"]["-y"] = "+y";
    dir["-x"]["+z"] = "-z";
    dir["-x"]["-z"] = "+z";
}

void run_case() {
    direction();

    int N;
    string ans;

    while (cin >> N && N != 0) {
        ans = "+x";

        for (int i = 0; i < N-1; ++i) {
            string decision;
            cin >> decision;

            if (decision == "No")
                continue;

            ans = dir[ans][decision];
        }

        cout << ans << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int tests = 1;

    while (tests-- > 0)
        run_case();

    return 0;
}
