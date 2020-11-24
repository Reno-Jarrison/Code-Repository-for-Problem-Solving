#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
char a[maxn],b[maxn],c[maxn];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>c;
		int n=strlen(a),ok=1;
		for(int i=0;i<n;i++)
			if(a[i]!=c[i]&&b[i]!=c[i]) ok=0;
		puts(ok?"YES":"NO");
	}
}