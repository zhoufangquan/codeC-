#include<bits/stdc++.h>

using namespace std;
int arr[100005];

int main(){
    memset(arr, 0, sizeof arr);
    int N;
    cin>>N;
    for(int i=1;i<N;i++)
    {
        int a,b;
        scanf("%d%d", &a, &b);
        arr[a] ++;
        arr[b] ++;
    }
    bool Yes = false;
    for(int i=1;i<=N;i++){
        if(arr[i] == N-1){
            Yes = true;
            break;
        }
    }
    if(Yes){
        puts("Yes");
    }
    else {
        puts("No");
    }
    return 0;
}