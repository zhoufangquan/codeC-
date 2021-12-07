#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef vector<vector<int> > Matrix;

Matrix add(const Matrix &A, const Matrix &B){
    if(A.empty()) return B;
    if(B.empty()) return A;
    Matrix C;
    int m = A.size(), n = A[0].size();
    for(int i=0;i<m;i++){
        vector<int> t;
        for(int j=0;j<n;j++){
            t.push_back(A[i][j] + B[i][j]);
        }
        C.push_back(t);
    }
    return C;
}

Matrix sub(const Matrix &A, const Matrix &B){
    Matrix C;
    int m = A.size(), n = A[0].size();
    for(int i=0;i<m;i++){
        vector<int> t;
        for(int j=0;j<n;j++){
            t.push_back(A[i][j] - B[i][j]);
        }
        C.push_back(t);
    }
    return C;
}

void input_M(Matrix &M, int m, int n){
    for(int i=0;i<m;i++){
        vector<int> t;
        for(int j=0;j<n;j++){
            int c; cin>>c;
            t.push_back(c);
        }
        M.push_back(t);
    }
}

void output_M(Matrix M){
    int m = M.size(), n = M[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<M[i][j]<<' ';
        }
        cout<<'\n';
    }
}

void Combine(Matrix &M, Matrix &M11, Matrix &M12, Matrix &M21, Matrix &M22){
    for(int i=0;i<M11.size() || i<M21.size();i++){
        vector<int> t;
        for(int j=0;i<M11.size() && j<M11[0].size();j++){
            t.push_back(M11[i][j]);
        }
        for(int j=0;j<M12[0].size();j++){
            t.push_back(M12[i][j]);
        }
        M.push_back(t);
    }
    for(int i=0;i<M21.size() || i<M22.size();i++){
        vector<int> t;
        for(int j=0;i<M21.size() && j<M21[0].size();j++){
            t.push_back(M21[i][j]);
        }
        for(int j=0;j<M22[0].size();j++){
            t.push_back(M22[i][j]);
        }
        M.push_back(t);
    }
}


int main(){
    Matrix A, B;
    // cout<<A.empty();
    int m, n, r;
    cin>>m>>n>>r;
    input_M(A, m, n);
    input_M(B, n, r);

    Matrix C;
    Combine(C, A, A, A, B);
    // output_M(add(A, B));
    output_M(C);

    // Matrix A;
    // A.push_back({1});
    // output_M(A);
    return 0;
}