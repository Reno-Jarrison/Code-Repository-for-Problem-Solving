#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
const int maxn=6e3+5;
int w[maxn],dp[maxn][2];
vector<int>e[maxn];
void dfs(int u)
{
    dp[u][0]=0,dp[u][1]=w[u];
    for(int v:e[u])
    {
        dfs(v);
        dp[u][0]+=max(dp[v][0],dp[v][1]);
        dp[u][1]+=dp[v][0];
    }
}
int main()
{
    int n,u,v;
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        set<int>st;
        for(int i=1;i<=n;i++)
            cin>>w[i],st.insert(i),e[i].clear();
        while(cin>>v>>u&&v)
            e[u].push_back(v),st.erase(v);
        int rt=*st.begin();
        dfs(rt);
        cout<<max(dp[rt][0],dp[rt][1])<<endl;
    }
}