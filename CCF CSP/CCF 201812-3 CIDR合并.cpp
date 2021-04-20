#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
const ll lim=(1ll<<32)-1;
struct ip
{	
	ll addr; int len; 
	ip(ll addr=0,int len=0):addr(addr),len(len){}
}p[maxn],q[maxn];
bool operator <(const ip& a,const ip& b)
{	return a.addr<b.addr||(a.addr==b.addr&&a.len<b.len); }
ll pow256[4];
ll cal(ll x,int len)
{	return x&(lim<<len); }
bool contain(ip a,ip b)
{	return a.addr==cal(b.addr,32-a.len); }
bool check(ip a,ip b)
{
	if(a.len!=b.len) 
		return false;
	ip c=ip(cal(a.addr,32-a.len+1),a.len-1);
	return contain(c,a)&&contain(c,b);
}
int main()
{
	int n;
	char s[25];
	pow256[0]=1;
	for(int i=1;i<=3;i++)
		pow256[i]=pow256[i-1]*256;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		int slen=strlen(s),cnt=3,buf=0,tag=0;
		for(int j=0;j<=slen;j++)
		{
			if(isdigit(s[j]))
				buf=buf*10+s[j]-'0';
			else if(tag) break;
			else
			{
				p[i].addr+=pow256[cnt]*buf;
				buf=0,cnt--;
				if(s[j]=='/') tag=1;
			}
		}
		p[i].len=tag?buf:32-(cnt+1)*8;
	}
	sort(p+1,p+n+1);
	int tot=1;
	for(int i=2;i<=n;i++)
		if(!contain(p[tot],p[i]))
			p[++tot]=p[i];
	deque<ip>deq;
	for(int i=1;i<=tot;i++)
	{
		ip cur=p[i];
		while(deq.size())
		{
			ip las=deq.back();
			if(check(cur,las))
			{
				cur=ip(cal(cur.addr,32-cur.len+1),cur.len-1);
				deq.pop_back();
			}
			else break;
		}
		deq.push_back(cur);
	}
	int tmp[4];
	while(!deq.empty())
	{
		ip cur=deq.front();
		deq.pop_front();
		ll addr=cur.addr;
		for(int i=3;~i;i--)
			tmp[i]=addr%256,addr/=256;
		printf("%d.%d.%d.%d/%d\n",tmp[0],tmp[1],tmp[2],tmp[3],cur.len);
	}
}