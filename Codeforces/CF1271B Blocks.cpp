#include<bits/stdc++.h>
using namespace std;
const int maxn=205;
vector<int>ans[2];
char s[maxn];
int tag[2][maxn];
int main()
{
	int n;
	cin>>n>>(s+1);
	for(int i=1;i<=n;i++)
		tag[0][i]=s[i]=='W',tag[1][i]=s[i]=='B';
	for(int i=1;i<n;i++)
		for(int j=0;j<2;j++) if(!tag[j][i])
			tag[j][i]=1,tag[j][i+1]=!tag[j][i+1],ans[j].push_back(i);	
	if(tag[0][n])
	{
		cout<<ans[0].size()<<endl;
		for(int i:ans[0]) printf("%d ",i);
	}
	else if(tag[1][n])
	{
		cout<<ans[1].size()<<endl;
		for(int i:ans[1]) printf("%d ",i);
	}
	else puts("-1");
}