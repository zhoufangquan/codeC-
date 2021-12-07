#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
vector<vector<int> >G; // ÍØÆËÍ¼
int N, M;
int in[200005];


int main(){
    cin>>N>>M;
    G.resize(N+1);
    priority_queue<int, vector<int>, greater<int> > Q;

    memset(in, 0, sizeof in);

    for(int i=0;i<M;i++){
        int f,t;
        scanf("%d%d", &f, &t);
        G[f].emplace_back(t);
        in[t] ++;
    }
    for(int i=1;i<=N;i++){
        if(in[i] == 0) Q.emplace(i);
    }
    if(Q.empty()) {
        puts("-1");
        return 0;
    }
    vector<int> ans;
    while(!Q.empty()){
        int u = Q.top(); Q.pop();
        ans.emplace_back(u);
        for(int i=0;i<G[u].size();i++){
            int v = G[u][i];
            in[v] --;
            if(in[v] == 0) Q.emplace(v);
        }
        if(Q.empty() && ans.size() != N) {
            puts("-1");
            return 0;
        }
    }
    for(int &a:ans){
        printf("%d ", a);
    }

    return 0;    
}