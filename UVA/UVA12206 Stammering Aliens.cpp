#include<cstdio>
#include<cstring>
#include<map>
#define ull unsigned long long
using namespace std;
const int maxn=4e5+5;
const ull p=233;
ull h[maxn],pow[maxn]={1};
char s[maxn];
ull gethash(int l,int r)
{	return h[r]-h[l-1]*pow[r-l+1]; }
int check(int mval,int n,int m)
{
	int pos=-1;
	map<ull,int>mp;
	for(int i=mval;i<=n;i++)
	{
		ull hval=gethash(i-mval+1,i);
		mp[hval]++;
		if(mp[hval]>=m) pos=i-mval;
	}
	return pos;
}
int main()
{
	int m;
	for(int i=1;i<=maxn-5;i++)
		pow[i]=p*pow[i-1];
	while(~scanf("%d",&m)&&m)
	{
		scanf("%s",s+1);
		int len=strlen(s+1),l,r;
		for(int i=1;i<=len;i++)
			h[i]=h[i-1]*p+s[i];
		l=1,r=len;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(check(mid,len,m)>=0) l=mid+1;
			else r=mid-1;
		}
		if(!r) puts("none");
		else printf("%d %d\n",r,check(r,len,m));
	}
}