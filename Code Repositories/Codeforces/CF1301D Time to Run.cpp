#include<bits/stdc++.h>
using namespace std;
vector<int>ans1;
vector<string>ans2;
void push(int x,string s)
{	if(x) ans1.push_back(x),ans2.push_back(s); }
int main()
{
	int n,m,k,tmp;
	cin>>n>>m>>k;
	if(4*n*m-2*n-2*m<k) 
	{	puts("NO"); return 0; }
	puts("YES");
	tmp=min(k,m-1),push(tmp,"R"),k-=tmp;
	tmp=min(k,m-1),push(tmp,"L"),k-=tmp;
	int len=4*m-3,p=min(k/len,n-1);
	k-=p*len;
	for(int i=1;i<=p;i++)
		push(m-1,"DRU"),push(1,"D"),push(m-1,"L");
	if(p==n-1) tmp=min(k,n-1),push(tmp,"U"),k-=tmp;
	else if(k)
	{
		p=min(m-1,k/3),k-=p*3,push(p,"DRU");
		if(p<m-1&&k) push(1,k==1?"D":"DR");
		else if(k) push(1,"D"),push(--k,"L");
	}
	int step=ans1.size();
	cout<<step<<endl;
	for(int i=0;i<step;i++)
		cout<<ans1[i]<<" "<<ans2[i]<<endl;
}