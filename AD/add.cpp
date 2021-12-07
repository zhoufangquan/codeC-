#include<bits/stdc++.h>
using namespace std;

string add(string &a, string &b){
    string ans;
    int na = a.size();
    int nb = b.size();
    int i = na-1, j=nb-1;
    int c = 0;
    while(i>=0 || j>=0){
        int t = c;
        if(i>=0) {t += a[i]-'0'; i --;}
        if(j>=0) {t += b[j]-'0'; j --;}
        ans += t%10+'0';
        c = t/10;
    }
    if(c) ans += '0'+c;
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    string a, b;
    while(cin>>a>>b){
        cout<<add(a, b)<<'\n';
        cout<<"press Ctrl+C to end the program.\n";
    }
    return 0;
}