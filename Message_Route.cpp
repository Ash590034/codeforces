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


void solve()
{
    ll n,m;
    cin>>n>>m;
    vvl adj(n+1);
    for(int i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    vl prev(n+1,-1);
    prev[1]=1;
    ll dist=1;
    queue<ll> q;
    q.push(1);
    while(!q.empty()){
        ll sz=q.size();
        bool f=0;
        while(sz--){
            ll node=q.front();
            q.pop();
            if(node==n) {
                f=1;
                break;
            }
            for(auto it:adj[node]){
                if(prev[it]==-1){
                    prev[it]=node;
                    q.push(it);
                }
            }
        }
        if(f) break;
        dist++;
    }
    if(prev[n]==-1){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    else{
        cout<<dist<<endl;
        vl ans;
        ll node=n;
        prev[1]=-1;
        while(node!=-1){
            ans.pb(node);
            node=prev[node];
        }
        for(int i=dist-1;i>=0;i--) cout<<ans[i]<<" ";
        cout<<endl;
    }

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
