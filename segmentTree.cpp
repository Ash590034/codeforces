#include <bits/stdc++.h>
using namespace std;


vector<int> segTree;

void build(vector<int> &arr,int start,int end,int index){ //O(n)
    if(start==end){
        segTree[index]=arr[start];
        return;
    }
    int mid=(start+end)/2;
    int left=2*index , right=2*index + 1;
    build(arr,start,mid,left);
    build(arr,mid+1,end,right);
    segTree[index]=segTree[left] + segTree[right];
} 
void update(vector<int> &arr,int start,int end,int index,int pos,int val){ //O(logN)
    if(start==end){
        arr[pos]=val;
        segTree[index]=arr[pos];
        return;
    }
    int mid=(start+end)/2;
    if(mid>=pos){
        update(arr,start,mid,2*index,pos,val);
    }
    else{
        update(arr,mid+1,end,2*index+1,pos,val);
    }
    segTree[index]=segTree[2*index] + segTree[2*index+1];
}
int query(int start,int end,int index,int l,int r){ //O(logN)
    if(l<=start && end<=r) return segTree[index];
    if(l>end || r<start) return 0;
    int mid=(start+end)/2;
    return query(start,mid,2*index,l,r) + query(mid+1,end,2*index+1,l,r);
} 
void solve(){
    int n;
    cin>>n;
    segTree.resize(4*n,-1);
    vector<int> arr(n);
    for(auto &it:arr) cin>>it;
    build(arr,0,n-1,1);
    for(auto it:segTree) cout<<it<<" ";
    cout<<endl;
}

int main(){
    solve();
    return 0;
}