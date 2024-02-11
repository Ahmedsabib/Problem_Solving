#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef set<int> si;
typedef set<ll> sl;
typedef multiset<int> msi;
typedef multiset<ll> msl;

typedef map<int,int> mpii;
typedef map<ll,ll> mpll;
typedef map<char,int> mpci;
typedef map<char,ll> mpcl;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=1; i<=(a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define REP(i, a, x) for(int i=0; i < (a); i+= x)
#define PER(i, a, b, x) for(int i=a; i < (b); i+=x)
#define REPd(i, a, x) for(int i=(a)-1; i >= 0; i-=x)
#define PERd(i, a, b, x) for(int i=(b)-1; i >= a; i-=x)
#define trav(a, x) for (auto& a : x)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
const int MOD = 1000000007;
const int MX = 100001;


void solve() {
    
    ll a, b; cin >> a >> b;
    ll sum = 0;
    F0R(i, a){
    	sum += i*100*b;
    }
    cout << sum+(a*(b*(b+1)/2)) << '\n';
}
 

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);    
    int T = 1;
    //cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}
