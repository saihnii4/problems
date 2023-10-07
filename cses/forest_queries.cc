#include<iostream>
#include<algorithm>
using namespace std;
int n,q,x1,_y1,x2,y2,p[1001][1001];
int main() {
    cin>>n>>q;
    for (int i=0;i<n;i++) {
        p[i][0] = 0;
    }
    for (int i=0;i<n;i++) {
        p[0][i] = 0;
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            char t;
            cin>>t;
            p[i][j]=p[i-1][j]+p[i][j-1]-p[i-1][j-1]+(t-'*' == 0 ? 1 : 0);
        }
    }
    for(int i=0;i<q;i++) {
        cin>>x1>>_y1>>x2>>y2;
        int x = min(x1,x2);
        int X = max(x1,x2);
        int y = min(_y1,y2);
        int Y = max(_y1,y2);
        cout << p[X][Y] - p[X][y-1] - p[x-1][Y] + p[x-1][y-1] << endl;
    }
    return 0;
}