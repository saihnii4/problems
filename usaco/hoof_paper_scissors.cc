#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
int n;
char c[100000];
int ph[100000], pp[100000], ps[100000], m;
int main()
{
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  freopen("hps.in", "r", stdin);
  freopen("hps.out", "w", stdout);
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    char t;
    cin >> t;
    c[i] = t;
  }
  for (int i = 0; i < n; i++)
  {
    switch (c[i])
    {
    case 'H':
      ph[i + 1] = ph[i];
      ps[i + 1] = ps[i];
      pp[i + 1] = pp[i] + 1;
      break;
    case 'P':
      ph[i + 1] = ph[i];
      ps[i + 1] = ps[i] + 1;
      pp[i + 1] = pp[i];
      break;
    case 'S':
      ph[i + 1] = ph[i] + 1;
      ps[i + 1] = ps[i];
      pp[i + 1] = pp[i];
      break;
    }
  }
  for (int i = 0; i < n; i++)
  {
    m = max(m, ps[i] + ph[n] - ph[i]);
    m = max(m, ps[i] + pp[n] - pp[i]);
    m = max(m, pp[i] + ps[n] - ps[i]);
    m = max(m, pp[i] + ph[n] - ph[i]);
    m = max(m, ph[i] + pp[n] - pp[i]);
    m = max(m, ph[i] + ps[n] - ps[i]);
  }
  m = max(m, ph[n]);
  m = max(m, ph[n]);
  m = max(m, ps[n]);
  cout << m << endl;
}
