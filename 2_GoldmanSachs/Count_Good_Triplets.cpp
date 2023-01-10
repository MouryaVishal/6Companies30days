#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    constexpr int static len = 100000;
    int bit[len+1]{};

    int getSum(int i) {
        int res = 0;
        for(i = i+1; i > 0; i -= i&(-i)) res += bit[i];
        return res;
    }

    void add(int i, int v) {
        for(i = i+1; i <= len; i += i&(-i)) bit[i] += v;
    }

    ll goodTriplets(vector<int>& A, vector<int>& B) {
        ll res = 0, N = A.size();
        vector<int> idx_remap(N);
        for(int i = 0; i < N; i++) idx_remap[B[i]] = i;
        for(int i = 0; i < N; i++) {
            int idx = idx_remap[A[i]];
            ll left = getSum(idx), right = N-1-idx-(i-left);
            res += left*right;
            add(idx, 1);
        }
        return res;
    }
};

int main(){
    int num;
    cout<<"Enter number:- ";
    cin>>num;
    vector<int> vec(num);
    for(int i=0;i<num;i++) cin>>vec[i];
    vector<int> vec2(num);
    for(int j=0;j<num;j++) cin>>vec2[j];
    Solution obj;
    cout<<obj.goodTriplets(vec,vec2)<<endl;
}