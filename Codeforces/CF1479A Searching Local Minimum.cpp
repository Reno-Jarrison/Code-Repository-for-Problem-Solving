#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int a[maxn];
int ask(int x)
{
	if(a[x]) return a[x];
	printf("? %d\n",x);
	fflush(stdout);
	int pos;
	scanf("%d",&pos);
	return a[x]=pos;
}
void answer(int x)
{
	printf("! %d\n",x);
	fflush(stdout);
}
int main()
{
	int n,l,r;
	scanf("%d",&n);
	l=1,r=n;
	a[0]=a[n+1]=n+1;
	while(l<=r)
	{
		int mid=(l+r)>>1,mval=ask(mid);
		int lval=ask(mid-1),rval=ask(mid+1);
		if(mval<lval&&mval<rval)
		{	answer(mid); break; }
		if(mval<lval) l=mid+1;
		else r=mid-1;
	}
}