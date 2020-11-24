#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int a[maxn],n;
bool judge(int x)
{
	if(x-1<1||x+1>n) return false;
	return a[x]>a[x-1]&&a[x]>a[x+1];
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int tot=0;
		for(int i=1;i<=n;i++)
			tot+=judge(i);
		int ans=tot;
		for(int i=1;i<=n;i++)
		{
			int cnt=0;
			for(int j=i-1;j<=i+1;j++)
				cnt+=judge(j);
			if(i-2>=1&&i+1<=n&&a[i-1]>a[i-2]&&a[i-1]>a[i+1]) cnt--;
			if(i-1>=1&&i+2<=n&&a[i+1]>a[i+2]&&a[i+1]>a[i-1]) cnt--;
			ans=min(ans,tot-cnt);
		}
		printf("%d\n",ans);
	}
}