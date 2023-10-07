#include <bits/stdc++.h>
using namespace std;
int lucky(int n){
    while(n){
        if(n%10!=7 || n%10!=4) return 0;
        n/=10;
    }
    return 1;


    


}
int nearlyLucky(int n){
    if(n%4==0 || n%7==0 || n%44==0 || n%47==0 || n%74==0 || n%77==0 || n%444==0 || n%447==0 ||n%474==0 || n%477==0 ) return 1;
    return 0;

}
int main(){
    int n;
    cin>>n;
    if(lucky(n) || nearlyLucky(n)) cout<<"YES";
    else cout<<"NO";

    return 0;

}