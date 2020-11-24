#include<iostream>
#define ll long long
using namespace std;
struct Trie
{
	Trie(ll n=0):num(n)
		{ next[0]=next[1]=NULL; }
	ll num;
	Trie *next[2];
}trie;

void del(Trie *rt)
{
	for(int i=0;i<2;i++)
		if(rt->next[i]) del(rt->next[i]);
	if(rt==&trie) rt->next[0]=rt->next[1]=NULL;
	else delete rt; 
}
int main()
{
	int t,n,m,k;
	ll temp,num;
	scanf("%d",&t);
	for(int ii=0;ii<t;ii++)
	{
		del(&trie);
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
		{
			int k=0,bit[35]={0};
			Trie *pt=&trie;
			scanf("%lld",&temp);
			num=temp;
			while(temp)
				bit[k++]=temp&1,temp>>=1;
			for(int j=32;j>=0;j--)
			{
				Trie *tempnode=NULL;
				if(pt->next[bit[j]])
					tempnode=pt->next[bit[j]];
				else
					tempnode=new Trie(),pt->next[bit[j]]=tempnode;
				pt=tempnode;
			}
			pt->num=num;
		}
		printf("Case #%d:\n",ii+1);
		for(int i=0;i<m;i++)
		{
			int k=0,max=-1,bit[35]={0};
			Trie *pt=&trie;
			scanf("%lld",&temp);
			while(temp)
				bit[k++]=temp&1,temp>>=1;
			for(int j=32;j>=0;j--)
				if(pt->next[!bit[j]])
					pt=pt->next[!bit[j]];
				else pt=pt->next[bit[j]];
			printf("%lld\n",pt->num);
		}
	}
}