#include<bits/stdc++.h>
using namespace std;


int main(){
    
    int n, p;
    cin>>n>>p;
    int ans = 0;
    for(int i=0;i<n;i++){
        int t;cin>>t;
        if(t>=p) ans ++;
    }

    cout<<(n-ans);
    return 0;
}