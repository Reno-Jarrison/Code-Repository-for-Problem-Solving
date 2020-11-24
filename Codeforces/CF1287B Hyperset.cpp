#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1505;
string s[maxn];
int key[26];
char val[4]="SET";
int main()
{
	int n,k;
	cin>>n>>k;
	set<string>st[maxn];
	key['S'-'A']=0;
	key['E'-'A']=1;
	key['T'-'A']=2;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=n;i;i--)
		st[i]=st[i+1],st[i].insert(s[i]);
	ll ans=0;
	for(int i=1;i<n;i++)
		for(int j=i+1;j<n;j++)
		{
			string tmp=s[i];
			for(int p=0;p<k;p++)
			{
				int chx=s[i][p]-'A',chy=s[j][p]-'A';
				tmp[p]=chx==chy?chx+'A':val[3-key[chx]-key[chy]];
			}
			ans+=st[j+1].count(tmp);
		}
	cout<<ans;
}