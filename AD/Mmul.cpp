/*
Matrix multiplication optimization
*/
#include<bits/stdc++.h>
using namespace std;
typedef vector<vector<int> > Matrix;

void Apart(Matrix M, Matrix &M11, Matrix &M12, Matrix &M21, Matrix &M22){
    int m = M.size(),n = M[0].size();
    int m1 = m/2, n1 = n/2;
    for(int i=0;i<m1;i++){
        vector<int> t;
        for(int j=0;j<n1;j++){
            t.push_back(M[i][j]);
        }
        M11.push_back(t);
    }
    for(int i=0;i<m1;i++){
        vector<int> t;
        for(int j=n1;j<n;j++){
            t.push_back(M[i][j]);
        }
        M12.push_back(t);
    }
    for(int i=m1;i<m;i++){
        vector<int> t;
        for(int j=0;j<n1;j++){
            t.push_back(M[i][j]);
        }
        M21.push_back(t);
    }
    for(int i=m1;i<m;i++){
        vector<int> t;
        for(int j=n1;j<n;j++){
            t.push_back(M[i][j]);
        }
        M22.push_back(t);
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

void input_M(Matrix &M, int m, int n){
    M.clear();
    cout<<" 输入一个矩阵：\n";
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
    cout<<" 输出得到的矩阵：\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<M[i][j]<<' ';
        }
        cout<<'\n';
    }
}

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

void extend(Matrix &M, int rc){
    int r = M.size(), c = M[0].size();
    int add_r = rc-r, add_c = rc-c;

    for(auto &row:M){
        int i=add_c;
        while(i--) row.push_back(0);
    }
    int i = add_r;
    while(i--){
        vector<int> temp(c+add_c, 0);
        M.push_back(temp);
    }
}

void compress(Matrix &M, int r, int c){
    int r0 = M.size(), c0 = M[0].size();
    for(int i=r0;i!=r;i--) M.pop_back();
    for(auto &row:M){
        for(int i=c0;i!=c;i--) row.pop_back();
    }
}

Matrix Mmul(Matrix A, Matrix B){
    Matrix C;  // 结果矩阵
    int m = A.size(),n = B.size(),r = B[0].size();
    if(m == 1 && n == 1 && r == 1){
        C.push_back({A[0][0] * B[0][0]});
        return C;
    }

    Matrix  A11, A12,  B11, B12,  C11, C12;
    Matrix  A21, A22,  B21, B22,  C21, C22;
           
    Apart(A, A11, A12, 
             A21, A22);
    Apart(B, B11, B12, 
             B21, B22);

    // // if(m == 1 || n == 1 || r==1){
    // Matrix M1, M2, M3, M4, M5, M6, M7, M8;
    // // M1 一定是空矩阵
    // if(m != 1 && n!=1 && r!=1) M1 = Mmul(A11, B11);
    // if(m != 1 && r != 1) M2 = Mmul(A12, B21);
    // if(m != 1 && n != 1) M3 = Mmul(A11, B12);
    // if(m != 1) M4 = Mmul(A12, B22);
    // if(n != 1 && r != 1) M5 = Mmul(A21, B11);
    // if(r != 1) M6 = Mmul(A22, B21);
    // if(n != 1) M7 = Mmul(A21, B12);
    // M8 = Mmul(A22, B22);
    // C11 = add(M1, M2);
    // C12 = add(M3, M4);
    // C21 = add(M5, M6);
    // C22 = add(M7, M8);
    // Combine(C, C11, C12, 
    //             C21, C22);
    // return C;
    // // }

    Matrix P1, P2, P3, P4, P5, P6, P7;
    P1 = Mmul(A11, sub(B12, B22));  // output_M(P1);
    P2 = Mmul(add(A11, A12), B22);  // output_M(P2);
    P3 = Mmul(add(A21, A22), B11); // output_M(P3);
    P4 = Mmul(A22, sub(B21, B11)); // output_M(P4);
    P5 = Mmul(add(A11, A22), add(B11, B22));  // output_M(P5);
    P6 = Mmul(sub(A12, A22), add(B21, B22));  // output_M(P6);
    P7 = Mmul(sub(A11, A21), add(B11, B12));  // output_M(P7);

    C11 = add(add(P4, P5), sub(P6, P2));
    C12 = add(P1, P2);
    C21 = add(P3, P4);
    C22 = sub(add(P1, P5), add(P3, P7));
    Combine(C, C11, C12, 
               C21, C22);

    return C;
}

uint32_t ceilToPowerOf2(uint32_t v) {
// 高位的1往右移动并且复制到地位，然后从刚开始的最高位1个，累加3 7 15 31个。最后再加1。
   v += (v == 0);  
   v--;
   v |= v >> 1;
   v |= v >> 2;
   v |= v >> 4;
   v |= v >> 8;
   v |= v >> 16;
   v++;
   return v;
}

int main(){
    Matrix A, B, C;
    int m, n, r;
    while(cin>>m>>n>>r){
        input_M(A, m, n);
        input_M(B, n, r);
        int mnr = ceilToPowerOf2( max(n, max(r, m)) );
        extend(A, mnr);
        extend(B, mnr);
        C = Mmul(A, B);
        compress(C, m, r);
        output_M(C);
        cout<<"press Ctrl+C to end the program.\n";
    }

    return 0;
}

/*
examples:
A  B
4 4 4
1 2 3 4
5 6 7 8
2 4 6 8
1 3 5 7
1 0 0 0
0 2 0 0
0 0 3 0
0 0 0 4

1 2 1
1 2
3
4

3 3 3
1 2 3
1 2 3
1 2 3
1 0 0
0 2 0
0 0 1

*/
