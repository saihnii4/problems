#include <stdio.h>

float f(float d, float m, float v, int i) {
    float r = v;
    for (int i = 1; i < m; i++) {
        r = r*(1 + i/100) - d;
    }

    return r;
}

int main() {
    int m, v, i;
    float d;
    float epsilon = 1e-5;
    
    scanf("%d %d %d", &m, &v, &i);

    float a = 0.01, b = (1 + i/100)*v;
    float func = 0;
    printf("%f\n", f(550.005, m, v, i));
    
    do {
        int r = (a + b)/2;
        func = f(r,m,v,i);
        if (func>0) a = r;
        else b = r;
    } while (func > epsilon);
}
