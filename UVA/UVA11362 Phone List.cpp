#include<iostream>
#include<cstring>
using namespace std;
char temp[11];
struct Trie
{
	int next[10],flag;
}trie[400005];
int main()
{
	ios::sync_with_stdio(false);
	int t,n,suffix,k;
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(trie,0,sizeof(trie));
		suffix=k=0;
		for(int i=0;i<n;i++)
		{
			cin>>temp;
			int len=strlen(temp),rt=0,flag=0;
			for(int j=0;j<len;j++)
			{
				int pos=temp[j]-'0';
				if(trie[rt].flag&&!flag) 
					{ suffix=1; break; }
				if(!trie[rt].next[pos])
					trie[rt].next[pos]=++k,flag=1;
				rt=trie[rt].next[pos];
			}
			trie[rt].flag=1;
			if(!flag) suffix=1;
		}		
		if(suffix) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
 } 