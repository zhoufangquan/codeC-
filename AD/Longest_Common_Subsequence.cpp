#include<bits/stdc++.h>

using namespace std;

int main(){
    string s, t;
    cin>>s>>t;
    int len_s = s.length(), len_t = t.length();

    vector<vector<int> > dp;
    vector<vector<int> > path;
    for(int i=0; i<len_s+1;i++){
        vector<int> temp(len_t+1, 0);
        dp.push_back(temp);
        path.push_back(temp);
    }
    // 设置边界的值
    for(int i=0;i<len_s+1;i++) dp[i][0]=0;
    for(int i=0;i<len_t+1;i++) dp[0][i]=0;

    for(int i=1;i<=len_s;i++){
        for(int j=1;j<=len_t;j++){
            if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    
    cout<<"output the value of dp matrix:"<<'\n';
    for(int i=0;i<len_t+1;i++){
        if (i==0) cout<<"    ";
        else cout<<t[i-1]<<' ';
    } 
    cout<<'\n';
    int i=-1, j;
    for(auto &a:dp){
        if(i == -1)i++, cout<<"  ";
        else cout<<s[i++]<<' ';
        for(int &item: a){
            cout<<item<<' ';
        }
        cout<<'\n';
    }

    cout<<"length of the longest common subsequence is:"<<dp[len_s][len_t]<<'\n';

    cout<<"the longest common subsequence is: "<<'\n';
    i = len_s, j = len_t;
    string lcs = "";
    while(i>0 && j>0){
        if(dp[i][j] == dp[i-1][j-1]+1 && s[i-1] == t[j-1]){
            lcs += s[i-1];
            i--, j--;
        }
        else if(dp[i][j] == dp[i-1][j]) i--;
        else if(dp[i][j] == dp[i][j-1]) j--;
    }
    reverse(lcs.begin(), lcs.end());

    cout<<lcs;

    return 0;
}