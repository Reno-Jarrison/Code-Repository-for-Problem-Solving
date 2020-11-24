#include<bits/stdc++.h>
using namespace std;
int s[15],flag[100005];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,ans=0;
		set<int>set;
		cin>>n;
		memset(flag,0,sizeof(flag));
		for(int i=1;i<=n;i++)
			cin>>s[i],set.insert(s[i]);
		for(int i=1;i<=n;i++)
			if(!flag[s[i]])
				flag[s[i]]=true;
			else
			{
				int tmp=s[i]/10*10;
				for(int j=0;j<10;j++)
					if(!flag[tmp+j]&&!set.count(tmp+j))
					{
						flag[tmp+j]=true;
						s[i]=tmp+j;
						break;
					}
				ans++;
			}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++)
		{
			int res[4];
			for(int j=0;j<4;j++)
				res[j]=s[i]%10,s[i]/=10;
			for(int j=3;j>=0;j--)
				cout<<res[j];
			puts("");
		}
	}	
}