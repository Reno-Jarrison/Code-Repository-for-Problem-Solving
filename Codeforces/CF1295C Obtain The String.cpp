#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
char s[maxn],t[maxn];
int idx[maxn][26];
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>(s+1)>>(t+1);
		int slen=strlen(s+1),tlen=strlen(t+1);
		for(int i=0;i<26;i++) idx[slen][i]=-1;
		for(int i=slen-1;i>=0;i--)
		{
			for(int j=0;j<26;j++)
				idx[i][j]=idx[i+1][j];
			idx[i][s[i+1]-'a']=i+1;
		}
		int pt=0,ans=1;
		for(int i=1;i<=tlen;i++)
			if(idx[pt][t[i]-'a']==-1)
			{
				if(pt==0) { ans=-1; break; }
				ans++,pt=0,i--;
			}
			else pt=idx[pt][t[i]-'a'];
		cout<<ans<<endl;
	}
}