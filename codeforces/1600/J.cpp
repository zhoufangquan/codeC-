#include<bits/stdc++.h>
using namespace std;

int n, m;
int G[1003][1003];
bool vis[1003][1003];
int derections[4] = {8,4,2,1};  // 北、东、南、西
int movesx[4] = {-1, 0, 1, 0};
int movesy[4] = {0, 1, 0, -1};

int dfs(int x, int y){
    if(vis[x][y]) return 0;
    vis[x][y] = true;
    int ans = 0;
    for(int i=0;i<4;i++){
        if(G[x][y]&derections[i]) continue;  // 此方向不通
        int x1 = x+movesx[i];
        int y1 = y+movesy[i];
        if(vis[x1][y1] || (0>=x1 || x1>n) || (0>=y1 || y1>m)) continue;
        ans += 1+dfs(x1, y1);
    }

    return ans;
}

int main(){

    cin>>n>>m;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        scanf("%d", &G[i][j]);
    }
    memset(vis, false, sizeof(vis));
    vector<int> ans;

    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        if(vis[i][j]) continue;
        ans.push_back(1+dfs(i , j));
    }
    sort(ans.begin(), ans.end(), greater<int>());
    for(auto &a:ans){
        cout<<a<<' ';
    }
    return 0;
}