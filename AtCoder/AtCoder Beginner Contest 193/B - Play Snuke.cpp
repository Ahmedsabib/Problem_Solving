#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long N; cin >> N;
	vector<int>Arr;
	double A[N], P[N], X[N];
	for(int i = 0; i < N; ++i){
	 cin >> A[i] >> P[i] >> X[i];
	 if((A[i]+0.5) <= X[i]) Arr.push_back(P[i]);
	}
	if(!Arr.empty()){
	 int mn = *min_element(Arr.begin(), Arr.end());
	 cout << mn << '\n';
	}
	else{
	 cout << -1 << '\n';
	}
	return 0;
}
