#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


bool cmp(pair<int, int> &a, pair<int, int> &b){
    if(a.second == b.second) return a.first<b.first;
    else return a.second<b.second;
}

int main(){

    int n; // 任务数
    vector<pair<int, int> > interval;  // 任务工作时间

    cin>>n;

    for(int i=0;i<n;i++){
        int s, f;
        cin>>s>>f;
        interval.push_back({s, f});
    }

    sort(interval.begin(), interval.end(), cmp);

    vector<pair<int, int> > ans;
    int time = 0;
    for(int i=0;i<n;i++){
        if(time <= interval[i].first){
            time = interval[i].second;
            ans.push_back(interval[i]);
        }
    }

    cout<<"最大的任务数不重叠的集合大小："<<ans.size()<<endl;
    for(int i=0; i<ans.size();i++){
        cout<<ans[i].first<<"——"<<ans[i].second<<' ';
    }
    return 0;
}



/*
8
0 6
1 4
3 5
3 8
4 7
5 9
6 10
8 11


*/