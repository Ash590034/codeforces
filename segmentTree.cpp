#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define all(x) x.begin() , x.end()

// vector<ll> segTree;
// ll merge(ll a,ll b){
//     return a+b;
// }
// void build(vector<ll> &arr,int start,int end,int index){ //O(n)
//     if(start==end){
//         segTree[index]=arr[start];
//         return;
//     }
//     int mid=(start+end)/2;
//     int left=2*index , right=2*index + 1; // root has index 1
//     build(arr,start,mid,left);
//     build(arr,mid+1,end,right);
//     segTree[index]=merge(segTree[left] , segTree[right]);
// } 
// void update(vector<ll> &arr,int start,int end,int index,int pos,ll val){ //O(logN)
//     if(start==end){
//         arr[pos]=val;
//         segTree[index]=arr[pos];
//         return;
//     }
//     int mid=(start+end)/2;
//     int left=2*index , right=2*index+1;
//     if(mid>=pos){
//         update(arr,start,mid,left,pos,val);
//     }
//     else{
//         update(arr,mid+1,end,right,pos,val);
//     }
//     segTree[index]=merge(segTree[left] , segTree[right]);
// }
// ll query(int start,int end,int index,int l,int r){ //O(logN) //l and r are arr Indexes and start and end are segtree node-ranges 
//     if(l<=start && end<=r) return segTree[index];
//     if(l>end || r<start) return 0;
//     int mid=(start+end)/2;
//     return merge(query(start,mid,2*index,l,r) , query(mid+1,end,2*index+1,l,r));
// } 
// void solve(){
//     int n;
//     cin>>n;
//     segTree.resize(4*n,-1);
//     vector<int> arr(n);
//     for(auto &it:arr) cin>>it;
//     build(arr,0,n-1,1);
//     for(auto it:segTree) cout<<it<<" ";
//     cout<<endl;
// }



// vector<int> segTree , lazy;
// int merge(int a,int b){
//     return min(a,b);
// }
// void build(vector<int> &arr,int start,int end,int index){ //O(n)
//     if(start==end){
//         segTree[index]=arr[start];
//         return;
//     }
//     int mid=(start+end)/2;
//     int left=2*index , right=2*index + 1; // root has index 1
//     build(arr,start,mid,left);
//     build(arr,mid+1,end,right);
//     segTree[index]=merge(segTree[left] , segTree[right]);
// } 
// void propagate(int start,int end,int index){
//     if(start==end){
//         lazy[index]=0;
//         return;
//     }
//     int left=2*index , right=2*index+1;
//     lazy[left]+=lazy[index];
//     lazy[right]+=lazy[index];
//     lazy[index]=0;
// }
// void update(int start,int end,int index,int l,int r,int val){ //O(logN) s and e node ranges l and r query range
//     if(lazy[index]!=0){
//         segTree[index]+=lazy[index];
//         propagate(start,end,index);
//     }
//     if(l<=start && end<=r){
//         segTree[index]+=val;
//         lazy[index]=val;
//         propagate(start,end,index);
//         return;
//     }
//     if(start>r || end<l) return;
//     int mid=(start+end)/2;
//     int left=2*index , right=2*index+1;
//     update(start,mid,left,l,r,val);
//     update(mid+1,end,right,l,r,val);
//     segTree[index]=merge(segTree[left] , segTree[right]);
// }
// int query(int start,int end,int index,int l,int r){ //O(logN) //l and r are arr Indexes and start and end are segtree node-ranges 
//     if(lazy[index]!=0){
//         segTree[index]+=lazy[index];
//         propagate(start,end,index);
//     }
//     if(l<=start && end<=r) return segTree[index];
//     if(l>end || r<start) return INT_MAX;
//     int mid=(start+end)/2;
//     return merge(query(start,mid,2*index,l,r) , query(mid+1,end,2*index+1,l,r));
// } 
// void solve(){
//     int n;
//     cin>>n;
//     segTree.resize(4*n,-1);
//     lazy.resize(4*n,0);
//     vector<int> arr(n);
//     for(auto &it:arr) cin>>it;
//     build(arr,0,n-1,1);
//     update(0,n-1,1,0,1,3);
//     cout<<query(0,n-1,1,0,2)<<endl;
//     for(auto it:segTree) cout<<it<<" ";
//     cout<<endl;
//     for(auto it:lazy) cout<<it<<" ";
//     cout<<endl;
// }

// int main(){
//     solve();
//     return 0;
// }




// template<typename Node, typename Update>
// struct SegTree {
// 	vector<Node> tree;
// 	vector<ll> arr; // type may change
// 	int n;
// 	int s;
// 	SegTree(int a_len, vector<ll> &a) { // change if type updated
// 		arr = a;
// 		n = a_len;
// 		s = 1;
// 		while(s < 2 * n){
// 			s = s << 1;
// 		}
// 		tree.resize(s); fill(all(tree), Node());
// 		build(0, n - 1, 1);
// 	}
// 	void build(int start, int end, int index)  // Never change this
// 	{
// 		if (start == end)	{
// 			tree[index] = Node(arr[start]);
// 			return;
// 		}
// 		int mid = (start + end) / 2;
// 		build(start, mid, 2 * index);
// 		build(mid + 1, end, 2 * index + 1);
// 		tree[index].merge(tree[2 * index], tree[2 * index + 1]);
// 	}
// 	void update(int start, int end, int index, int query_index, Update &u)  // Never Change this
// 	{
// 		if (start == end) {
// 			u.apply(tree[index]);
// 			return;
// 		}
// 		int mid = (start + end) / 2;
// 		if (mid >= query_index)
// 			update(start, mid, 2 * index, query_index, u);
// 		else
// 			update(mid + 1, end, 2 * index + 1, query_index, u);
// 		tree[index].merge(tree[2 * index], tree[2 * index + 1]);
// 	}
// 	Node query(int start, int end, int index, int left, int right) { // Never change this
// 		if (start > right || end < left)
// 			return Node();
// 		if (start >= left && end <= right)
// 			return tree[index];
// 		int mid = (start + end) / 2;
// 		Node l, r, ans;
// 		l = query(start, mid, 2 * index, left, right);
// 		r = query(mid + 1, end, 2 * index + 1, left, right);
// 		ans.merge(l, r);
// 		return ans;
// 	}
// 	void make_update(int index, ll val) {  // pass in as many parameters as required
// 		Update new_update = Update(val); // may change
// 		update(0, n - 1, 1, index, new_update);
// 	}
// 	Node make_query(int left, int right) {
// 		return query(0, n - 1, 1, left, right);
// 	}
// };

// struct Node1 {
// 	ll val; // may change
// 	Node1() { // Identity element
// 		val = 0;	// may change
// 	}
// 	Node1(ll p1) {  // Actual Node
// 		val = p1; // may change
// 	}
// 	void merge(Node1 &l, Node1 &r) { // Merge two child nodes
// 		val = (l.val+r.val);  // may change
// 	}
// };

// struct Update1 {
// 	ll val; // may change
// 	Update1(ll p1) { // Actual Update
// 		val = p1; // may change
// 	}
// 	void apply(Node1 &a) { // apply update to given node
// 		a.val = val; // may change
// 	}
// };
// void solve(){
//     int n;
//     cin>>n;
//     vector<ll> arr(n);
// 	for(int i=0;i<n;i++) cin>>arr[i];
// 	SegTree<Node1,Update1> seg= SegTree<Node1,Update1>(n,arr);
// 	Node1 ans=seg.make_query(0,3);
// 	cout<<ans.val<<endl;
// }

// int main(){
//     solve();
//     return 0;
// }


// template<typename Node, typename Update>
// struct LazySGT {
//     vector<Node> tree;
//     vector<bool> lazy;
//     vector<Update> updates;
//     vector<ll> arr; // type may change
//     int n;
//     int s;
//     LazySGT(int a_len, vector<ll> &a) { // change if type updated
//         arr = a;
//         n = a_len;
//         s = 1;
//         while(s < 2 * n){
//             s = s << 1;
//         }
//         tree.resize(s); fill(all(tree), Node());
//         lazy.resize(s); fill(all(lazy), false);
//         updates.resize(s); fill(all(updates), Update());
//         build(0, n - 1, 1);
//     }
//     void build(int start, int end, int index) { // Never change this
//         if (start == end)   {
//             tree[index] = Node(arr[start]);
//             return;
//         }
//         int mid = (start + end) / 2;
//         build(start, mid, 2 * index);
//         build(mid + 1, end, 2 * index + 1);
//         tree[index].merge(tree[2 * index], tree[2 * index + 1]);
//     }
//     void pushdown(int index, int start, int end){
//         if(lazy[index]){
//             int mid = (start + end) / 2;
//             apply(2 * index, start, mid, updates[index]);
//             apply(2 * index + 1, mid + 1, end, updates[index]);
//             updates[index] = Update();
//             lazy[index] = 0;
//         }
//     }
//     void apply(int index, int start, int end, Update& u){
//         if(start != end){
//             lazy[index] = 1;
//             updates[index].combine(u, start, end);
//         }
//         u.apply(tree[index], start, end);
//     }
//     void update(int start, int end, int index, int left, int right, Update& u) {  // Never Change this
//         if(start > right || end < left)
//             return;
//         if(start >= left && end <= right){
//             apply(index, start, end, u);
//             return;
//         }
//         pushdown(index, start, end);
//         int mid = (start + end) / 2;
//         update(start, mid, 2 * index, left, right, u);
//         update(mid + 1, end, 2 * index + 1, left, right, u);
//         tree[index].merge(tree[2 * index], tree[2 * index + 1]);
//     }
//     Node query(int start, int end, int index, int left, int right) { // Never change this
//         if (start > right || end < left)
//             return Node();
//         if (start >= left && end <= right){
//             pushdown(index, start, end);
//             return tree[index];
//         }
//         pushdown(index, start, end);
//         int mid = (start + end) / 2;
//         Node l, r, ans;
//         l = query(start, mid, 2 * index, left, right);
//         r = query(mid + 1, end, 2 * index + 1, left, right);
//         ans.merge(l, r);
//         return ans;
//     }
//     void make_update(int left, int right, ll val) {  // pass in as many parameters as required
//         Update new_update = Update(val); // may change
//         update(0, n - 1, 1, left, right, new_update);
//     }
//     Node make_query(int left, int right) {
//         return query(0, n - 1, 1, left, right);
//     }
// };

// struct Node1 {
//     ll val; // may change
//     Node1() { // Identity element
//         val = 0;    // may change
//     }
//     Node1(ll p1) {  // Actual Node
//         val = p1; // may change
//     }
//     void merge(Node1 &l, Node1 &r) { // Merge two child nodes
//         val = l.val + r.val;  // may change
//     }
// };

// struct Update1 {
//     ll val; // may change
//     Update1(){ // Identity update
//         val = -1;
//     }
//     Update1(ll val1) { // Actual Update
//         val = val1;
//     }
//     void apply(Node1 &a, int start, int end) { // apply update to given node
//         if(val==-1) return;
//         a.val = val * (end - start + 1); // may change
//     }
//     void combine(Update1& new_update, int start, int end){
//         if(val==-1)  val=new_update.val;
//         else val = new_update.val;
//     }
// };    

