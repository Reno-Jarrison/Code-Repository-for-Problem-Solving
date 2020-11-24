#include<bits/stdc++.h>
using namespace std;
int c[20],p[20],l[20];
void exgcd(int a,int b,int& d,int& x,int& y)
{
	if(!b) d=a,x=1,y=0;
	else exgcd(b,a%b,d,y,x),y-=a/b*x;
}
bool check(int n,int b)
{
	int a,e,d,x,y,mod;
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
		{
			a=p[j]-p[i],e=c[i]-c[j];
			exgcd(a,b,d,x,y);
			if(e%d) continue;
			mod=abs(b/d);
			x=(x*e/d%mod+mod)%mod;
			if(x<=min(l[i],l[j])) return false;
		}
	return true;	
}
int main()
{
	int n,m=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&c[i],&p[i],&l[i]),m=max(m,c[i]);
	while(!check(n,m)) m++;
	printf("%d",m);
}