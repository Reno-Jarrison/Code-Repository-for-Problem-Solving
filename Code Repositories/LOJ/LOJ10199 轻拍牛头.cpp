#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6+5;
int cnt[maxn],a[maxn],ans[maxn];
int main()
{
	int n,maxa=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),cnt[a[i]]++,maxa=max(maxa,a[i]);
	for(int i=1;i<=maxa;i++)
		for(int j=i;j<=maxa;j+=i)
			ans[j]+=cnt[i]; 
	for(int i=1;i<=n;i++) printf("%d\n",ans[a[i]]-1);
}