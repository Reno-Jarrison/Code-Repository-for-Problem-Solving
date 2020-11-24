#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
char s[maxn];
int main()
{
	int n,cnt[2]={0};
	cin>>n>>s;
	for(int i=0;i<n;i++)
		cnt[s[i]=='L']++;
	cout<<cnt[0]+cnt[1]+1;
}