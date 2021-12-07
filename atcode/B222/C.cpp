#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;

PII players[503];  // players_i  选手编号和分数
string C[503];

int f(char p1, char p2){
    if(p1 == p2) return 0;
    if( (p1 == 'G' && p2 == 'C') ||
        (p1 == 'C' && p2 == 'P') ||
        (p1 == 'P' && p2 == 'G'))
        return 1;
    return -1;
}

int main(){
    int N, M;
    cin>>N>>M;
    for(int i=1;i<=2*N;i++){
        players[i].first = 0;
        players[i].second = i;
    }

    for(int i=1;i<=2*N;i++){
        cin>>C[i];
    }

    for(int i = 0;i<M;i++){
        for(int j=1;j<=N;j++){
            int p1_i = players[2*j-1].second;
            int p2_i = players[2*j].second;
            // cout<<C[p1_i][i]<<' '<<C[p2_i][i]<<'\n';
            int res = f(C[p1_i][i], C[p2_i][i]);
            if(res == 1){
                players[2*j-1].first -= 1; 
            }
            else if(res == -1){
                players[2*j].first -= 1; 
            }
        }
        sort(players+1, players+1+2*N);
    }
    for(int i=1;i<=2*N;i++){
        cout<<players[i].second<<'\n';
    }
    return 0;
}