
#include<bits/stdc++.h>

using namespace std;

string add(string &a, string &b){
    string ans;
    int na = a.size();
    int nb = b.size();
    int i = na-1, j=nb-1;
    int c = 0;
    while(i>=0 || j>=0){
        int t = c;
        if(i>=0) {t += a[i]-'0'; i --;}
        if(j>=0) {t += b[j]-'0'; j --;}
        ans += t%10+'0';
        c = t/10;
    }
    if(c) ans += '0'+c;
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    int N, M; cin>>N>>M;
    if(M>7){
        puts("No");
        return 0;
    }
    int num[7];
    for(int i=0;i<M;i++){
        cin>>num[i];
    }
    for(int i=1;i<M;i++){
        if(num[i-1]+1 != num[i]  || (num[i-1]-1)%7 >= (num[i]-1)%7){
            puts("No");
            return 0;
        }
    }
    for(int i=1;i<N;i++){
        int arr[7];
        for(int j=0;j<M;j++) cin>>arr[j];
        for(int j=1;j<M;j++){
            if(arr[j-1]+1 != arr[j]){
                puts("No");
                return 0;
            }
        }

        for(int j=0;j<M;j++){
            if(num[j] + 7 != arr[j]){
                puts("No");
                return 0;
            }
            num[j] = arr[j];
        }
    }

    puts("Yes");
    return 0;
}