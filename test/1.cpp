#include<bits/stdc++.h>
using namespace std;
bool q3(int i, string &s);
bool q2(int i, string &s);
bool q1(int i, string &s);
bool q0(int i, string &s);

bool q3(int i, string &s){
    if(i == s.length()) return true;
    else return q3(i+1, s);
}
bool q2(int i, string &s){
    if(i>=s.length()) return false;
    if(s[i] == '1'){
        return q0(i+1, s);
    }
    else{
        return q3(i+1, s);
    }
}
bool q1(int i, string &s){
    if(i>=s.length()) return false;
    if(s[i] == '1'){
        return q0(i+1, s);
    }
    else{
        return q2(i+1, s);
    }
}

bool q0(int i, string &s){
    if(i>=s.length()) return false;
    if(s[i] == '1'){
        return q0(i+1, s);
    }
    else{
       return q1(i+1, s);
    }
}


int main(){
    cout<<"ÇëÊäÈëÒ»¸ö01´®£º";
    string s;cin>>s;
    int n = s.size();
    cout<<q0(0, s)<<'\n';
    cout<<s;
    return 0; 
}