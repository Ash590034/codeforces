#include <bits/stdc++.h>
using namespace std;

int main(){

    int n,h;
    cin>>n>>h;
    int arr[n];
    int w=n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]>h) w++;

    }
    cout<<w;

    

    return 0;

}