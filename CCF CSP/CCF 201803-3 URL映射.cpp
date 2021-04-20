#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int ok;
vector<string>res;
string rule[maxn],name[maxn];
string offlead(string num)
{
	while(num.size()>1&&num[0]=='0')
		num=num.substr(1);
	return num;
}
void match(string txt,string pat,string cur,vector<string>& arg)
{
	if(ok) return;
	if(txt==""&&pat=="")
	{	res=arg,ok=1; return; }
	if(txt==""||pat=="") return;
	string txt_nxt=txt.substr(1),pat_nxt=pat.substr(1);
	if(txt[0]==pat[0])
		match(txt_nxt,pat_nxt,"",arg);
	if(pat[0]=='@')
	{
		if(txt[0]=='/')
		{
			arg.push_back(cur);
			match(txt,pat_nxt,"",arg);
			arg.pop_back();
		}
		else
		{
			match(txt_nxt,pat,cur+txt[0],arg);
			if(ok) return;		
			arg.push_back(cur+txt[0]);
			match(txt_nxt,pat_nxt,"",arg);
			arg.pop_back();
		}
	}
	if(pat[0]=='#')
	{
		if(txt[0]=='/')
		{
			arg.push_back(offlead(cur));
			match(txt,pat_nxt,"",arg);
			arg.pop_back();
		}
		else if(isdigit(txt[0]))
		{

			match(txt_nxt,pat,cur+txt[0],arg);
			if(ok) return;
			arg.push_back(offlead(cur+txt[0]));
			match(txt_nxt,pat_nxt,"",arg);
			arg.pop_back();
		}
	}
	if(pat[0]=='$')
	{
		arg.push_back(txt);
		match("","","",arg);
		arg.pop_back();
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	string s;
	for(int i=1;i<=n;i++)
	{
		cin>>s>>name[i];
		int endtag=0;
		if(s[s.length()-1]!='/')
			s+='/';
		else endtag=1;
		string pat,cur,tmp;
		for(char x:s)
		{
			if(x=='/'&&tmp!="")
			{
				if(tmp[0]=='<'&&tmp[1]=='s')
					pat+="/@";
				else if(tmp[0]=='<'&&tmp[1]=='i')
					pat+="/#";
				else if(tmp[0]=='<'&&tmp[1]=='p')
					pat+="/$";
				else 
					pat+='/',pat+=tmp;
				tmp="";
			}
			else if(x!='/') tmp+=x;
		}
		if(endtag) pat+='/';
		rule[i]=pat;
	}
	for(int i=1;i<=m;i++)
	{
		string addr;
		cin>>addr;
		vector<string>arg;
		ok=0,res.clear();
		for(int j=1;j<=n&&!ok;j++)
		{
			arg.clear();
			match(addr,rule[j],"",arg);
			if(ok) cout<<name[j];
		}
		if(!ok) cout<<"404";
		else for(string x:res)
			cout<<" "<<x;
		cout<<endl;
	}
}