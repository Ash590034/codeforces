int getMinTime(int n, int m, vector <int> cache) {

  map <int, int> mpp;
  for(auto it: cache) mpp[it - 1]++;

  auto check = [&](int mx) {
    vector <int> slot(n, mx);
    int extra = 0;
    for (int i = 0; i < n; i++) {
      int a = min(mx, mpp[i]);
      slot[i] -= a;
      extra += mpp[i] - a;
    }

    for (int i = 0; i < n; i++) {
      int rem = mx - slot[i];
      extra -= (rem / 2);
      if(extra <= 0) return true;
    }
    return false;
  };

  int low = 0, high = 4e5 + 1;
  while(low < high) {
    int mid = low + (high - low) / 2;
    if(check(mid)) high = mid;
    else low = mid + 1;
  }
  return low;
}
int main(){
    vector<int> v={1,2,3,4};
    cout<<getMinTime(4,4,v)<<endl;

    return 0;
}







#include <bits/stdc++.h>
using namespace std;
class  DisjointSet{

    vector<int> size,parent;
    public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            size[i]=1;
            parent[i]=i;
        }

    }
    
    void unionSz(int u,int v){
        int ulp_u=findPar(u);
        int ulp_v=findPar(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        
        }
        else {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        
        }
              
    }
    int findPar(int node){
        if(node==parent[node]) return node;
        return parent[node]=findPar(parent[node]);
    }


};
vector<int> recoverDeadPods(int n,vector<vector<int>> connections,vector<vector<int>> queries){
    DisjointSet ds(n);
    vector<int> ans;
    for(int i=0;i<connections.size();i++){
        int u,v;
        u=connections[i][0];
        v=connections[i][1];
        ds.unionSz(u,v);
    }
    map<int,set<int>> data;
    for(int i=1;i<=n;i++){
        int parent=ds.findPar(i);
        data[parent].insert(i);
    }
    int q;
    q=queries.size();
    for(int i=0;i<q;i++){
        int type,podNo;
        type=queries[i][0];
        podNo=queries[i][1];
        if(type==1){
            int parent=ds.findPar(podNo);
            if(data[parent].size()==0){
                ans.push_back(-1);
            }
            else{
                int val=*(data[parent].begin());
                ans.push_back(val);
            }
        }
        else{
            int parent=ds.findPar(podNo);
            data[parent].erase(podNo);
        }
    }
    return ans;

}
int main(){
    // int pods,n;
    // cin>>pods>>n;
    // DSU ds(pods);
    // for(int i=0;i<n;i++){
    //     int u,v;
    //     cin>>u>>v;
    //     ds.unionSz(u,v);
    // }
    // map<int,set<int>> data;
    // for(int i=1;i<=n;i++){
    //     int par=ds.parent(i);
    //     data[par].insert(i);
    // }
    // int q;
    // cin>>q;
    // for(int i=0;i<q;i++){
    //     int type,podNo;
    //     cin>>type>>podNo;
    //     if(type==1){
    //         int par=ds.parent(podNo);
    //         if(data[par].size()==0){
    //             cout<<-1<<endl;
    //         }
    //         else{
    //             cout<<*(data[par].begin())<<endl;
    //         }
    //     }
    //     else{
    //         int par=ds.parent(podNo);
    //         data[par].erase(podNo);
    //     }
    // }
    vector<vector<int>> c={{1,2},{2,3}};
    vector<vector<int>> q={{2,2},{1,2},{2,1},{2,3},{1,1}};
    vector<int> ans=recoverDeadPods(3,c,q);
    for(auto it:ans) cout<<it<<endl;

    return 0;
}