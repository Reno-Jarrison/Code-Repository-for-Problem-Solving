#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
int a[maxn],cnt[2];
void print(int x)
{
	printf("%d\n",cnt[x]);
	for(int i=1;i<=cnt[x];i++)
		printf("%d ",x);
}
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		cnt[0]=cnt[1]=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),cnt[a[i]]++;
		if(cnt[0]>=cnt[1]) print(0);
		else
		{
			if(cnt[1]&1) cnt[1]--;
			print(1);
		} 
		puts("");
	}
}