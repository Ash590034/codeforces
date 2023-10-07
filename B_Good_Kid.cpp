#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int s;
        cin>>s;
        int arr[s];
        int mini=INT_MAX;
        int index=-1;

        for(int i=0;i<s;i++){
            cin>>arr[i];
           if(arr[i]<mini){
            mini=arr[i];
            index=i;
           }
        }
        arr[index]++;
        int prod=1;
        for(int i=0;i<s;i++){
            prod=prod*arr[i];
            
        }
        cout<<prod<<endl;


        

        
    }

    return 0;

}
