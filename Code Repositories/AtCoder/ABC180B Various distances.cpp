#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	long long md=0,cd=0,x;
	double ed=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&x);
		md+=abs(x);
		ed+=x*x;
		cd=max(cd,abs(x));
	}
	ed=sqrt(ed);
	printf("%lld\n%.10lf\n%lld\n",md,ed,cd);
}