#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int > PII;

int main(){
    int n, w;
    cin>>n>>w;
    vector<PII> Items(n+1);
    vector<int> dp(w+1, 0);

    for(int i=1;i<=n;i++){
        cin>>Items[i].first>>Items[i].second;
    }

    for(int i=1;i<=n;i++){
        for(int j=0;j<=w;j++){
            cout<<dp[j]<<' ';
            if(j<Items[i].first) continue;
            dp[j] = max(dp[j], dp[j-Items[i].first] + Items[i].second);
        }
        cout<<'\n';
    }

    cout<<dp[w];

    return 0;
}

/*
7 14
3 2
4 3
3 4
2 2
7 6
6 4
6 5


*/