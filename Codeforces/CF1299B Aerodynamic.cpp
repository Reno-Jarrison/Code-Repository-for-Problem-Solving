#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int px[maxn],py[maxn],nx[maxn],ny[maxn];
int main()
{
	int n,cx,cy,m;
	cin>>n,m=n/2;
	for(int i=1;i<=n;i++)
		cin>>px[i]>>py[i];
	cx=(px[1]+px[m+1]);
	cy=(py[1]+py[m+1]);
	for(int i=1;i<=m;i++)
		nx[i+m]=cx-px[i],ny[i+m]=cy-py[i];
	for(int i=m+1;i<=n;i++)
		nx[i-m]=cx-px[i],ny[i-m]=cy-py[i];
	bool ok=!(n&1);
	for(int i=1;i<=n&&ok;i++)
		if(px[i]!=nx[i]||py[i]!=ny[i]) ok=false;
	puts(ok?"YES":"NO");
}