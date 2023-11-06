#include <iostream>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;
using ll = long long;
string str;
unordered_map<ll,ll> s;
ll ps[200001],ans;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>str;
    for (int i=0;i<str.size();i++) {
        ps[i] = stol(&str.c_str()[i]) % 2019;
    }
    ps[str.size()] = 0;

    for (int i=0;i<=str.size();i++) {
        s[ps[i]]++;
    }

    for (auto& it : s) {
        ans += ((it.second)*(it.second-1)) >> 1;
    }

    cout << ans << endl;
}
