#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
// struct FenwickTree
// {
//     ll n;
//     vector<ll> bit;
//     FenwickTree(vector<ll> &a) : n(a.size()) , bit(n+1){
//         for(int i=0;i<n;i++) upd(i,a[i]);
//     }
//     void upd(ll i,ll x){
//         for(i++;i<=n;i+=i& -i) bit[i]+=x;
//     }
//     ll sum(ll i){
//         ll s=0;
//         for(i++;i>0;i-=i& -i) s+=bit[i];
//         return s;
//     }
//     int query(int l,int r){
//         return sum(r) - sum(l-1);
//     }
// };


// struct FenwickTree2D{
//     ll n,m;
//     vector<vector<ll>> bit;
//     FenwickTree2D(vector<vector<ll>> &a) : n(a.size()) , m(a[0].size()) ,bit(n+1,vector<ll>(m+1)) {
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 upd(i,j,a[i][j]);
//             }
//         }
//     }
//     void upd(int r,int c,ll x){
//         for(int i=r+1;i<=n;i+=i& -i){
//             for(int j=c+1;j<=m;j+=j& -j){
//                 bit[i][j]+=x;
//             }
//         }
//     } 
//     ll sum(int r,int c){
//         ll s=0;
//         for(int i=r+1;i>0;i-=i& -i){
//             for(int j=c+1;j>0;j-=j& -j){
//                 s+=bit[i][j];
//             }
//         }
//         return s;
//     }
//     ll query(int r1,int c1,int r2,int c2){
//         return sum(r2,c2) - sum(r1-1,c2) - sum(r2,c1-1) + sum(r1-1,c1-1);      
//     }

// };
// int main(){
//     vector<ll> a={1,2,3,4,5,6};
//     FenwickTree ft(a);
//     cout<<ft.query(0,5)<<endl;  
//     return 0;
// }


struct FenwickTree
{
    ll n;
    vector<ll> bit;
    FenwickTree(ll n){
        this->n=n;
        bit=vector<ll>(n+1,0);
    }
    void upd(ll i,ll x){
        for(i++;i<=n;i+=i& -i) bit[i]=max(x,bit[i]);
    }
    ll query(ll r){
        ll mx=0;
        for(r++;r>0;r-=r&-r){
            mx=max(mx,bit[r]);
        }
        return mx;
    }
};