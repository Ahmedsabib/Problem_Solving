#include <bits/stdc++.h>
using namespace std;

bool check(string a, string b) {
    return (a[0] == b[0]) || (a[1] == b[1]);
}

void run_case() {
    string input;

    while (cin >> input && input != "#") {
        vector<stack<string>> piles(1);
        piles[0].push(input);

        for (int i = 1; i < 52; ++i) {
            cin >> input;

            stack<string> S;
            S.push(input);
            piles.push_back(S);

            bool ok = false;

            do {
                ok = false;

                for (int j = 1; j < (int)piles.size(); ++j) {
                    input = piles[j].top();
                    int cur_ind = j - 1;

                    if (j > 2 && check(input, piles[j-3].top()))
                        cur_ind -= 2;

                    string card = piles[cur_ind].top();

                    if (check(card, input)) {
                        piles[cur_ind].push(input);
                        piles[j].pop();

                        if (piles[j].empty())
                            piles.erase(piles.begin() + j);

                        ok = true;
                        break;
                    }
                }
            } while (ok);
        }

        cout << (int)piles.size() << ' ' << "pile" << ((int)piles.size() == 1?" ": "s ") << "remaining: ";

        for (int i = 0; i < (int)piles.size(); ++i) {
            cout << (int)piles[i].size();

            if (i + 1 != (int)piles.size())
                cout << ' ';
        }

        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int tests = 1;

    while (tests-- > 0)
        run_case();

    return 0;
}
