
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const ll RADIX_1=26;
const ll RADIX_2=27;
const ll MOD_1=1e9+7;
const ll MOD_2=1e9+33;

pair<ll,ll> hashPair(string s,ll n){
    ll hash1=0,hash2=0;
    ll factor1=1,factor2=1;

    for(ll i=n-1;i>=0;i--){
        hash1=((s[i]-'a')*factor1+hash1)%MOD_1;
        hash2=((s[i]-'a')*factor2+hash2)%MOD_2;
        factor1=(factor1*RADIX_1)%MOD_1;
        factor2=(factor2*RADIX_2)%MOD_2;


    }
    return {hash1%MOD_1,hash2%MOD_2};

}


int str(string s,string p){
    ll n=s.size();
    ll m=p.size();

    if(m>n) return -1;

    ll MAXWEIGHT_1=1,MAXWEIGHT_2=1;
    for(ll i=0;i<m;i++){
        MAXWEIGHT_1=(MAXWEIGHT_1*RADIX_1)%MOD_1;
        MAXWEIGHT_2=(MAXWEIGHT_2*RADIX_2)%MOD_2;
    }

    pair<ll,ll> hashP=hashPair(p,m);
    pair<ll,ll> hashS={0,0};

    for(ll i=0;i<=n-m;i++){
        if(i==0){
            hashS=hashPair(s,m);
        }
        else{
            hashS.first=((hashS.first*RADIX_1)%MOD_1
             -((s[i-1]-'a')*MAXWEIGHT_1)%MOD_1
             + (s[i+m-1]-'a') + MOD_1)%MOD_1;

            hashS.second=((hashS.second*RADIX_2)%MOD_2
             -((s[i-1]-'a')*MAXWEIGHT_2)%MOD_2
             + (s[i+m-1]-'a') + MOD_2)%MOD_2;

        }
        if(hashS.first==hashP.first && hashS.second==hashP.second){
            return i;
        }

    }
    return -1;
}

int main(){
    cout<<str("aaaaaaad","aaad");
    return 0;
}

