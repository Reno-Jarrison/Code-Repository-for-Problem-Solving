#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
int a[maxn],d[maxn],pos1[maxn],pos2[maxn];
int main()
{
	int t,n,base;
	cin>>t;
	while(t--)
	{
		cin>>n,base=n;
		for(int i=1;i<=2*n;i++) 
		{
			cin>>a[i];
			if(a[i]==2) a[i]=-1;
		}
		memset(d,0,sizeof(d));
		memset(pos1,-1,sizeof(pos1));
		memset(pos2,-1,sizeof(pos2));		
		pos1[base]=0,pos2[base]=2*n+1;
		for(int i=1;i<=n;i++) 
			d[i]=d[i-1]+a[i],pos1[d[i]+base]=i;
		for(int i=2*n;i>n;i--)
			d[i]=d[i+1]+a[i],pos2[d[i]+base]=i;
		int ans=n*2;
		for(int i=-n;i<=n;i++)
			if(pos1[i+base]!=-1&&pos2[-i+base]!=-1)
				ans=min(ans,pos2[-i+base]-pos1[i+base]-1);
		cout<<ans<<endl;
	}
}