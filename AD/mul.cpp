/*
两个长度为n
*/

#include<bits/stdc++.h>
using namespace std;

string i_s(int n){
    string ans = "";
    while(n){
        ans += n%10+'0';
        n/=10;
    }
    reverse(ans.begin(), ans.end());
    if(ans.length() == 0) return "0";
    else return ans;
}

bool IsZero(string s){
    for(int i=0;i<s.length();i++){
        if(s[i] != '0') return false;
    }
    return true;
}

string BigNumberAdd(string a, string b){
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

string FillZero(string x, int n){
    string ans = "";
    if(IsZero(x)) return "0";
    ans += x;
    for(int i=0;i<n;i++) ans += "0";
    return ans;
}

string BigNumberMul(string x, string y){
    int nx = x.length(), ny = y.length();
    if(nx == 0 || ny == 0) return "0";
    if(nx == 1 && ny == 1){
        int a = x[0]-'0';
        int b = y[0]-'0';
        return i_s(a*b);
    }
    int na = nx/2, nb = nx-na;
    string a = x.substr(0, na); 
    string b = x.substr(na, nb);
    int nc = ny/2, nd = ny-nc;
    string c = y.substr(0, nc);
    string d = y.substr(nc, nd);

    string ac = BigNumberMul(a, c);
    string ad = BigNumberMul(a, d);
    string bc = BigNumberMul(b, c);
    string bd = BigNumberMul(b, d);

    string s1 = FillZero(ac, nb+nd);
    string s2 = FillZero(ad, nb);
    string s3 = FillZero(bc, nd);
    string s4 = BigNumberAdd(s1, s2);
    string s5 = BigNumberAdd(s3, bd);

    return BigNumberAdd( BigNumberAdd(FillZero(ac, nb+nd), FillZero(ad, nb)), 
                         BigNumberAdd(FillZero(bc, nd), bd) );
}

int main(){
    string a, b;
    while(cin>>a>>b){
        cout<<BigNumberMul(a, b)<<'\n';
        cout<<"press Ctrl+C to end the program.\n";
    }
    // string s = "sd";
    // cout<<" "+s;
    return 0;
}

/*
"123456789"
"987654321"

"3876620623801494171"
"6529364523802684779"
*/