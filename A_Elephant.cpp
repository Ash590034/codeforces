#include <bits/stdc++.h>
using namespace std;
int main(){
    int x;
    cin>>x;
    int ans=0;

    while(x){
        if(x>=5){
            ans+=x/5;
            x=x%5;
        }
        else if(x=4){
            ans+=x/4;
            x=x%4;
        }
        else if(x=3){
            ans+=x/5;
            x=x%5;
        }
        else if(x=2){
            ans+=x/5;
            x=x%5;
        }
        else if(x=1){
            ans+=x/5;
            x=x%5;
        }
        
        
        

       
        


    }
    cout<<ans;

    return 0;
}