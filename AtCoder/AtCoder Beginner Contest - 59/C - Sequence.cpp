#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
 
 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

void run_case(){

	long long N; cin >> N;
	vector<int> A(N);
	for(auto &x: A){
		cin >> x;
	}
	long long res1 = 0, res2 = 0;
	long long sum1 = 0, sum2 = 0;
	for(int i = 0; i < N; ++i){
		sum1 += A[i];
		sum2 += A[i];
		if(i%2 == 0){
			if(sum1 <= 0){
				res1 += -sum1 + 1;
				sum1 = 1;
			}
			if(sum2 >= 0){
				res2 += sum2 + 1;
				sum2 = -1;
			}
		} else{
			if(sum1 >= 0){
				res1 += sum1 + 1;
				sum1 = -1;
			}
			if(sum2 <= 0){
				res2 += -sum2+1;
				sum2 = 1;
			}
		}

	}
	cout << min(res1, res2) << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();

    return 0;
}
