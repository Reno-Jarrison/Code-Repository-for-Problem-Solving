#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
struct Hpint 
{
	static const int bit=4,base=10000;
	int len,num[1000];
	Hpint(char *s=NULL)
	{
		memset(num,0,sizeof(num)),len=1;
		if(s==NULL) return;
		int slen=strlen(s),w=1;
		for(int i=0;i<slen;i++,w*=10)
		{
			if(w==base) len++,w=1;
			num[len-1]+=w*(s[slen-i-1]-'0');
		}
	}
	void write()
	{
		printf("%d",num[len-1]);
		for(int i=len-2;~i;i--)
			printf("%0*d",bit,num[i]);
		puts("");
	}
	friend Hpint operator +(const Hpint& x,const Hpint& y)
	{
	    Hpint ans;
	    ans.len=max(x.len,y.len);
	    for(int i=0;i<ans.len;i++)
	    {
	        ans.num[i]+=x.num[i]+y.num[i];
	        if(ans.num[i]>=base) 
	        	ans.num[i]-=base,ans.num[i+1]++;
	    }
	    if(ans.num[ans.len]) ans.len++;
	    return ans;
	}
}fib[maxn];
int main()
{
	fib[1].num[0]=1,fib[2].num[0]=3;
	for(int i=3;i<maxn;i++)
		fib[i]=fib[i-1]+fib[i-2];
	int n;
	while(~scanf("%d",&n))
		fib[n].write();
}