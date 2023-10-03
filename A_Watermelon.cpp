#include <bits/stdc++.h>
using namespace std;
string func(int w){
    if(w%2==0) return "YES";
    return "NO";
}
int main(){
    int weight;
    cin>>weight;
    cout<<func(weight);
    
    return 0;
}