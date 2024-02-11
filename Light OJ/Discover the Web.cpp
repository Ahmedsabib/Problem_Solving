#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int T; cin >> T;
    
    for (int TC = 1; TC <= T; ++TC) {
        string A, current;
        stack<string> back, forword;

        forword.push("http://www.lightoj.com/");
        
        cout << "Case " << TC << ':' << '\n';

        while(1) {
            
            cin >> A;

            string B;
            
            if (A == "VISIT") {
                cin >> B;

                if (forword.empty()) {
                    cout << "Ignored" << '\n';
                }
                else {
                    current = forword.top();
                    back.push(current);
                    
                    while (!forword.empty())
                        forword.pop();

                    forword.push(B);

                    cout << forword.top() << '\n';
                }
            }
            else if (A == "BACK") {
                if (back.empty()) {
                    cout << "Ignored" << '\n';
                }
                else {
                    current = back.top();
                    forword.push(current);
                    back.pop();
                    cout << forword.top() << '\n';
                }
            }
            else if (A == "FORWARD") {
                if (forword.size() < 2) {
                    cout << "Ignored" << '\n';
                }
                else {
                    current = forword.top();
                    back.push(current);
                    forword.pop();
                    cout << forword.top() << '\n';
                }
            }
            else if (A == "QUIT") {
                break;
            }
        }
    }
    
    return 0;
}
