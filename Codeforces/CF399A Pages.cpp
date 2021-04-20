#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,p,k;
	scanf("%d%d%d",&n,&p,&k);
	int l=max(1,p-k),r=min(n,p+k);
	if(l>1) printf("<< ");
	for(int i=l;i<=r;i++)
	{
		if(i==p) putchar('(');
		printf("%d%c",i,i==p?')':' ');
		if(i==p) putchar(' ');
	}
	if(r<n) printf(">>");
	puts("");
}