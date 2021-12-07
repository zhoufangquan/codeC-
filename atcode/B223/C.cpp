#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int, int> PII;

PII arr[100005];

int main(){
    int n;cin>>n;
    double t= 0;
    for(int i=0;i<n;i++){
        scanf("%d%d", &arr[i].fi, &arr[i].se);
        t += 1.0*arr[i].fi/arr[i].se;
    }
    t /= 2;
    double ans = 0.0;
    for(int i=0;i<n;i++){
        double temp = 1.0*arr[i].fi/arr[i].se;
        if(t-temp > 1e-8){
            ans += arr[i].fi;
            t -= temp;
        }
        else{
            ans += t*arr[i].se;
            break;
        }
    }
    printf("%.7f\n", ans);
    return 0;
}