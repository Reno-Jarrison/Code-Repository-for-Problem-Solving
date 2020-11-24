#include<iostream>
#include<algorithm>
using namespace std;
int a[200005],ans[200005];
int main()
{
	int n,sum=0,ans,minid=1,maxid;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(maxid=1;maxid<=n&&a[maxid]-a[1]<=5;maxid++) sum++;
	ans=sum;
	while(maxid<=n)
	{
		if(a[maxid]-a[minid]>5) sum--,minid++;
		else maxid++,sum++,ans=max(sum,ans);
	}
	printf("%d",ans);
}