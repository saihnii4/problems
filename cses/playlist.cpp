#include <vector>
#include <set>
#include <algorithm>
#include <stdio.h>
 
using namespace std;
 
int main()
{
    int n, max = 0;
    scanf("%d", &n);
    long long arr[n];
    set<long long> songs;
 
    for (int i = 0; i < n; i++)
        scanf("%lld", &arr[i]);
 
    vector<long long> sub;
 
    for (int i = 0; i < n; i++)
    {
        long long num = arr[i];
        if (songs.find(num) != songs.end()) {
            auto res = find(sub.begin(), sub.end(), num);
            int j = res - sub.begin();
            for (int i = 0; i < j; i++) {
                songs.erase(sub[i]);
            }
            sub.erase(sub.begin(), res + 1);
        }
 
        sub.push_back(num);
        songs.insert(num);
 
        if (sub.size() > max)
            max = sub.size();
    }
 
    printf("%d\n", max);
}
