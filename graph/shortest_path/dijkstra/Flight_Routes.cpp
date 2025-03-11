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
    ll n,m,k;
    cin>>n>>m>>k;
    vector<pair<ll,ll>>graph[n+1];
    for(int i=0;i<m;i++)
    {
        ll a,b,v;
        cin>>a>>b>>v;
        graph[a].push_back({b,v});
    }
    vector<vector<ll>>dis(n+1,vector<ll>(k,inf));
    multiset<pair<ll,ll>>pq;
    dis[1][0]=0;
    pq.insert({0,1});
    while(!pq.empty())
    {
        ll d=(*pq.begin()).first;
        ll par=(*pq.begin()).second;
        pq.erase(pq.begin());
        for(auto child:graph[par])
        {
            if(dis[child.first][k-1]>d+child.second)
            {
                if(dis[child.first][k-1]!=inf)pq.erase(pq.find({dis[child.first][k-1],child.first}));
                dis[child.first][k-1]=d+child.second;
                pq.insert({dis[child.first][k-1],child.first});
                sort(all(dis[child.first]));
            }
        }
    }
    for(int i=0;i<k;i++)cout<<dis[n][i]<<" ";
    cout<<endl;
}