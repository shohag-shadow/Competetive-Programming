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
const ll inf =1000000000000000;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,char>>graph[n+1];
    ll dis[n+1][n+1];
    queue<pair<ll,ll>>q;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            dis[i][j]=inf;
        }
    }
    for(int i=0;i<m;i++)
    {
        ll a,b;
        char c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    for(int i=1;i<=n;i++)
    {
        dis[i][i]=0;
        q.push({i,i});
        for(auto u:graph[i])
        {
            if(dis[i][u.first]==inf)
            {
                dis[i][u.first]=1;
                dis[u.first][i]=1;
                q.push({i,u.first});
            }
        }
    }
    //cout<<"hi"<<endl;
    while(q.size())
    {
        pair<ll,ll> p=q.front();
        q.pop();
        ll d=dis[p.first][p.second]+2;
        for(auto u:graph[p.first])
        {
            for(auto v:graph[p.second])
            {
                if(dis[u.first][v.first]>d&&u.second==v.second)
                {
                    dis[u.first][v.first]=d;
                    dis[v.first][u.first]=d;
                    q.push({u.first,v.first});
                }
            }
        }
    }
    //cout<<"hello"<<endl;
    if(dis[1][n]==inf)cout<<-1<<endl;
    else cout<<dis[1][n]<<endl;

}