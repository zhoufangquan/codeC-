#include<bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor) {
    if(divisor == 1) return dividend;
    if(divisor == -1 && dividend == -2147483648) return 2147483647;
    else if(divisor == -1) return -dividend;
    
    long long ans = 0;
    long long add = 1;
    long long dend = abs(dividend);
    long long dsor = abs(divisor);
    long long t = dsor; int i=1;
    while(dend > t && i<=30){
            t = t<<1;
            add = add<<1; i++;
    }
    while(dend >= dsor){
        if(dend >= t){
            ans = ans | add;
            dend -= t;
        }
        t = t>>1;
        add = add>>1;
    }
    if((divisor<0 && dividend<0) || (dividend>0&&divisor>0)) return ans;
    return -ans;
}
int main(){

    int dividend;
    int divisor;
    while(cin>>dividend>>divisor){
        cout<<divide(dividend, divisor)<<'\n';
    }

    return 0;
}