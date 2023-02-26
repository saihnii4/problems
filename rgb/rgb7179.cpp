#include <iostream>
using namespace std;
int main()
{
int i,a,b,s1,s2,s3;
cin>>a>>b;

s1=0;s2=0;s3=0;

for(i=1;i<=6;i++)
{
if(abs(i-a)>abs(i-b)) s1=s1+1;
if(abs(i-a)==abs(i-b)) s2=s2+1;
if(abs(i-a)<abs(i-b)) s3=s3+1;
}

cout << s3 << " " << s2 << " " << s1;
return 0;
} 
