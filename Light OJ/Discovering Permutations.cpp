#include <bits/stdc++.h>

using namespace std;

int fact(int x){
	int ans = 1;
	while(x) {
		ans = ans * x;
		x--;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
  cin.tie(0);
	char c;
	int tt;
	int k;
	int n;
	int ok;
	scanf("%d", &tt);
	for (int j = 1; j <= tt; j++) {
		c = 'A';
		string a;
		scanf("%d", &n);
		scanf("%d", &k);
		for (int i = 0; i < n; i++) {
			a = a + c;
			c = c + 1;
		}
		printf("Case %d:\n", j);
		if(n < 5) {
			ok = fact(n);
			if(k < ok) {
				for (int i = 0; i < k; i++) {
					cout << a << endl;
					next_permutation(a.begin(), a.end());
				}
			}
			else {
				if(k >= ok) {
					for (int i = 0; i < ok; i++) {
						cout << a << endl;
						next_permutation(a.begin(), a.end());
					}
				}
			}
		}
		else {
			for (int i = 0; i < k; i++) {
				cout << a << endl;
				next_permutation(a.begin(), a.end());
			}
		}
	}
}
