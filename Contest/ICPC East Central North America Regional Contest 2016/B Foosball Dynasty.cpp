#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
char name[15][105],s[maxn];
int id[2][2],cur[2],flag[2],mxv,tot;
pair<int,int>ans[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%s",name[i]);
	id[0][0]=1,id[1][0]=2;
	id[0][1]=3,id[1][1]=4;
	flag[0]=flag[1]=1;
	queue<int>que;
	for(int i=5;i<=n;i++)
		que.push(i);
	scanf("%s",s);
	int len=strlen(s);
	for(int i=0;i<len;i++)
	{
		int tag=s[i]=='B'; 
		int w0=id[tag][0],w1=id[tag][1];
		int l0=id[!tag][0],l1=id[!tag][1];
		cur[tag]++,cur[!tag]=0;
		if(cur[tag]==mxv)
			ans[++tot]=flag[tag]?make_pair(w0,w1):make_pair(w1,w0);
		else if(cur[tag]>mxv)
			ans[tot=1]=flag[tag]?make_pair(w0,w1):make_pair(w1,w0),mxv=cur[tag];
		swap(id[tag][0],id[tag][1]);
		flag[tag]^=1,flag[!tag]=0;
		id[!tag][1]=l0,id[!tag][0]=que.front();
		que.pop(),que.push(l1);
	}
	for(int i=1;i<=tot;i++)
		printf("%s %s\n",name[ans[i].first],name[ans[i].second]);
}