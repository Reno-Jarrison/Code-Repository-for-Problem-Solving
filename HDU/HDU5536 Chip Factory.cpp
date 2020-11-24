#include<iostream>
using namespace std;
struct Trie
{
	Trie(int n=0):num(n),flag(n)
		{ next[0]=next[1]=NULL; }
	int num,flag;                                       
	Trie *next[2];
}trie;
void del(Trie *rt)
{
	if(rt->next[0]) del(rt->next[0]);
	if(rt->next[1]) del(rt->next[1]);
	if(rt==&trie) rt->next[0]=rt->next[1]=NULL;
	else delete rt;
}
void build(int x)
{
	Trie *pt=&trie;
	int k=0,bit[35]={0},temp=x;
	while(temp)
		bit[k++]=temp&1,temp>>=1;
	for(int j=32;j>=0;j--)
	{
		Trie *tempnode=NULL;
		if(pt->next[bit[j]])
			tempnode=pt->next[bit[j]];
		else
			tempnode=new Trie(),pt->next[bit[j]]=tempnode;
		pt=tempnode,pt->flag++;
	}
	pt->num=x;
}
void changex(int x,int inc)
{
	Trie *pt=&trie;
	int k=0,bit[35]={0};
	while(x)
		bit[k++]=x&1,x>>=1;
	for(int j=32;j>=0;j--)
	{
		pt=pt->next[bit[j]];
		if(inc) pt->flag++;
		else pt->flag--;
	}
}
int num[1005];
int main()
{
	int t,n,temp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		del(&trie);
		for(int i=0;i<n;i++)
			scanf("%d",&num[i]),build(num[i]);
		int maxm=-1;
		for(int i=1;i<n;i++)
			for(int j=0;j<i;j++)
			{
				Trie *pt=&trie;
				int k=0,bit[35]={0};
				temp=num[i]+num[j];
				changex(num[i],0);
				changex(num[j],0);
				int tempxor=temp;
				while(temp)
					bit[k++]=temp&1,temp>>=1;
				for(int k=32;k>=0;k--)
					if(pt->next[!bit[k]]&&pt->next[!bit[k]]->flag)
						pt=pt->next[!bit[k]];
					else pt=pt->next[bit[k]];
				if(maxm<(pt->num^tempxor))
					maxm=(pt->num^tempxor);
				changex(num[i],1);
				changex(num[j],1);
			}
		printf("%d\n",maxm);
	}
}