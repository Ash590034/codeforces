#include <bits/stdc++.h>
using namespace std;
string dangSitu(string s){
    int n=s.size();
    int count=0;
    char el=s[0];
    for(int i=0;i<n;i++){
        if(s[i]==el){
            count++;
            if(count>=7) return "YES";
        }
        else{
            el=s[i];
            count=1;

        }


    }
    return "NO";


}
int main(){
    string s;
    cin>>s;
    cout<<dangSitu(s);

    return 0;

}