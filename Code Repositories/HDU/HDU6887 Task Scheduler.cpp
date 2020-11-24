#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
pair<int,int>pr[maxn];
bool cmp(pair<int,int> a,pair<int,int> b)
{	return a.first>b.first||(a.first==b.first&&a.second<b.second); }
int main()
{
	int t,n,m,k,x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",&x),pr[i]=make_pair(x,i);
		if(k) sort(pr+1,pr+n+1,cmp);
		for(int i=1;i<=n;i++)
			printf("%d%c",pr[i].second,i==n?'\n':' ');
	}
}