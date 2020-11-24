#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6+5;
ll s[maxn];
int	stk[maxn];
bool update(int top,int k)
{
	int i=stk[top-1],j=stk[top];
	return (s[k]-s[j])*(k-i)<=(s[k]-s[i])*(k-j);
}
int main()
{
	int n,x,top=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
		scanf("%d",&x),s[i]=s[i-1]+x;
	for(int i=1;i<=n;i++)
	{
		while(top&&update(top,i)) top--;
		stk[++top]=i;
	}
	for(int i=1;i<=top;i++)
	{
		int l=stk[i-1],r=stk[i];
		double x=1.0*(s[r]-s[l])/(r-l);
		for(int j=l;j<r;j++) printf("%.9lf\n",x);
	}
}