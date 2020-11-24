#include<bits/stdc++.h>
#define ll long long
using namespace std;
char chr[3]={'R','P','S'};
int getid(char x)
{
	if(x=='R') return 0;
	else if(x=='P') return 1;
	else return 2;
}
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		int cnta[3],cntb[3]={0},pt=0,idx[105];
		char str[105]={0},txt[105]={0};
		cin>>n;
		for(int i=0;i<3;i++) cin>>cnta[i];
		cin>>(str+1);
		for(int i=1;i<=n;i++) cntb[getid(str[i])]++;
		int ans=min(cnta[0],cntb[2])+min(cnta[1],cntb[0])+min(cnta[2],cntb[1]);
		if(ans*2<n) { puts("NO"); continue; }
		puts("YES");
		for(int i=1;i<=n;i++)
		{
			int id=(getid(str[i])+1)%3;
			if(cnta[id]) txt[i]=chr[id],cnta[id]--;
			else idx[++pt]=i;
		}
		for(int i=1;i<=pt;i++)
			for(int j=0;j<3;j++)
				if(cnta[j]) { txt[idx[i]]=chr[j],cnta[j]--; break; }
		cout<<(txt+1)<<endl;
	}
}

