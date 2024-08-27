// #include <bits/stdc++.h>
// using namespace std;

// //Speed
// #define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

// //Macros
// #define IOtext freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
// #define PI (3.141592653589)
// #define M 1000000007
// #define pb push_back
// #define f first
// #define s second
// #define set_bits(x) __builtin_popcountll(x)
// #define zero_bits(x) __builtin_ctzll(x)
// #define sz(s) (int)(s.size())
// #define digCnt(n) ((int)log10(n) + 1)
// #define all(x) x.begin(), x.end()
// #define MAX(x) *max_element(all(x))
// #define MIN(x) *min_element(all(x))
// #define SUM(x) accumulate(all(x), 0LL)
// #define B break
// #define C continue
// #define py cout<<"YES"<<endl
// #define pn cout<<"NO"<<endl
// #define pm cout<<"-1"<<endl
// #define ps(x,y) fixed<<setprecision(y)<<x
// #define endl '\n'

// typedef long long ll;
// typedef unsigned long long ull;
// typedef long double lld;
// typedef pair<int, int> pi;
// typedef pair<ll, ll> pl;
// typedef vector<int> vi;
// typedef vector<ll> vl;
// typedef vector<pi> vpi;
// typedef vector<pl> vpl;
// typedef vector<vi> vvi;
// typedef vector<vl> vvl;
// typedef map<int,int> mii;
// typedef map<ll,ll> mll;
// typedef set<int> seti;
// typedef set<ll> setll;
// typedef priority_queue<ll> pqll;
// typedef priority_queue<ll,vl,greater<ll>> pqllmn;

// #ifndef ONLINE_JUDGE
// #define debug(x) cerr<<#x<<" ";_print(x); cerr<<endl;
// #else
// #define debug(x)
// #endif

// void _print(ll t) {cerr << t;}
// void _print(int t) {cerr << t;}
// void _print(string t) {cerr << t;}
// void _print(char t) {cerr << t;}
// void _print(double t) {cerr << t;}

// // Operator overloads
// template<typename T> // cin >> vector<T>
// istream& operator>>(istream &istream, vector<T> &v){for (auto &it : v)cin >> it;return istream;}
// template<typename T> // cout << vector<T>
// ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }
// template<typename T, typename V> // cout << map<T,T>
// ostream& operator<<(ostream &ostream, const map<T,V> &c) { for (auto &it : c) cout << it.first << " " << it.second<<endl; return ostream; }


// void solve()
// {
//     ll n,m;
//     cin>>n>>m;
//     pl start,end;
//     vector<vector<char>> arr(n,vector<char>(m));
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cin>>arr[i][j];
//             if(arr[i][j]=='A'){
//                 start={i,j};
//             }
//             if(arr[i][j]=='B'){
//                 end={i,j};
//             }
//         }
//     }
//     int dx[4]={-1,0,1,0};
//     int dy[4]={0,1,0,-1};
//     vvl distFromA(n,vl(m,1e8)) , distFromB(n,vl(m,1e8));
//     function<void(ll,ll,ll)> bfs=[&](ll isA,ll i,ll j){
//         if(isA){
//             distFromA[i][j]=0;
//         }
//         else{
//             distFromB[i][j]=0;
//         }
//         queue<pl> q;
//         q.push({i,j});
//         while(!q.empty()){
//             ll sz=q.size();
//             while(sz--){
//                 auto [x,y]=q.front();
//                 q.pop();
//                 for(int k=0;k<4;k++){
//                     ll nr=x+dx[k];
//                     ll nc=y+dy[k];
//                     if(nr>=0 && nc>=0 && nr<n && nc<m && arr[nr][nc]!='#'){
//                         if(isA){
//                             if(distFromA[nr][nc]==1e8){
//                                 distFromA[nr][nc]=distFromA[x][y]+1;
//                                 q.push({nr,nc});
//                             }
//                         }
//                         else{
//                             if(distFromB[nr][nc]==1e8){
//                                 distFromB[nr][nc]=distFromB[x][y]+1;
//                                 q.push({nr,nc});
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//     };
//     bfs(1,start.f,start.s);
//     bfs(0,end.f,end.s);
//     // for(int i=0;i<n;i++){
//     //     for(int j=0;j<m;j++) cout<<distFromA[i][j]<<" ";
//     //     cout<<endl;
//     // }
//     // for(int i=0;i<n;i++){
//     //     for(int j=0;j<m;j++) cout<<distFromB[i][j]<<" ";
//     //     cout<<endl;
//     // }
//     if(distFromA[end.f][end.s]==1e8){
//         pn;
//         return;
//     }
//     else{
//         py;
//         ll minDist=distFromA[end.f][end.s];
//         cout<<minDist<<endl;
//         string ans="";
//         vector<char> hash={'U','R','D','L'};
//         pl curr=start;
//         while(curr.f!=end.f && curr.s!=end.s){
//             for(int k=0;k<4;k++){
//                 ll nr=curr.f+dx[k];
//                 ll nc=curr.s+dy[k];
//                 if(nr>=0 && nc>=0 && nr<n && nc<m && arr[nr][nc]!='#' && distFromA[nr][nc]+distFromB[nr][nc]==minDist){
//                         curr.f=nr;
//                         curr.s=nc;
//                         ans.pb(hash[k]);
//                         break;
//                 }
//             }
//         }
//         cout<<ans<<endl;
//     }

// }

// int32_t main()
// {
//     fastio()
//     #ifndef ONLINE_JUDGE
//         freopen("Error.txt","w",stderr);
//     #endif
    
//     int t=1;
//     //cin>>t;
//     while(t--)
//     {
//     solve();
//     }
//     return 0;  
// }
#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>
#define f first
#define s second
#define mp make_pair

int n, m;
char A[1000][1000];
bool vis[1000][1000];

// previousStep stores the previous direction that we moved in to arrive that
// this cell
int previousStep[1000][1000];

// 0 = up, 1 = right, 2 = down, 3 = left
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
string stepDir = "URDL";

int main() {
	cin >> n >> m;

	queue<ii> q;
	ii begin, end;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> A[i][j];
			if (A[i][j] == 'A') {
				begin = mp(i, j);
			} else if (A[i][j] == 'B') {
				end = mp(i, j);
			}
		}
	}

	q.push(begin);
	vis[begin.f][begin.s] = true;

	while (!q.empty()) {
		ii u = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			ii v = mp(u.f + dx[i], u.s + dy[i]);
			if (v.f < 0 || v.f >= n || v.s < 0 || v.s >= m) continue;
			if (A[v.f][v.s] == '#') continue;
			if (vis[v.f][v.s]) continue;
			vis[v.f][v.s] = true;
			previousStep[v.f][v.s] = i;
			q.push(v);
		}
	}

	if (vis[end.f][end.s]) {
		cout << "YES" << endl;
		vector<int> steps;
		while (end != begin) {
			int p = previousStep[end.f][end.s];
			steps.push_back(p);
			// undo the previous step to get back to the previous square
			// Notice how we subtract dx/dy, whereas we added dx/dy before
			end = mp(end.f - dx[p], end.s - dy[p]);
		}
		reverse(steps.begin(), steps.end());

		cout << steps.size() << endl;
		for (int c : steps) { cout << stepDir[c]; }
		cout << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}