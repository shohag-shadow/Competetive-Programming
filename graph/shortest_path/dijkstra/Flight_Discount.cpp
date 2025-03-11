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
const ll N=1e5+100;
vector<pair<ll,ll>>graph[N];
const ll inf=100000000000000000;
ll dijkstra(ll n)
{
    ll dis[n+1][2];
    for(int i=1;i<=n;i++)
    {
        dis[i][0]=inf;
        dis[i][1]=inf;
    }
    set<pair<pair<ll,ll>,ll>>pq;
    pq.insert({{0,1},1});
    dis[1][1]=0;
    while(!pq.empty())
    {
        pair<pair<ll,ll>,ll>parent=*pq.begin();
        //cout<<"parent "<<parent.second<<" "<<parent.first.first<<" "<<parent.first.second<<endl;
        pq.erase(pq.begin());
        for(auto child:graph[parent.second])
        {
            if(parent.first.second==1)
            {
                if(dis[child.first][0]>dis[parent.second][1]+child.second/2)
                {
                    pq.erase({{dis[child.first][0],0},child.first});
                    dis[child.first][0]=dis[parent.second][1]+child.second/2;
                    pq.insert({{dis[child.first][0],0},child.first});
                    //cout<<child.first<<" "<<dis[child.first][0]<<endl;
                }
            }
            if(dis[child.first][parent.first.second]>dis[parent.second][parent.first.second]+child.second)
            {
                pq.erase({{dis[child.first][parent.first.second],parent.first.second},child.first});
                dis[child.first][parent.first.second]=dis[parent.second][parent.first.second]+child.second;
                pq.insert({{dis[child.first][parent.first.second],parent.first.second},child.first});
                //cout<<child.first<<" "<<dis[child.first][parent.first.second]<<endl;
            }
        }
    }
    //cout<<dis[2][0]<<endl;
    return min(dis[n][0],dis[n][1]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        ll a,b,w;
        cin>>a>>b>>w;
        graph[a].push_back({b,w});
        //graph[b].push_back({a,w});
    }
    cout<<dijkstra(n)<<endl;
}