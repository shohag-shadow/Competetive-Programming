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
void dijkstra(vector<ll>&dis)
{
    dis[1]=0;
    pbds<pair<ll,ll>>pq;
    pq.insert({0,1});
    while(!pq.empty())
    {
        pair<ll,ll>parent=*pq.begin();
        pq.erase(pq.begin());
        for(auto child:graph[parent.second])
        {
            if(dis[child.first]>dis[parent.second]+child.second)
            {
                ll pos=pq.order_of_key({dis[child.first],child.first});
                if(pos!=pq.size())
                {
                    if(*pq.find_by_order(pos)==make_pair(dis[child.first],child.first))
                    {
                        pq.erase(pq.find_by_order(pos));
                    }
                }
                dis[child.first]=dis[parent.second]+child.second;
                pq.insert({dis[child.first],child.first});
            }
        }
    }
    return;
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
        ll a,b,v;
        cin>>a>>b>>v;
        graph[a].push_back({b,v});
        //graph[b].push_back({a,v});
    }
    vector<ll>dis(n+1,100000000000000000);
    dijkstra(dis);
    for(int i=1;i<=n;i++)cout<<dis[i]<<" ";
    cout<<endl;
}