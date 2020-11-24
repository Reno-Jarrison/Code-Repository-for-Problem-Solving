#include<iostream>
#include<cmath>
using namespace std;
const double eps=1e-7;
int p[4][3];
int id(int a,int d)
{    return (a+d)%3; }
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<4;i++)
            for(int j=0;j<3;j++)
                cin>>p[i][j];
        int v[3][3];
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                v[i][j]=p[i][j]-p[3][j];
        bool flag=true;
        for(int i=0;i<3;i++)
        {
            int tmp=0;
            for(int j=0;j<3;j++)
                tmp+=(v[i][id(j,1)]*v[id(i,1)][id(j,2)]-v[i][id(j,2)]*v[id(i,1)][id(j,1)])*v[id(i,2)][j];
            if(tmp) flag=false;
        }
        puts(flag?"YES":"NO");
    }
}