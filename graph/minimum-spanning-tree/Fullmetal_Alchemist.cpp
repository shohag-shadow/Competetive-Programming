#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
ll par[10000];
ll find_par(ll n)
{
    if(par[n]==n)return n;
    else return par[n]=find_par(par[n]);
}
bool union_set(ll a,ll b)
{
    a=find_par(a);
    b=find_par(b);
    if(a==b)return false;
    par[a]=b;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    string arr[n+1];
    ll dis[n+1][n+1];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)dis[i][j]=0;
    }
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                dis[j][k]=max(dis[j][k],(ll)abs(arr[j][i]-arr[k][i]));
            }
        }
    }
    for(int i=0;i<=n;i++)
    {
        par[i]=i;
    }
    ll ans=0;
    multiset<pair<ll,pair<ll,ll>>>q;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            q.insert({dis[i][j],{i,j}});
        }
    }
    while(q.size())
    {
        pair<ll,pair<ll,ll>>t=*q.begin();
        q.erase(q.begin());
        if(union_set(t.second.first,t.second.second))
        {
            ans=max(ans,t.first);
        }
    }
    cout<<ans<<endl;
}