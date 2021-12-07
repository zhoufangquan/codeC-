#include<bits/stdc++.h>
using namespace std;

const string numE0[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"}; 
const string numE1[] = {"", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"}; 
const string numE2[] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"}; 

string TNumtoW(int n){  // 三位数的转换
    string ans = "";
    int h = n/100;  // 百位
    int t2 = n%100;  // 后两位
    if(h != 0){
        ans += numE0[h];
        ans += " Hundred";
    }
    if(t2 == 0) return ans;
    ans += " "; //百位和后两位的分割空格
    if(t2%10 == 0){
        ans += numE2[t2/10];
    }
    else if(t2<10){
        ans += numE0[t2];
    }
    else if(t2<20){
        ans += numE1[t2%10];
    }
    else{
        ans += numE2[t2/10];
        ans += " " + numE0[t2%10];
    }

    return ans;
}


string numberToWords(int num){
    if(num == 0) return "Zero";
    string ans = "";
    const int a[] = {1000000000, 1000000, 1000};
    const string b[] = {" Billion", " Million", " Thousand"};
    for(int i=0;i<3;i++){
        int t = num / a[i];
        if(t != 0){
            ans += TNumtoW(t);
            ans += b[i];
            if(num%a[i]) ans += " ";
        }
        num %= a[i];
    }
    if(num != 0){
        ans += TNumtoW(num);
    }
    return ans;
}

int main(){
    int n;

    while(cin>>n){
        cout<<numberToWords(n)<<'\n';
    }

    return 0;
}