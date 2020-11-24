#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int ans[maxn],a[5],tmp[5];
bool check(int fst,int n)
{
	int pt=fst;
	for(int i=0;i<4;i++)
		tmp[i]=a[i];
	if(!tmp[fst]) return false;
	for(int i=1;i<=n;i++)
	{
		ans[i]=pt,tmp[pt]--;
		if(i==n) break;
		if(pt&&tmp[pt-1]) pt--;
		else if(tmp[pt+1]) pt++;
		else return false;
	}
	return true;
}
int main()
{
	int n=0;
	for(int i=0;i<4;i++)
		scanf("%d",&a[i]),n+=a[i];
	for(int i=0;i<4;i++) if(check(i,n))
	{
		puts("YES");
		for(int j=1;j<=n;j++)
			printf("%d ",ans[j]);
		return 0;
	}
	puts("NO");
}