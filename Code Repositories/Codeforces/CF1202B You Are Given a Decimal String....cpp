#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll vis[10][10],ans[10][10],key[10][10][10][10];
int main()
{
	string s;
	cin>>s;
	int len=s.size();
	memset(key,0x3f,sizeof(key));
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			for(int k=0;k<10;k++)
				for(int m=9;m>=0;m--)
					for(int n=9;n>=0;n--)
					{
						if(m+n==0) continue;
						int l=(i+j*m+k*n)%10;
						key[i][l][j][k]=min(key[i][l][j][k],(ll)m+n);
					}
	for(int i=1;i<len;i++)
		vis[s[i-1]-'0'][s[i]-'0']++;
	for(int i=0;i<10;i++)
		for(int j=i;j<10;j++)
		{
			ll cnt=0;
			for(int k=0;k<10;k++)	
			{
				for(int l=0;l<10;l++)
				{
					if(!vis[k][l]) continue;
					int x=key[k][l][i][j];
					if(x<20) cnt+=(x-1)*vis[k][l];
					else { cnt=-1; break; }
				}
				if(cnt==-1) break;
			}
			ans[i][j]=ans[j][i]=cnt;
		}
	for(int i=0;i<10;i++) 
	{
		for(int j=0;j<10;j++) 
			cout<<ans[i][j]<<" ";
		cout<<endl;
	}
}

