#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
char s[maxn];
int main()
{
	int q,l,r;
	cin>>(s+1)>>q;
	while(q--)
	{
		cin>>l>>r;
		puts(l==r||s[l]!=s[r]?"Yes":"No");
	}
}

