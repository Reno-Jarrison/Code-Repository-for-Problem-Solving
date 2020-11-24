#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
char s[maxn];
int main()
{
	int n,l,r,ans=0;
	scanf("%d%s",&n,s+1);
	l=1,r=n;
	while(l<r)
	{
		while(l<r&&s[l]=='R') l++;
		while(l<r&&s[r]=='W') r--;
		if(l<r) ans++;
		l++,r--;
	}
	printf("%d",ans);
}