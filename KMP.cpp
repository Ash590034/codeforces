#include<bits/stdc++.h>
using namespace std;

void kmp(string &t,string &p,vector<int> &ans){
        string s=p+'#'+t;
        vector<int> lps(s.size(), 0);

        for(int i=1;i<lps.size();i++){
            int prev_idx = lps[i-1];

            while(prev_idx>0 && s[i] != s[prev_idx]){
                prev_idx = lps[prev_idx-1];
            }

            lps[i] = prev_idx + (s[i]==s[prev_idx] ? 1 : 0);
            if(lps[i]==p.size()) ans.push_back(i-2*p.size());
        }

        return;
}




int main(){
    
    vector<int> arr;
    string t="isawsquirrelnearmysquirrelhouseohmy";
    string p="my";
    kmp(t,p,arr);
    for (auto it:arr) cout<<it<<" ";

    return 0;



}