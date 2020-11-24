#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
int tot,p[maxn],vis[maxn],tag[maxn];
void init(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(!vis[i]) p[++tot]=i;
		for(int j=1;p[j]*i<=n;j++)
		{
			vis[p[j]*i]=1;
			if(p[j]%i==0) break;
		}
	}
}
int ask(char ch,int x)
{
	printf("%c %d\n",ch,x);
	fflush(stdout);
	if(ch=='C') return 0;
	scanf("%d",&x);
	return x;
}
int main()
{
	int n;
	scanf("%d",&n),init(n);
	int blk=sqrt(tot),res=n,ans=1,beg=tot+1;
	for(int i=1;i<=tot;i+=blk)
	{
		for(int j=i;j<=min(i+blk-1,tot);j++)
		{
			ask('B',p[j]);
			for(int k=p[j];k<=n;k+=p[j])
				if(!tag[k]) res--,tag[k]=1;
		}
		if(ask('A',1)!=res)
		{	beg=i; break; }
	}
	for(int i=beg;i<=tot;i++)
	{
		if(ans*p[i]>n) break;
		int cur=0;
		for(ll j=p[i];j<=n;j*=p[i])
			if(!tag[j]) cur++;
		for(ll j=p[i];j<=n;j*=p[i])
		{
			if(ask('A',j)==cur) break;
			ans*=p[i],cur-=!tag[j];
		}
	}
	ask('C',ans);
}