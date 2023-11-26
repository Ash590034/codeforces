#include <bits/stdc++.h>
using namespace std;
int main (){
    char num[20];
    cin>>num;
    long long digits=strlen(num);
    long long ans=(1<<digits)-2;
    for(long long i=digits-1,count=0;i>=0;i--,count++){
        if(num[i]=='7'){
            ans+=(1<<count);
        }
    }
    cout<<ans+1;

    return 0;
}