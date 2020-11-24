#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
int a[maxn],b[maxn];
int check(int n)
{
	int num=a[0];
	for(int i=1;i<n;i++)
		if(a[i]!=num) return -1;
	return num;
}
int main()
{
	int n;
	while(scanf("%d",&n)&&n)
	{
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		int ans=0;
		while(check(n)==-1)
		{
			ans++;
			for(int i=0;i<n;i++)
				b[i]=a[i]/2,a[i]-=b[i];
			for(int i=0;i<n;i++)
				a[(i+1)%n]+=b[i];
			for(int i=0;i<n;i++)
				if(a[i]&1) a[i]++;
		}
		printf("%d %d\n",ans,check(n));
	}
}