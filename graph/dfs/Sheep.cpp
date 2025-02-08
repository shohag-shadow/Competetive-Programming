#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<long long int, null_type, less<long long int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
long long int dx[]={1,0,-1,0,1,-1,-1,1};
long long int dy[]={0,1,0,-1,1,1,-1,-1};
string field[260];
long long int vis[260][260];
pair<long long int,long long int>dfs(long long int x,long long int y,long long int n,long long int m)
{
    if(x<0||x>=n||y<0||y>=m)return {0,0};
    if(field[x][y]=='#')return {0,0};
    if(vis[x][y])return {0,0};
    vis[x][y]=1;
    long long int sheep=0;
    long long int wolf=0;
    if(field[x][y]=='k')sheep++;
    if(field[x][y]=='v')wolf++;
    for(int i=0;i<4;i++)
    {
        long long int x1=x+dx[i];
        long long int y1=y+dy[i];
        pair<long long int,long long int>p=dfs(x1,y1,n,m);
        wolf+=p.first;
        sheep+=p.second;
    }
    return {wolf,sheep};
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>field[i];
    long long int wolfs=0,sheeps=0;
    for(int i=0;i<n;i++)
    {
        if(field[i][0]!='#')
        {
            pair<long long int,long long int>x=dfs(i,0,n,m);
            wolfs+=x.first;
            sheeps+=x.second;
        }
        if(field[i][m-1]!='#')
        {
            pair<long long int,long long int>x=dfs(i,m-1,n,m);
            wolfs+=x.first;
            sheeps+=x.second;
        }
    }
    for(int i=0;i<m;i++)
    {
        if(field[0][i]!='#')
        {
            pair<long long int,long long int>x=dfs(0,i,n,m);
            wolfs+=x.first;
            sheeps+=x.second;
        }
        if(field[n-1][i]!='#')
        {
            pair<long long int,long long int>x=dfs(0,i,n,m);
            wolfs+=x.first;
            sheeps+=x.second;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(field[i][j]!='#')
            {
                pair<long long int,long long int>x=dfs(i,j,n,m);
                if(x.second>x.first)sheeps+=x.second;
                else wolfs+=x.first;
            }
        }
    }
    cout<<sheeps<<" "<<wolfs<<'\n';
}