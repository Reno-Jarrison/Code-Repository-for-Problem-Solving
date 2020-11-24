#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
int sg[maxn],mex[maxn];
char p1[10]="aekdycoin",p2[10]="abcdxyzk";
int main()
{
	int t,n,m,ks=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		if(m>n)
		{	printf("Case #%d: %s\n",++ks,p2); continue; }
		for(int i=1;i<m;i++) sg[i]=0;
		for(int i=m;i<=n-m;i++)
		{
			fill(mex,mex+i+1,0);
			for(int j=0;j+m<=i;j++)
				mex[sg[j]^sg[i-m-j]]=1;
			for(int j=0;j<=i+1;j++)
				if(!mex[j]) 
				{	sg[i]=j; break; }
		}
		printf("Case #%d: %s\n",++ks,sg[n-m]?p2:p1);
	}
}