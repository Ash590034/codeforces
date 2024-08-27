
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
#define foreach(i, j, k, in) for(int i=j;i<k;i+=in)
#define rforeach(i, j, k, in) for(int i=j;i>=k;i-=in)
#define rep(i,j) foreach(i,0,j,1)
#define rrep(i,j) rforeach(i,j,0,1)
#define set_bits(x) __builtin_popcountll(x)
#define zero_bits(x) __builtin_ctzll(x)
#define sz(s) (int)(s.size())
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define inint(x) int x; cin>>x;
#define inll(x) long long int x; cin>>x;
#define instr(x) string x; cin>>x;
#define all(x) x.begin(), x.end()
#define os(x) cout << x << " ";
#define out(x) cout << x << endl;
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))
#define SUM(x) accumulate(all(x), 0LL)
#define COUNT(x,u) count(all(x), u)
#define B break
#define C continue
#define py cout<<"YES"<<endl
#define pn cout<<"NO"<<endl
#define pm cout<<"-1"<<endl
#define ps(x,y) fixed<<setprecision(y)<<x
#define endl '\n'

//Typedef
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
typedef set<int> st;
typedef priority_queue<ll> pqll;

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

//Sorting
bool sorta(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}
bool sortd(const pair<int,int> &a,const pair<int,int> &b){return (a.second > b.second);}

//Bits
string decToBinary(int n){string s="";int i = 0;while (n > 0) {s =to_string(n % 2)+s;n = n / 2;i++;}return s;}
ll binaryToDecimal(string n){string num = n;ll dec_value = 0;int base = 1;int len = num.length();for(int i = len - 1; i >= 0; i--){if (num[i] == '1')dec_value += base;base = base * 2;}return dec_value;}

//Check
bool isPrime(ll n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(int i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
bool isPowerOfTwo(int n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}
bool isPerfectSquare(ll x){if (x >= 0) {ll sr = sqrt(x);return (sr * sr == x);}return false;}

//Constants
vector <ll> primes;
vector <bool> is_prime;
// Mathematical functions
void Sieve(int n){ is_prime.assign(n + 1, true); is_prime[0] = is_prime[1] = false; for(ll i = 2; i * i <= n; i++) if(is_prime[i]) for(ll j = i * i; j <= n; j += i) is_prime[j] = false;}
void get_primes(int n){ for(int i = 2; i <= n; i++)  if(is_prime[i])  primes.push_back(i); }
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);} //__gcd 
ll lcm(ll a, ll b){return (a/gcd(a,b)*b);}
ll moduloMultiplication(ll a,ll b,ll mod){ll res = 0;a %= mod;while (b){if (b & 1)res = (res + a) % mod;b >>= 1;}return res;}
ll powermod(ll x, ll y, ll p){ll res = 1;x = x % p;if (x == 0) return 0;while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}
ll modinv(ll p,ll q){ll ex;ex=M-2;while (ex) {if (ex & 1) {p = (p * q) % M;}q = (q * q) % M;ex>>= 1;}return p;}
vector<ll> getBin(ll a){
    vector<ll> ans(64,0);
    for(ll i=0;i<64;i++) ans[i]=((a>>i)&1LL);
    return ans;
}
void solve()
{
    ll n;
    cin>>n;
    vl a(n) ,b(n) , c(n);
    cin>>a>>b>>c;
    for(int i=1;i<n;i++){
        a[i]+=a[i-1];
        b[i]+=b[i-1];
        c[i]+=c[i-1];
    }
    ll reqVal=(a[n-1]+2)/3;
    ll lba=n , lbb=n , lbc=n;
    //abc 
    lba=lower_bound(all(a),reqVal)-a.begin();
    lbb=lower_bound(all(b),reqVal+b[lba])-b.begin();
    if(lbb<n) lbc=lower_bound(all(c),reqVal+c[lbb])-c.begin();
    if(lba!=n && lbb!=n && lbc!=n){
        cout<<1<<" "<<lba+1<<" "<<lba+2<<" "<<lbb+1<<" "<<lbb+2<<" "<<n<<endl;
        return;
    }
    lba=n , lbb=n , lbc=n;
    //acb
    lba=lower_bound(all(a),reqVal)-a.begin();
    lbc=lower_bound(all(c),reqVal+c[lba])-c.begin();
    if(lbc<n) lbb=lower_bound(all(b),reqVal+b[lbc])-b.begin();
    if(lba!=n && lbb!=n && lbc!=n){
        cout<<1<<" "<<lba+1<<" "<<lbc+2<<" "<<n<<" "<<lba+2<<" "<<lbc+1<<endl;
        return;
    }
    lba=n , lbb=n , lbc=n;
    //bac
    lbb=lower_bound(all(b),reqVal)-b.begin();
    lba=lower_bound(all(a),reqVal+a[lbb])-a.begin();
    if(lba<n) lbc=lower_bound(all(c),reqVal+c[lba])-c.begin();
    if(lba!=n && lbb!=n && lbc!=n){
        cout<<lbb+2<<" "<<lba+1<<" "<<1<<" "<<lbb+1<<" "<<lba+2<<" "<<n<<endl;
        return;
    }
    lba=n , lbb=n , lbc=n;
    //bca
    lbb=lower_bound(all(b),reqVal)-b.begin();
    lbc=lower_bound(all(c),reqVal+c[lbb])-c.begin();
    if(lbc<n) lba=lower_bound(all(a),reqVal+a[lbc])-a.begin();
    if(lba!=n && lbb!=n && lbc!=n){
        cout<<lbc+2<<" "<<n<<" "<<1<<" "<<lbb+1<<" "<<lbb+2<<" "<<lbc+1<<endl;
        return;
    }
    lba=n , lbb=n , lbc=n;
    //cab
    lbc=lower_bound(all(c),reqVal)-c.begin();
    lba=lower_bound(all(a),reqVal+a[lbc])-a.begin();
    if(lba<n) lbb=lower_bound(all(b),reqVal+b[lba])-b.begin();
    if(lba!=n && lbb!=n && lbc!=n){
        cout<<lbc+2<<" "<<lba+1<<" "<<lba+2<<" "<<n<<" "<<1<<" "<<lbc+1<<endl;
        return;
    }
    lba=n , lbb=n , lbc=n;
    //cba
    lbc=lower_bound(all(c),reqVal)-c.begin();
    lbb=lower_bound(all(b),reqVal+b[lbc])-b.begin();
    if(lbb<n) lba=lower_bound(all(a),reqVal+a[lbb])-a.begin();
    if(lba!=n && lbb!=n && lbc!=n){
        cout<<lbb+2<<" "<<n<<" "<<lbc+2<<" "<<lbb+1<<" "<<1<<" "<<lbc+1<<endl;
        return;
    }
    cout<<-1<<endl;
    
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

