#include <stdio.h>
int main() {
    int A, B;
    scanf("%d %d", &A, &B);
    if (A == 2) return printf("2\n");
    else if (B == 2) return printf("3\n");
    if (B >= A) return printf("%d\n", 2*(A-1));
    else return printf("%d\n", 2*B-1);
}
