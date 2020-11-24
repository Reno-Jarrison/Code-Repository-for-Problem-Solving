#include<iostream>
#include<cstring>
#define maxn 1000005
using namespace std;
struct Trie
{
	Trie(int f=0):flag(f)
		{ left=right=NULL; }
	bool flag;
	Trie *left,*right;
}trie;
Trie *pt=NULL;
char temp[maxn];
void delete_trie(Trie *rt)
{
	if(rt->left)
		delete_trie(rt->left);
	if(rt->right)
		delete_trie(rt->right);
	if(rt!=&trie)
		delete rt;
}
int main()
{
	int flag=0,Case=0;
	while(gets(temp))
		if(temp[0]=='9')
		{
			Case++; 
			delete_trie(&trie);
			trie.flag=trie.left=trie.right=0;
			cout<<"Set "<<fixed<<Case<<" is ";
			if(flag)
				cout<<"not ";
			cout<<"immediately decodable"<<endl;
			flag=0;
		}
		else
		{
			int len=strlen(temp),check=0;
			pt=&trie;
			for(int i=0;i<len;i++)
			{
				Trie *tempnode=NULL;
				if(temp[i]=='0')
					if(!pt->left) 
						tempnode=new Trie(),pt->left=tempnode,check=1;
					else tempnode=pt->left;
				else 
					if(!pt->right) 
						tempnode=new Trie(),pt->right=tempnode,check=1;
					else tempnode=pt->right;
				pt=tempnode;
				if(pt->flag)
					flag=1;
			}
			pt->flag=1;
			if(!check)
				flag=1;
		}
} 