#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
int a[maxn],id[maxn],mnv[maxn],mxv[maxn];
int main()
{
	int n,m,x;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		a[i]=i,id[i]=i,mnv[i]=i,mxv[i]=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&x);
		int pos=id[x];
		if(pos!=1)
		{
			int pre=a[pos-1];
			mnv[x]=min(mnv[x],pos-1);
			mxv[pre]=max(mxv[pre],pos);
			id[x]=pos-1,id[pre]=pos;
			swap(a[pos],a[pos-1]);
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d %d\n",mnv[i],mxv[i]);
}