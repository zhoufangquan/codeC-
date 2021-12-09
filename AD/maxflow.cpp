#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
typedef vector<vector<PII> > Graph;  // first ���Ŀ�ĵ㣬 second��������ߵ�������
bool dfs(Graph G, vector<int> &path, vector<bool> &vis, int &f, int u, int t){
    if(u == t) return true;
    if(vis[u]) return false;
    vis[u] = true;
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i].first, val = G[u][i].second;
        if(vis[v] || val <= 0) continue;
        
        path[v] = u;
        int f0 = f;
        f = min(f, val);
        if(dfs(G, path, vis, f, v, t)) return true;
        f = f0;
    }
    return false;
}
vector<int> printPath(vector<int> path, int f, int s, int t){
    vector<int> ans(path.size(), 0);
    vector<string> Augmented_path;
    int p = t;
    while(p != s){
        Augmented_path.push_back("->" + to_string(p));
        ans[path[p]] = p;
        p = path[p];
    }
    Augmented_path.push_back(to_string(s));
    cout<<"�����ǣ�"<<f<<"\t";
    reverse(Augmented_path.begin(), Augmented_path.end());
    for(auto &a:Augmented_path) cout<<a; 
    cout<<'\n';

    return ans;
}
void add_Residual_edge(Graph &G, vector<int> path, int f, int s, int t){
    vector<bool> vis(G.size(), false);
    queue<int> Q;
    Q.push(s);
    while (!Q.empty())
    {
        int u = Q.front(); Q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(int i=0;i<G[u].size();i++){
            int v = G[u][i].first;
            int val = G[u][i].second;
            if(vis[v] || path[u] != v) continue;
            G[u][i].second -= f;  // ȡ����Ӧ������
            Q.push(v);
            bool extis = false;
            for(int j = 0;j<G[v].size();j++){
                if(G[v][j].first == u){
                    G[v][j].second += f;
                    extis = true;
                    break;
                }
            }
            if(!extis){
                G[v].push_back({u, f});
            }
            break;
        }
    }
}
int main(){
    Graph G;
    int V, E; // the number of Vertex and Edge
    cin>>V>>E;
    G.resize(V+1);  // the graph, the begin Vertex is number 1, the end Vertex number V
    for(int i=1;i<=E;i++){
        int u, v, e;
        cin>>u>>v>>e;
        G[u].push_back({v, e});
    }
    int maxflow = 0;
    int f;
    vector<bool> vis(V+1, false);
    vector<int> path(V+1, 0), path0(V+1, 0);
    while(1){
        f = INT_MAX;
        fill(vis.begin(), vis.end(), false);
        fill(path.begin(), path.end(), 0);
        if(!dfs(G, path, vis, f, 1, V)) break;
        maxflow += f;
        // output the Augmented path
        path = printPath(path, f, 1, V);
        // add Residual edges
        add_Residual_edge(G, path, f, 1, V);
    }
    cout<<"the max flow id: "<<maxflow<<'\n';
    return 0;
}
/*
# 1
6 9
1 2 10
1 3 10
2 3 2
2 4 4
2 5 8
3 5 9
5 4 6
5 6 10
4 6 10

# 2
7 13
1 2 10
1 3 5
1 4 5
2 3 6
2 5 3
3 6 4
3 7 6
4 2 2
4 5 3
4 6 4
5 3 3
5 6 3
6 7 10

# 3
8 14
1 2 15
1 4 7
1 3 17
2 4 5
2 5 15
3 4 8
3 6 10
4 5 20
4 6 30
5 7 30
5 8 5
6 5 5
6 8 10
7 8 20

*/


