#include<bits/stdc++.h>
using namespace std;

int main(){
    string S; cin>>S;
    string ansMax = "", ansMin = "";
    int n = S.length();
    for(int i=0;i<n;i++) ansMax += 'a';
    for(int i=0;i<n;i++) ansMin += 'z';
    for(int i=0;i<n;i++){
        string t = "";
        t += S.substr(i);
        t += S.substr(0, i);
        if(t < ansMin) ansMin = t;
        if(t > ansMax) ansMax = t;
        // cout<<t<<'\n';
    }
    cout<<ansMin<<'\n';
    cout<<ansMax<<'\n';
    return 0;
}