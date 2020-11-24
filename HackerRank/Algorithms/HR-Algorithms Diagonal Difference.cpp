#include<iostream>
#include<cmath>
using namespace std;
int a[105][105];
int main()
{
    int n,sum1=0,sum2=0;
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    for(int i=0;i<n;i++)
        sum1+=a[i][i],sum2+=a[i][n-i-1];
    cout<<abs(sum1-sum2);
}