#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
#define endl '\n'
template <class T> using pbds= tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; // find_by_order, order_of_key
#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl        
#define no cout << "NO" << endl          
#define M 1000000007                     
#define lcm(a, b) a *b / gcd(a, b)       
#define memz(a) memset(a, 0, sizeof(a))  
#define memn(a) memset(a, -1, sizeof(a)) 
ll dx[]={1,0,-1,0,1,-1,-1,1};
ll dy[]={0,1,0,-1,1,1,-1,-1};
const ll inf=10000000000000000;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m,q;
    cin>>n>>m>>q;
    ll dis[n+1][n+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            dis[i][j]=inf;
        }
        dis[i][i]=0;
    }
    for(int i=0;i<m;i++)
    {
        ll a,b,v;
        cin>>a>>b>>v;
        dis[a][b]=min(dis[a][b],v);
        dis[b][a]=dis[a][b];
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--)
    {
        ll a,b;
        cin>>a>>b;
        if(dis[a][b]==inf)cout<<-1<<endl;
        else cout<<dis[a][b]<<endl;
    }
}