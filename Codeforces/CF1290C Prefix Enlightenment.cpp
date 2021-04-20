#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=3e5+5,inf=0x3f3f3f3f;
char s[maxn];
vector<int>vec[maxn];
int f[maxn*2];
ll siz[maxn*2];
int find(int x)
{	return f[x]==x?x:f[x]=find(f[x]); }
void merge(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(fx!=fy)
		f[fx]=fy,siz[fy]+=siz[fx];
}
ll getsiz(int x,int k)
{	return min(siz[find(x)],siz[find(x+k)]); }
int main()
{
	int n,k,c,x;
	scanf("%d%d%s",&n,&k,s+1);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c);
		while(c--)
			scanf("%d",&x),vec[x].push_back(i);
		f[i]=i,f[i+k]=i+k,siz[i+k]=1;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int cnt=vec[i].size();
		if(cnt==1)
		{
			int x=vec[i][0];
			ans-=getsiz(x,k);
			siz[find(x+(s[i]=='1')*k)]=inf;
			ans+=getsiz(x,k);
		}
		else if(cnt==2)
		{
			int x=vec[i][0],y=vec[i][1],tag=(s[i]=='0');
			if(find(x)!=find(y+tag*k))
			{
				ans-=getsiz(x,k)+getsiz(y,k);
				merge(x,y+tag*k),merge(x+k,y+(tag^1)*k);
				ans+=getsiz(x,k);
			}
		}
		printf("%d\n",ans);
	}
}