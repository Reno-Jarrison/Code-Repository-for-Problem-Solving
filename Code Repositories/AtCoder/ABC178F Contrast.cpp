#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int a[maxn],b[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=n;i;i--)
		scanf("%d",&b[i]);
	int pt=0,ok=1;
	for(int i=1;ok&&i<=n;i++)
	{
		if(a[i]^b[i]) continue;
		while(++pt<=n)
			if(a[i]!=b[pt]&&a[pt]!=b[i]) 
			{	swap(b[i],b[pt]); break; }
		if(a[i]==b[i]) ok=0;
	}
	if(!ok) puts("No");
	else
	{
		puts("Yes");
		for(int i=1;i<=n;i++)
			printf("%d ",b[i]);
	}
}