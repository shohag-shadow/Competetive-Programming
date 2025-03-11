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
const ll inf=100000000000000000;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>>graph[n+1];
    for(int i=0;i<m;i++)
    {
        ll a,b,v;
        cin>>a>>b>>v;
        graph[a].push_back({b,v});
    }
    vector<ll>dis(n+1,inf);
    vector<ll>ways(n+1,0);
    vector<ll>min_f(n+1,inf);
    vector<ll>max_f(n+1,0);
    dis[1]=0;
    ways[1]=1;
    min_f[1]=0;
    max_f[1]=0;
    multiset<pair<ll,ll>>pq;
    pq.insert({0,1});
    while(!pq.empty())
    {
        pair<ll,ll>par=*pq.begin();
        pq.erase(pq.begin());
        for(auto child:graph[par.second])
        {
            if(dis[child.first]==dis[par.second]+child.second)
            {
                ways[child.first]=(ways[child.first]+ways[par.second])%M;
                min_f[child.first]=min(min_f[child.first],min_f[par.second]+1);
                max_f[child.first]=max(max_f[child.first],max_f[par.second]+1);
            }
            if(dis[child.first]>dis[par.second]+child.second)
            {
                pq.erase({dis[child.first],child.first});
                dis[child.first]=dis[par.second]+child.second;
                ways[child.first]=ways[par.second];
                min_f[child.first]=min_f[par.second]+1;
                max_f[child.first]=max_f[par.second]+1;
                pq.insert({dis[child.first],child.first});
            }

        }
    }
    cout<<dis[n]<<" "<<ways[n]<<" "<<min_f[n]<<" "<<max_f[n]<<endl;
}