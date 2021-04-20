#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int base=233;
char s[105];
ull hval[105],powb[105];
void init(int n)
{
	powb[0]=1;
	for(int i=1;i<=n;i++)
	{
		hval[i]=hval[i-1]*base+s[i];
		powb[i]=powb[i-1]*base;
	}
}
ull gethash(int l,int r)
{	return hval[r]-hval[l-1]*powb[r-l+1]; }
int main()
{
	scanf("%s",s+1);
	int len=strlen(s+1),ans=len;
	init(len);
	for(int i=1;i<=len;i++)
		for(int j=i+1;j<=len;j++)
		{
			ull hashval=gethash(i,j);
			int tot=j-i+1,cnt=0;
			for(int k=1;k+tot-1<=len;k++)
				if(gethash(k,k+tot-1)==hashval)
					cnt++,k+=tot-1;
			ans=min(ans,len+tot-cnt*tot+cnt);
		}
	printf("%d\n",ans);
}