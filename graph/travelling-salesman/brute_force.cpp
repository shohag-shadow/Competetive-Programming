#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll N=1000;
ll dist[N+1][N+1];
ll n;
ll travelling_sales_man(ll node,ll source ,vector<ll>&vis)
{
    ll ans=INT16_MAX;
    vis[node]=1;
    bool flag=false;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            ans=min(ans,dist[node][i]+travelling_sales_man(i,source,vis));
            flag=true;
        }
    }
    vis[node]=0;
    if(flag==false)return dist[node][source];
    else return ans;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>dist[i][j];
        }
    }
    vector<ll>vis(n+1,0);
    cout<<travelling_sales_man(1,1,vis)<<endl;
}

