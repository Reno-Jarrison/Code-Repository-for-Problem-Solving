#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int a[maxn],b[maxn],n;
bool check(int *s)
{
	int cnt=0;
	for(int i=2;i<=n;i++)
		if(s[i]<s[i-1])
		{
			if(s[i+1]<s[i-1]&&s[i]<s[i-2])
				return false;
			cnt++;
		}
	return cnt<=1;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),b[n-i+1]=a[i];
		a[n+1]=b[n+1]=1e6;
		puts(check(a)||check(b)?"YES":"NO");
	}
}