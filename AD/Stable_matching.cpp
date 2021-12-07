#include<iostream>
#include<cstring>
#include<vector>
#include<deque>
#include<map>
using namespace std;

typedef map<string, string> MSS;
typedef vector<string> VS;
typedef map<string, vector<string>> MSV;

VS f(string s){
    VS ans;
    string temp = "";
    for(int i=0;i<s.length();i++){
        if(s[i] == ' '){
            ans.push_back(temp);
            temp = "";
        }
        else{
            temp += s[i];
        }
    }
    ans.push_back(temp);
    return ans;
}

MSS GS(VS &M, MSV &MList, VS &F, MSV &FList){
    MSS ans;
    map<string, bool> Fvis;
    for(auto &f:F) Fvis[f] = false;
    deque<string> Q;
    for(auto &m:M) Q.push_back(m);

    while(!Q.empty()){
        string man = Q.front(); Q.pop_front();
        VS prefer = MList[man];
        for(auto &f:prefer){
            if(!Fvis[f]){
                ans[f] = man;
                Fvis[f] = true;
                break;
            }
            else{
                string man1 = ans[f];
                VS prefer_f = FList[f];
                bool have_better = false;
                for(auto &_:prefer_f){
                    if(_ == man1){
                        break;
                    }
                    if(_ == man){
                        have_better = true;
                        break;
                    }
                }                
                if(have_better){
                    Q.push_front(man1);
                    ans[f] = man;
                    Fvis[f] = true;
                    break;
                }
                else{
                    continue;
                }
            }
        }
    }
    return ans;
}

int main(){
    int n;
    cout<<"����Ů�Ե�������";cin>>n;
    VS M(n), F(n);
    MSV Mlist, Flist;
    cout<<"���Ե����ƣ�";
    for(int i=0;i<n;i++){
        cin>>M[i];
    }
    cout<<"Ů�Ե����ƣ�";
    for(int i=0;i<n;i++){
        cin>>F[i];
    }
    getchar();
    for(int i=0;i<n;i++){
        cout<<"����"<<M[i]<<"ϲ����Ů�Ե�������";
        Mlist[M[i]] = {};
        string temp;
        getline(cin, temp);
        VS prefer;
        prefer = f(temp);
        for(auto &f: prefer){
            Mlist[M[i]].push_back(f);
        }
    }
    
    for(int i=0;i<n;i++){
        cout<<"Ů��"<<F[i]<<"ϲ�������Ե�������";
        Flist[F[i]] = {};
        string temp;
        getline(cin, temp);
        VS prefer;
        prefer = f(temp);
        for(auto &m: prefer){
            Flist[F[i]].push_back(m
            );
        }
    }

    MSS ans;
    ans = GS(M, Mlist, F, Flist);

    auto iter = ans.begin();
    for(;iter != ans.end(); iter++){
        cout<<iter->first<<' '<<iter->second<<'\n';
    }
    return 0;
}

/*
5
V W X Y Z
A B C D E
B A D E C
D B A C E
B E C D A
A D C B E
B D A E C
Z V W Y X
X W Y V Z
W X Y Z V
V Z Y X W
Y W Z X V
*/