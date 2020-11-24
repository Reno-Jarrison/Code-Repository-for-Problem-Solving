#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5,base=1e4;
char s[maxn][30];
int l[maxn],r[maxn];
int main()
{
	int n,x,sl=0,sr=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s%d",s[i],&x),x*=100;
		l[i]=max(0,x-50),r[i]=min(base,x+49);
		sl+=l[i],sr+=r[i];
	}
	if(sl<=base&&base<=sr)
	{
		for(int i=1;i<=n;i++)
		{
			int L=max(l[i],r[i]-(sr-base));
			int R=min(r[i],l[i]+(base-sl));
			printf("%s %d.%02d %d.%02d\n",s[i],L/100,L%100,R/100,R%100);
		}
	}
	else puts("IMPOSSIBLE");
}