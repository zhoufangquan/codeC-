#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct node
{
    int s;
    int f;
    int t;
    int deadliine;
};

bool cmp(node &a, node &b){
    return a.deadliine<b.deadliine;
}

int main(){

    int n;
    cin>>n;
    vector<node> requests(n, {0, 0, 0, 0});

    for(int i=0;i<n;i++){
        cin>>requests[i].t>>requests[i].deadliine;
    }

    sort(requests.begin(), requests.end(), cmp);

    int time = 0;
    int lateness = 0;
    for(auto &a:requests){
        a.s = time;
        a.f = a.s+a.t;
        time = a.f;
        lateness += a.f>a.deadliine?a.f-a.deadliine:0;
    }

    cout<<lateness<<endl;
    return 0;
}