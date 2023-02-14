#include <stdio.h>
int main(){int N,a,b;scanf("%d",&N);for (int i=0;i<N;i++){scanf("%d %d",&a,&b);printf("%s\n",a>b?">":(a<b?"<":"="));}
