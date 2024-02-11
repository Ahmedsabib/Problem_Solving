#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long x; cin >> x;
	long long v = (x/11)*2;
	x %= 11;
	if(x > 6) ++v;
	if(x > 0) v++;
	cout << v << '\n';
	return 0;
}
