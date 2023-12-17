#include <iostream>
#include <utility>
#include <string>
#include <vector>
#define HEAD_NODE 0
using namespace std;
using ll = long long;
typedef bool node;
int N, Q;
pair<int, int> arr[200000];
int S[3][200000];
int comb[3][200000];
node seg[800000];
node merge(node l, node r) {
  return l && r;
}
void build(ll id, ll L, ll R) {
  if (L == R) {
    bool state = false;
    for (int i=0;i<3;i++) {
      /* cout << arr[L].first << ' ' << comb[i][arr[L].second] << endl; */
      state |= arr[L].first == comb[i][arr[L].second];
      state |= arr[L].first == S[i][arr[L].second];
    }
    seg[id] = state;
    return;
  }
  ll M = (L + R) / 2;
  build(2 * id + 1, L, M);
  build(2 * id + 2, M + 1, R);
  seg[id] = merge(seg[2 * id + 1], seg[2 * id + 2]);
}
void preprocess() {
  for (int i = 0; i < N; i++) {
    if (S[0][i] == S[1][i])
      comb[0][i] = S[0][i];
    else
      comb[0][i] = S[0][1] ^ S[1][i] ^ (0 ^ 1 ^ 2);
    if (S[1][i] == S[2][i])
      comb[1][i] = S[1][i];
    else
      comb[1][i] = S[0][1] ^ S[1][i] ^ (0 ^ 1 ^ 2);

    if (S[0][i] == S[2][i])
      comb[2][i] = S[2][i];
    else
      comb[2][i] = S[0][1] ^ S[1][i] ^ (0 ^ 1 ^ 2);
  }
}
void update(ll id, ll L, ll R, ll i, ll v) {
  if (L == R) {
    bool state = false;
    for (int j=0;j<3;j++) {
      state |= arr[L].first == comb[j][arr[L].second];
      state |= arr[L].first == S[j][arr[L].second];
    }
    seg[id] = state;
    return;
  }
  ll M=(L+R)/2;
  if (i <= M) update(2*id+1,L,M,i,v);
  else update(2*id+1,M+1,R,i,v);
  seg[id] = merge(seg[2*id+1], seg[2*id+2]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("sample", "r", stdin);
  cin >> N;
  for (int i = 0; i < 3; i++) {
    string str;
    cin >> str;
    for (int j = 0; j < N; j++) {
      S[i][j] = str.c_str()[j] - '0';
    }
  }
  preprocess();
  cin >> Q;
  string str;
  cin >> str;
  for (int i=0;i<N;i++) {
    arr[i] = make_pair(str.c_str()[i] - '0', i);
  }
  build(HEAD_NODE, 0, N-1);
  cout << (seg[HEAD_NODE] ? "Yes" : "No") << endl;
  for (int i=0;i<Q;i++) {
    int l, r, v;
    cin >> l >> r >> v;
    for (int i=l-1;i<r;i++) {
      /* cout << arr[i].first; */
      update(HEAD_NODE, 0, N-1, i, v);
      /* cout << endl; */
    }
    cout << (seg[HEAD_NODE] ? "Yes" : "No") << endl;
  }
  return 0;
}
