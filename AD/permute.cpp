#include<iostream>
#include<vector>

using namespace std;

void permute(vector<int> arr, int l, int r){
    if(l == r){
        for(int i=0;i<arr.size();i++){
            cout<<arr[i]<<' ';
        }
        putchar('\n');
        return ;  
    }
    for(int i=l;i<r;i++){
        swap(arr[l], arr[i]);
        permute(arr, l+1, r);
        swap(arr[l], arr[l]);
    }
    return ;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n, 0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    permute(arr, 0, n);
    return 0;
}