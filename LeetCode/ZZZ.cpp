#include<iostream>
#include<queue>

using namespace std;

int main(){
    queue<int> Q;
    Q.push(1);
    Q.push(2);
    Q.push(3);
    Q.push(4);
    Q.push(5);

    while(!Q.empty()){
        int c = Q.front();Q.pop();
        cout<<c<<' ';
    }
    cout<<'\n';

    return 0;
}