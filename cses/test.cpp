#include <stdio.h>

int main() {
    int arr[9] = {5, 5, 6, 6, 7, 8};
    int l = 0;
    int r = 9;
    long long mid;
    int gondola = 1;

    while (l <= r) {
        mid = (l + r) / 2;

        printf("%d %d\n", l, r);

        if (arr[mid] == gondola) {
            l = mid;
            r = mid;
            break;
        }
        
        if (arr[mid] > gondola) r = mid - 1;
        else l = mid +  1;
    }

    printf("%d %d\n", l, r);
    return 0;
}