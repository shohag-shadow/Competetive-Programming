#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<long long int, null_type, less<long long int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
long long int dx[]={1,0,-1,0,1,-1,-1,1};
long long int dy[]={0,1,0,-1,1,1,-1,-1};
bool ans;
pair<long long int,long long int> dfs(long long int source,long long int flag,vector<long long int>graph[],vector<long long int>&vis,vector<long long int>&out)
{
    vis[source]=1;
    out[source]=flag;
    //cout<<source<<" ";
    
    pair<long long int,long long int>p={0,0};
    if(flag==0)p.second++;
    else p.first++;
    for(auto child:graph[source])
    {
        if(out[child]==flag)ans=false;
        if(vis[child]==0)
        {
            pair<long long int,long long int>x=dfs(child,!flag,graph,vis,out);
            p.first+=x.first;
            p.second+=x.second;
        }
    }
    return p;
}
long long int binary_expo(long long int a,long long int b)
{
    long long int ans=1;
    while(b)
    {
        if(b%2)ans=(ans*a)%998244353                     ;
        a=(a*a)%998244353                     ;
        b/=2;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int tst;
    cin>>tst;
    for(long long int test=1;test<=tst;test++)
    {
        //cout<<"Case "<<test<<": ";
        long long int n,m;
        cin>>n>>m;
        vector<long long int>graph[n+2];
        vector<long long int>vis(n+1,0);
        for(int i=0;i<m;i++)
        {
            long long int a,b;
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        ans=1;
        vector<long long int>out(n+1,-1);
        long long int x=1;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                pair<long long int,long long int>p=dfs(i,0,graph,vis,out);
                long long int zero=p.first,one=p.second;
                x=(x*((binary_expo(2,zero)+binary_expo(2,one))%998244353))%998244353;
            }
            if(ans==0)break;
        }
        if(ans)
        {
            cout<<x<<'\n';
        }
        else
        {
            cout<<0<<'\n';
        }
        
    }
}