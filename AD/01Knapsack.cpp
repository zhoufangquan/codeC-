#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int > PII;

int main(){
    int n, w;
    cin>>n>>w;
    vector<PII> Items(n+1);
    vector<vector<int> > dp(n+1);
    for(int i=0;i<=n;i++) dp[i].resize(w+1, 0);

    for(int i=1;i<=n;i++){
        cin>>Items[i].first>>Items[i].second;
    }

    for(int i=1;i<=n;i++){
        for(int j=0;j<=w;j++){
            if(j<Items[i].first) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-Items[i].first] + Items[i].second);
        }
    }

    for(auto &a:dp){
        for(auto &b:a){
            cout<<b<<' ';
        }
        cout<<'\n';
    }

    cout<<dp[n][w];

    return 0;
}

/*
# 1

7 14
3 2
4 3
3 4
2 2
7 6
6 4
6 5



# 2

5 11
1 1
2 6
5 18
6 22
7 28

*/