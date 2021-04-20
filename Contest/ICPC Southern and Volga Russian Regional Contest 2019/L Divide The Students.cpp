#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,a,b,c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(a>c) swap(a,c);
		int ans=max(a,(c+1)/2);
		b=max(b-(ans*3-a-c),0); 
		ans+=b/3+(b%3>0);
		printf("%d\n",ans);
	}
}