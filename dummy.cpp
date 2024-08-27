#include <bits/stdc++.h>
using namespace std;

//Speed
#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

//Macros
#define IOtext freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define PI (3.141592653589)
#define M 1000000007
#define pb push_back
#define f first
#define s second
#define set_bits(x) __builtin_popcountll(x)
#define zero_bits(x) __builtin_ctzll(x)
#define sz(s) (int)(s.size())
#define digCnt(n) ((int)log10(n) + 1)
#define all(x) x.begin(), x.end()
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))
#define SUM(x) accumulate(all(x), 0LL)
#define B break
#define C continue
#define py cout<<"YES"<<endl
#define pn cout<<"NO"<<endl
#define pm cout<<"-1"<<endl
#define ps(x,y) fixed<<setprecision(y)<<x
#define endl '\n'

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef map<int,int> mii;
typedef map<ll,ll> mll;
typedef set<int> seti;
typedef set<ll> setll;
typedef priority_queue<ll> pqll;
typedef priority_queue<ll,vl,greater<ll>> pqllmn;

#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" ";_print(x); cerr<<endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

// Operator overloads
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v){for (auto &it : v)cin >> it;return istream;}
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }
template<typename T, typename V> // cout << map<T,T>
ostream& operator<<(ostream &ostream, const map<T,V> &c) { for (auto &it : c) cout << it.first << " " << it.second<<endl; return ostream; }
const int mod=1e9+7;
    long long binModExp(long long base, long long exp, long long mod) {
        long long result = 1;
        base = base % mod; // Take modulo initially to prevent overflow

        while (exp > 0) {
            // If exp is odd, multiply the base with the result
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            // Now exp must be even, divide it by 2
            exp = exp >> 1;
            // Square the base
            base = (base * base) % mod;
        }

        return result;
    }
void solve()
{
    // cout<<((161209470)*binModExp(39846,56851412,M))%M<<endl;
    // ll b=161209470;
    // ll k=56851412;
    // ll m=39846;
    // for(int i=0;i<k;i++) b=((b%mod)*m)%mod;
    // cout<<b%mod<<endl;
    ll b=1;
    ll bb=1;
    for(int i=0;i<10;i++){
        cout<<b<<" "<<i<<endl;
        b=b*2;
        bb*=2;
        b%=5;
        cout<<b<<" "<<i<<endl;
    }
    cout<<b<<" "<<bb<<endl;
    //cout<<((int)pow(2,10))%5<<endl;
}

int32_t main()
{
    fastio()
    #ifndef ONLINE_JUDGE
        freopen("Error.txt","w",stderr);
    #endif
    
    int t=1;
    //cin>>t;
    while(t--)
    {
    solve();
    }
    return 0;  
}
