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

bool check(vl &arr){
    int n=arr.size();
    for(ll i=0;i<n;i++){
        for(ll j=i;j<n;j+=(i+1)){
            int ind=(i^j);
            if(arr[ind]!=(arr[i]^arr[j])) return 0;
        }
    }
    return 1;
}
void solve()
{
    ll n;
    cin>>n;
    vl arr((1<<n));
    cin>>arr;
    // vl sorted=arr;
    // sort(all(sorted));
    // for(int i=0;i<(1<<n);i++){
    //     if(sorted[i]!=i){
    //         pn;
    //         return;
    //     }
    // }
    if(check(arr)) py;
    else pn;
    // for(int i=0;i<(1<<n);i++) arr.pb(i);
    // ll ans=0;
    // do{
    //     if(check(arr)) {
    //         cout<<arr<<endl;
    //         ans++;
    //     }
    // }
    // while(next_permutation(all(arr)));
    // cout<<ans<<endl;
    
}

int32_t main()
{
    fastio()
    #ifndef ONLINE_JUDGE
        freopen("Error.txt","w",stderr);
    #endif
    
    int t=1;
    cin>>t;
    while(t--)
    {
    solve();
    }
    return 0;  
}