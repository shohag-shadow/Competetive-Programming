#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
#define endl '\n'
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl        
#define no cout << "NO" << endl          
#define M 1000000007                     
#define lcm(a, b) a *b / gcd(a, b)       
#define memz(a) memset(a, 0, sizeof(a))  
#define memn(a) memset(a, -1, sizeof(a)) 
ll dx[]={1,0,-1,0,1,-1,-1,1};
ll dy[]={0,1,0,-1,1,1,-1,-1};
string field[260];
ll vis[260][260];
pair<ll,ll>dfs(ll x,ll y,ll n,ll m)
{
    if(x<0||x>=n||y<0||y>=m)return {0,0};
    if(field[x][y]=='#')return {0,0};
    if(vis[x][y])return {0,0};
    vis[x][y]=1;
    ll sheep=0;
    ll wolf=0;
    if(field[x][y]=='k')sheep++;
    if(field[x][y]=='v')wolf++;
    for(int i=0;i<4;i++)
    {
        ll x1=x+dx[i];
        ll y1=y+dy[i];
        pair<ll,ll>p=dfs(x1,y1,n,m);
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
    ll n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>field[i];
    ll wolfs=0,sheeps=0;
    for(int i=0;i<n;i++)
    {
        if(field[i][0]!='#')
        {
            pair<ll,ll>x=dfs(i,0,n,m);
            wolfs+=x.first;
            sheeps+=x.second;
        }
        if(field[i][m-1]!='#')
        {
            pair<ll,ll>x=dfs(i,m-1,n,m);
            wolfs+=x.first;
            sheeps+=x.second;
        }
    }
    for(int i=0;i<m;i++)
    {
        if(field[0][i]!='#')
        {
            pair<ll,ll>x=dfs(0,i,n,m);
            wolfs+=x.first;
            sheeps+=x.second;
        }
        if(field[n-1][i]!='#')
        {
            pair<ll,ll>x=dfs(0,i,n,m);
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
                pair<ll,ll>x=dfs(i,j,n,m);
                if(x.second>x.first)sheeps+=x.second;
                else wolfs+=x.first;
            }
        }
    }
    cout<<sheeps<<" "<<wolfs<<endl;
}