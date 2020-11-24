#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
int cnt[maxn],ans[maxn][2];
int main()
{
	int k,n;
	string s,t;
	cin>>k;
	while(k--)
	{
		memset(cnt,0,sizeof(cnt));
		cin>>n>>s>>t;
		bool ok=true;
		for(int i=0;i<n;i++)
			cnt[s[i]-'a']++,cnt[t[i]-'a']++;
		for(int i=0;i<26;i++)
			if(cnt[i]&1) ok=false;
		if(!ok) puts("No");
		else 
		{
			int pt=0;
			puts("Yes");
			for(int i=0;i<n;i++)
			{
				if(s[i]==t[i]) continue;
				for(int j=i+1;j<n;j++)
				{
					if(s[i]==s[j])
					{	swap(t[i],s[j]),ans[++pt][0]=j,ans[pt][1]=i; break; }
					else if(s[i]==t[j])
					{
						swap(s[j],t[j]),ans[++pt][0]=j,ans[pt][1]=j;
						swap(t[i],s[j]),ans[++pt][0]=j,ans[pt][1]=i;
						break;
					}			
				}
			} 
			cout<<pt<<endl;
			for(int i=1;i<=pt;i++)
				cout<<ans[i][0]+1<<" "<<ans[i][1]+1<<endl;
		} 
	}
}

