#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string S; cin >> S;
	sort(S.begin(), S.end());
	vector<string>Arr;
	do{
		Arr.push_back(S);
	}while(next_permutation(S.begin(), S.end()));
	cout << Arr.size() << '\n';
	for(string x: Arr){
		cout << x << '\n';
	}
	return 0;
}
