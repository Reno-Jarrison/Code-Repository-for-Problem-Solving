#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a,b,cnt=0,ok=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		a==b?cnt++:cnt=0;
		if(cnt==3) ok=1;
	}
	puts(ok?"Yes":"No");
}