#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
char s[10]; 
int key[26],step[6][3]={{0,1,2}};
int main()
{
	key[0]=0,key['g'-'a']=1,key['o'-'a']=2;
	for(int i=1;i<6;i++)
	{
		for(int j=0;j<3;j++)
			step[i][j]=step[i-1][j];
		next_permutation(step[i],step[i]+3);
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		int ans=0;
		vector<int>v,tmp,del;
		for(int i=0;i<6;i++)
		{
			int cnt=0;
			for(int i=0;i<9;i++)
				v.push_back(key[s[i]-'a']);
			for(int j=0;j<3;j++)
			{
				for(int k=0;k<v.size();k++)
				{
					if(v[k]==step[i][j]) del.push_back(k);
					else tmp.push_back(v[k]);
				}
				if(del[0]+1==del[1]&&del[1]+1==del[2]) cnt++;
				v=tmp,del.clear(),tmp.clear();
			}
			ans=max(ans,cnt);
		}
		printf("%d\n",ans);
	}
}