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
string sea[1000];
ll vis[1000][1000];
ll dfs(ll x,ll y,ll n,ll m)
{
    if(x>=n||x<0||y>=m||y<0)return 0;
    if(sea[x][y]!='#')return 0;
    if(vis[x][y]==1)return 0;
    vis[x][y]=1;
    ll ans=1;
    for(int i=0;i<4;i++)
    {
        ll x1=x+dx[i];
        ll y1=y+dy[i];
        ans+=dfs(x1,y1,n,m);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tst;
    cin>>tst;
    for(ll test=1;test<=tst;test++)
    {
        //cout<<"Case "<<test<<": ";
        ll n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)vis[i][j]=0;
        }
        for(int i=0;i<n;i++)
        {
            cin>>sea[i];
        }
        ll se=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(sea[i][j]=='#'&&vis[i][j]==0)
                {
                    ll x=dfs(i,j,n,m);
                    se+=x*x;
                }
            }
        }
        ll d=__gcd(se,n*m);
        ll p=se/d;
        ll q=(n*m)/d;
        if(p==0)cout<<0<<endl;
        else if(q==1)cout<<p<<endl;
        else cout<<p<<" / "<<q<<endl;
    }
}