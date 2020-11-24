#include<bits/stdc++.h>
using namespace std;
const int maxn=7e4;
int s[maxn],key[maxn],stk[maxn];
int main()
{
  int t,m,n0,n,x,ks=0;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d%d%d",&m,&n0,&n),n0++,n++;
    memset(key,-1,sizeof(key));
    for(int i=1;i<=n0;i++)
      scanf("%d",&x),key[x]=i;
    for(int i=1;i<=n;i++)
      scanf("%d",&s[i]),s[i]=key[s[i]];
    int top=0,ans=1;
    stk[++top]=s[1];
    for(int i=2;i<=n;i++)
    {
      int id=lower_bound(stk+1,stk+top+1,s[i])-stk;
      stk[id]=s[i],ans=max(ans,id);
      if(top<id) top++;
    }
    printf("Case %d: %d\n",++ks,ans);
  }
}
