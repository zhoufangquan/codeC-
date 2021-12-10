// the same as the 完全背包

#include<bits/stdc++.h>

using namespace std;


int main(){
    int n, M; // n is the number of different value coins;  M is number of money you need to change.
    cin>>n>>M;
    vector<int> coins(n);  //  to store the value of different coins
    sort(coins.begin(), coins.end(), greater<int>());
    
    for(int &a:coins){
        cin>>a;
    }

    vector<vector<int>> dp(n+1); // use to store the opt ans of sub problem
                                // dp[i][j] 表示我们使用了1~i的面值硬币找钱j,得到的最小硬币数是？

    for (auto &a:dp){
        vector<int> temp(M+1, 0);
        a = temp;
    }
    // 初始值全不设为max 边界值已经得到解决
    for(int i=0;i<=n;i++) dp[i][0] = 0;
    for(int i=0;i<=M;i++) dp[0][i] = i/coins[0];

    for(int i=1;i<=n;i++) // 使用了前i个硬币的面值得到的最优解
    {
        for(int j=1;j<=M;j++){
            if(coins[i-1]>j) dp[i][j] = dp[i-1][j];
            else{
                dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i-1]]+1);
            }
        }
    }

    for(auto &a:dp){
        for(int &item:a){
            printf("%-3d", item);
            // cout<<item<<"\t";
        }
        cout<<'\n';
    }
    cout<<"the least number of coins is: "<< dp[n][M]<<'\n';

    // 输出找回的钱数
    cout<<"Output the coins needed to change: ";
    int i=n, j=M;
    while(i!=0 || j!=0){
        if(i == 0 || dp[i-1][j] != dp[i][j]){
            cout<<coins[i-1]<<' ';
            j -= coins[i-1];
        }
        else{
            i--;
        }
    }

/*
我们同样也可以用一维数组来解决这个问题。
dp[M]
边界条件的设定为： dp[0~M] = 0~M/coin[0]  要除以最小的硬币的面值

for(int i=1;i<=n;i++) // 使用了前i个硬币的面值得到的最优解
{
    for(int j=0;j<=M;j++){
        if(coins[i-1]>=j) dp[j] = dp[j];
        else{
            dp[j] = min(dp[j], dp[j-coins[i-1]]+1);
        }
    }
}

*/

    return 0;
}

/*

5 23
1 5 7 35 70

5 34
1 5 7 35 70

5 70
1 5 7 35 70

*/