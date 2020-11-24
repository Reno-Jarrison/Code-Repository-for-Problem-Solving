#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int a[maxn];
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int l=1,r=n,cnt=0;
		for(int i=1,ok=1;ok&&i<=n;i++)
			a[i]==i?l++:ok=0;
		for(int i=n,ok=1;ok&&i;i--)
			a[i]==i?r--:ok=0;
		for(int i=l;i<=r;i++)
			if(a[i]==i) cnt++;
		if(l>=r) puts("0");
		else if(!cnt) puts("1");
		else puts("2");
	}
}