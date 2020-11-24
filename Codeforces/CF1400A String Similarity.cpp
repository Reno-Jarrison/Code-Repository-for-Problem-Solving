#include<bits/stdc++.h>
using namespace std;
char s[200],ans[100];
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%s",&n,s);
		for(int i=0;i<n;i++)
			ans[i]=s[i*2];
		ans[n]=0;
		printf("%s\n",ans);
	}
}