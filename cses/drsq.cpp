// dynamic range sum queries cses
#include <iostream>
#define HEAD_NODE 0
using namespace std;
typedef long long ll;
ll n,q,arr[200000],seg[800000],op,a,b;
void build(ll id,ll L,ll R) {
    if (L==R) {
        seg[id]=arr[L];
        return;
    }
    ll M=(L+R)/2;
    build(2*id+1,L,M);
    build(2*id+2,M+1,R);
    seg[id]=seg[2*id+1]+seg[2*id+2];
}
void update(ll id,ll L,ll R,ll i,ll v) {
    if (L==R) {
        seg[id]=v;
        return;
    }
    ll M=(L+R)/2;
    if (i<=M) update(2*id+1,L,M,i,v);
    else update(2*id+2,M+1,R,i,v);
    seg[id]=seg[2*id+1]+seg[2*id+2];
}
ll query(ll id,ll L,ll R,ll l,ll r) {
    if (L == l && r == R)return seg[id];
    ll M=(L+R)/2;
    if (r <= M) return query(2*id+1,L,M,l,r);
    else if (l>=M+1)return query(2*id+2,M+1,R,l,r);
    else return query(2*id+1,L,M,l,M)+query(2*id+2,M+1,R,M+1,r);
}
int main() {
    cin>>n>>q;
    for (ll i=0;i<n;i++)cin>>arr[i];
    build(HEAD_NODE,0,n-1);
    for (ll i=0;i<q;i++) {
        cin>>op>>a>>b;
        if(op==1) update(HEAD_NODE,0,n-1,a-1,b);
        else printf("%lld\n",query(HEAD_NODE,0,n-1,a-1,b-1));
    }
}