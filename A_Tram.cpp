#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int maxi=0;
    int p=0;




    while(n--){
        int exit,entry;
        cin>>exit>>entry;
        p-=exit;
        p+=entry;
        maxi=max(maxi,p);
        
       

       
        


    }
    cout<<maxi;

    return 0;
}