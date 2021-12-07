#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> PII;
deque<PII> L;

void f(int a)
{
    vector<int> ans;
    ans.push_back(a);
    int p = a;
    while(L[p].first != 0){
        ans.push_back(L[p].first);
        p = L[p].first;
    }
    reverse(ans.begin(), ans.end());
    p = a;
    while(L[p].second != 0){
        ans.push_back(L[p].second);
        p = L[p].second;
    }
    cout<<ans.size()<<' ';
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
}

int main(){
    int n, q;
    cin>>n>>q;
    L.push_back({0, 0});
    for(int i=1;i<=n;i++){
        L.push_back({0, 0});
    }
    for(int i=1;i<=q;i++){
        int cmd;
        cin>>cmd;
        int a,b;
        if(cmd == 1){
            cin>>a>>b;
            L[a].second = b;
            L[b].first = a;
        }
        else if(cmd == 2){
            cin>>a>>b;
            L[a].second = 0;
            L[b].first = 0;
        }
        else {
            cin>>a;
            f(a);
        }
    }

    return 0;
}