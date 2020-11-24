#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
char s[maxn],txt[maxn];
int id[128];
struct tree
{	int mxv,mnv,sum; }t[maxn<<2];
void update(int rt,int pos,int l,int r,int val)
{
	if(l==r)
	{	t[rt].mxv=val,t[rt].mnv=val,t[rt].sum=val; return; }
	int lson=rt<<1,rson=lson|1,mid=(l+r)>>1;
	if(pos<=mid) update(lson,pos,l,mid,val);
	if(pos>mid) update(rson,pos,mid+1,r,val);
	t[rt].mxv=max(t[lson].mxv,t[lson].sum+t[rson].mxv);
	t[rt].mnv=min(t[lson].mnv,t[lson].sum+t[rson].mnv);
	t[rt].sum=t[lson].sum+t[rson].sum;
}
int main()
{
	int n,pt=1;
	id['(']=1,id[')']=-1;
	cin>>n>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='R') pt++;
		else if(s[i]=='L')
		{	if(pt>1) pt--; } 
		else update(1,pt,1,n,id[(int)s[i]]);
		if(t[1].sum==0&&t[1].mnv>=0) printf("%d ",t[1].mxv);
		else printf("-1 ");
	}
}