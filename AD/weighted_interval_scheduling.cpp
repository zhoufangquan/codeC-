#include<bits/stdc++.h>
using namespace std;

struct node
{
    int s,f,val;
    bool operator<(const node &a){
        return f<a.f;
    }
};

void get_p(vector<int> &p, vector<node> &interval){
    int n = interval.size();
    for(int i=n-1;i>0;i--){
        for(int j=i-1;j>0;j--){
            if(interval[j].f <= interval[i].s){
                p[i] = j;
                break;
            }
        }
    }
}

int main(){

    int n; // 任务数
    cin>>n;
    vector<node> interval(n+1);  // 工作时间
    vector<int> p(n+1, 0), dp(n+1, 0);
    for(int i=0;i<n;i++){
        int s, f, val;
        cin>>interval[i+1].s>>interval[i+1].f>>interval[i+1].val;
    }
    sort(interval.begin()+1, interval.end());
    get_p(p, interval);
    for(int i=1;i<=n;i++){
        dp[i] = max(dp[i-1], dp[p[i]] + interval[i].val);
    }
    for(auto &a:dp){
        cout<<a<<' ';
    }
    return 0;
}



/*
8
0 6 23
1 4 12
3 5 20
3 8 26
4 7 13
5 9 20
6 10 11
8 11 16


*/