#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
int a[maxn][maxn];
int gcd(int a,int b)
{	return !b?a:gcd(b,a%b); }
int quad(int x)
{	return x*x*x*x; }
int main()
{
	int n,m,lcm=1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
			lcm=lcm/gcd(lcm,a[i][j])*a[i][j];
		}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			printf("%d ",lcm+((i+j)%2?quad(a[i][j]):0));
		puts("");
	}
}