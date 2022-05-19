#include<bits/stdc++.h>
using namespace std;

vector<vector<char> > get_CharVec(int r, int c){
    vector<vector<char> > ans;
    for(int i=0;i<r;i++){
        string line;
        vector<char> temp(c);
        cin>>line;
        for(int j=0;j<line.length();j++){
            temp[j] = line[j];
        }
        ans.push_back(temp);
    }
    return ans;
}

class Solution {
public:
    vector<vector<bool> > vis;
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
    void bfs(vector<vector<char>>& board, int r, int c){

        queue<pair<int, int> > Q;
        Q.push({r, c});
        vis[r][c] = false;
        while(!Q.empty()){
            pair<int, int> temp = Q.front(); Q.pop();
            int r0, c0;

            for(int i=0;i<4;i++){
                r0 = temp.first+dr[i];
                c0 = temp.second+dc[i];
                if(r0<0 || r0>=board.size() || c0<0 || c0>=board[0].size()) continue;
                if(!vis[r0][c0] || board[r0][c0] == 'X') continue;
                vis[r0][c0] = false;
                Q.push({r0, c0});
            }
        }
        
    }
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0) return;
        int r = board.size();
        int c = board[0].size();
        vis.resize(r, {});
        for( auto &item: vis){
            item.resize(c, true);
        }
        for(int i=0;i<c;i++){
            if(!vis[0][i] || board[0][i] == 'X') continue;
            bfs(board, 0, i);
        }
        print(vis);
        for(int i=0;i<c;i++){
            if(!vis[r-1][i] || board[r-1][i] == 'X') continue;
            bfs(board, r-1, i);
        }
        print(vis);
        for(int i=0;i<r;i++){
            if(!vis[i][0] || board[i][0] == 'X') continue;
            bfs(board, i, 0);
        }
        print(vis);
        for(int i=0;i<r;i++){
            if(!vis[i][c-1] || board[i][c-1] == 'X') continue;
            bfs(board, i, c-1);
        }
        print(board);
        print(vis);
        for(int i=1;i<r-1;i++){
            for(int j=1;j<c-1;j++){
                if(!vis[i][j] || board[i][j] == 'X') continue;
                board[i][j] = 'X';
            }

        }
    }

    void print(vector<vector<char>>& board) {
        
        for(auto &items: board){
            for(auto &item: items){
                cout<<item;
            }
            cout<<'\n';
        }
        
        cout<<'\n';
    }

    void print(vector<vector<bool>>& board) {
        
        for(auto &items: board){
            for(auto item: items){
                cout<<item;
            }
            cout<<'\n';
        }
        
        cout<<'\n';
    }
};
// @lc code=end

int main(){
    vector<vector<char> > board;
    int r, c;
    cin>>r>>c;
    board = get_CharVec(r, c); 
    Solution test;
    test.solve(board);
    for(auto &items: board){
        for(auto &item: items){
            cout<<item;
        }
        cout<<'\n';
    }
    return 0;
}

/*
3 3
OOO
OOO
OOO


*/