// TODO:
#include<iostream>
using namespace std;
typedef long long ll;
int n,q,a,b;
char op;
ll arr[200000];
node seg[800000];
node merge(node a, node b) {

}
void build(ll id,ll L,ll R) {
    if (L==R) {
        seg[id] = arr[L];
        return;
    }
    ll M=(L+R)/2;
    build(2*id+1,L,M);
    build(2*id+2,M+1,R);
    seg[id]=merge(seg[2*id+1],seg[2*id+2]);
}
void update(ll id,ll L, ll R,ll a, ll b) {

}
int main() {
    cin>>n>>q;
    for (int i=0;i<n;i++) {
        cin>>arr[i];
    }
    build(HEAD_NODE,0,n-1);
    for (int i=0;i<q;i++) {
        cin>>op>>a>>b;
        if (op-'!' == 0) update(HEAD_NODE, 0, n-1, a, b);
        else printf("%lld\n", query(HEAD_NODE, 0, n-1, a, b));
    }
    return 0;
}