#include<bits/stdc++.h>
using namespace std;
int d[2][7];
int gcd(int a,int b)
{	return !b?a:gcd(b,a%b); }
int main()
{
	for(int i=0;i<2;i++)
		for(int j=1;j<=6;j++)
			scanf("%d",&d[i][j]);
	int a=0,b=36;
	for(int i=1;i<=6;i++)
		for(int j=1;j<=6;j++)
			if(d[0][i]>d[1][j]) a++;
	if(!a) a=0,b=1;
	else
	{
		int d=gcd(a,b);
		a/=d,b/=d;
	}
	printf("%d/%d\n",a,b);
}