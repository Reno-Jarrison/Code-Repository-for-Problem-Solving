#include<bits/stdc++.h>
#define ll long long
#define maxn 2000005 
using namespace std;
ll p[maxn],d[maxn],sump[maxn],sumd[maxn][2],q[maxn];
bool ans[maxn];
inline bool check(int i,int j,int flag)
{	return sump[i]-sumd[i][flag]>=sump[j]-sumd[j][flag]; }
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&p[i],&d[i]),p[i+n]=p[i],d[i+n]=d[i];
	sumd[1][1]=d[n];
	for(int i=1;i<=n<<1;i++)
	{
		sump[i]=sump[i-1]+p[i];
		sumd[i][0]=sumd[i-1][0]+d[i];
		sumd[i+1][1]=sumd[i][1]+d[i];
	}
	for(int i=1,h=1,t=0;i<n<<1;i++)
	{
		if(h<=t&&q[h]<=i-n) h++;
		while(h<=t&&check(q[t],i,0)) t--; 
		q[++t]=i;
		if(i>=n) ans[i-n+1]|=check(q[h],i-n,0);
	}
	for(int i=1,h=1,t=0;i<=n<<1;i++)
	{
		if(h<=t&&q[h]<=i-n) h++;
		while(h<=t&&check(i,q[t],1)) t--; 
		q[++t]=i;
		if(i>n) ans[i-n]|=check(i,q[h],1);
	}
	for(int i=1;i<=n;i++)
		printf(ans[i]?"TAK\n":"NIE\n");
}