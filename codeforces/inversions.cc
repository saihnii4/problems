#include <iostream>
using namespace std;
typedef long long ll;
int n;
ll seg[400000];
void build(ll id,ll L, ll R) {
    if (L==R) {
        seg[id] = 0;
        return;
    }
    build(2*id+1,L,M);
    build(2*id+2,M+1,R);
    seg[id]
}
int main() {
    cin >> n;
    build(HEAD_NODE,0,n-1);
    for (int i=0;i<n;i++) {
        cin >> t;
    }
}