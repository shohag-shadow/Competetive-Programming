#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
#define endl '\n'
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define all(v) v.begin(), v.end()
#define pb push_back //
#define mp make_pair
#define fi first                         //
#define se second                        //
#define yes cout << "YES" << endl        //
#define no cout << "NO" << endl          //
#define M 1000000007                     // 1e9+7
#define gcd(a, b) __gcd(a, b)            //
#define lcm(a, b) a *b / gcd(a, b)       //
#define memz(a) memset(a, 0, sizeof(a))  //
#define memn(a) memset(a, -1, sizeof(a)) //
pair<ll,ll>source;
pair<ll,ll>des;
map<pair<ll,ll>,ll>allowed;
void bfs()
{
    map<pair<ll,ll>,ll>vis;
    map<pair<ll,ll>,ll>dis;
    vis[source]=1;
    dis[source]=0;
    queue<pair<ll,ll>>q;
    q.push(source);
    while(q.size())
    {
        pair<ll,ll>par=q.front();
        q.pop();
        if(par==des)
        {
            cout<<dis[par]<<endl;
            return;
        }
        for(int i=-1;i<2;i++)
        {
            for(int j=-1;j<2;j++)
            {
                pair<ll,ll>child={par.first+i,par.second+j};
                if(allowed[child]==1&&vis[child]==0)
                {
                    vis[child]=1;
                    dis[child]=dis[par]+1;
                    q.push(child);
                }
            }
        }
    }
    cout<<-1<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    source={x1,y1};
    des={x2,y2};
    ll m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        ll r,a,b;
        cin>>r>>a>>b;
        for(int i=a;i<=b;i++)
        {
            allowed[{r,i}]=1;
        }
    }
    bfs();

}