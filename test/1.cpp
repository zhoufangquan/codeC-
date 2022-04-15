#include<bits/stdc++.h>

using namespace std;

// class City {
// public:
//     int u; // 城市编号
//     int cost;  // 花费
//     int k;   // 到达该城市的中转次数
//     City(int u, int cost, int k) {
//         u = u, cost = cost, k = k;
//     }

//     friend bool operator<(const City &a, const City &b) {
//         return a.cost < b.cost;
//     }
// };
struct node{
    int u;
    int cost;
    int k;
    node(int to1, int r1, int c1): u(to1), cost(r1), k(c1){}

    friend bool operator<(const node &a, const node &b) {
        return a.cost > b.cost;
    }
};



class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int res = -1;

        priority_queue<node> Q;
        vector<bool> vis(n, 0);
        
        Q.push(node(src, 0, 0)); // 输入起始点，0花费，经过0个中转站
        while(!Q.empty()){
            node now = Q.top(); Q.pop();
            if(now.k > k+1 ) continue;
            if(dst == now.u){
                res = now.cost;
                break;
            }
            vis[now.u] = 1;

            for(auto &a: flights){
                int v = a[1]; // now.u 的邻接点
                if(a[0] != now.u || vis[v]) continue;
                Q.push(node(v, a[2]+now.cost, now.k+1));
            }
        }

        return res;
    }
};

int main(){
    int n = 3;
    vector<vector<int>> flights;
    int src = 0;
    int dst = 2;
    int k = 1;

    flights.push_back({0,1,100});
    flights.push_back({1,2,100});
    flights.push_back({0,2,500});

    Solution C;
    cout<<C.findCheapestPrice(n, flights, src, dst, k);

    return 0;
}

/*

11
[[0,3,3],[3,4,3],[4,1,3],[0,5,1],[5,1,100],[0,6,2],[6,1,100],[0,7,1],[7,8,1],[8,9,1],[9,1,1],[1,10,1],[10,2,1],[1,2,100]]
0
2
4

*/