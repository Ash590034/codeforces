#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    int size=0;

    
    
    do{ n++;
        set <int> st;
        int c=n;
        for(int i=0;i<4;i++){
            st.insert(c%10);
            c=c/10;
        }
        size=st.size();
    } while (size!=4);

    cout<<n;

    

    return 0;

}