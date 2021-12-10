#include<bits/stdc++.h>

using namespace std;


int main(){

    int n;
    cin>>n; // 输入序列的长度
    vector<int> arr(n);
    for(int &a:arr){ // 输入序列的值
        cin>>a;
    }

    vector<int> dp(n+1, 1);  // dp[i] 表示在 1~i的子序列中，以arr[i-1]为结尾的最长上升子序列的长度
                            // 初始值设置为，因为最小的也是1的长度
    dp[0] = 0;

    for(int i = 2;i<=n;i++){ // 表示在0~i的子序列中求上升子序列的最大值
        for(int j=1;j<i;j++){
            if(arr[i-1] > arr[j-1]) dp[i] = max(dp[i], dp[j]+1);
        }
    }

    cout<<"Output the length Longest ascending subsequence: "<<*max_element(dp.begin(), dp.end())<<'\n';

    cout<<"Output all/one of the Longest ascending subsequence: ";


    return 0;
}