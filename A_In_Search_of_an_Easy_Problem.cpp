#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    int size=0;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]==1) size=1;

    }
    if(size==0) cout<<"EASY";
    else cout<<"HARD";

    
    
    

    

    return 0;

}