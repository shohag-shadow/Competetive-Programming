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

ll minimum_spanning_tree(vector<pair<ll,ll>>graph[],vector<pair<ll,ll>>&mst,vector<ll>&vis)
{
    set<pair<ll,pair<ll,ll>>>q;
    for(auto child:graph[1])
    {
        q.insert({child.second,{1,child.first}});
    }
    vis[1]=1;
    ll ans=0;
    while(q.size())
    {
        pair<ll,pair<ll,ll>>top=*q.begin();
        q.erase(q.begin());
        if(vis[top.second.second]==0)
        {
            vis[top.second.second]=1;
            ans+=top.first;
            mst.push_back(top.second);
            for(auto child:graph[top.second.second])
            {
                q.insert({child.second,{top.second.second,child.first}});
            }
        }
    }
    return ans;
}
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
        ll a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    vector<pair<ll,ll>>mst;
    vector<ll>vis(n+1,0);
    ll ans=minimum_spanning_tree(graph,mst,vis);
    ll c=0;
    for(int i=1;i<=n;i++)c+=vis[i]==1;
    if(c==n)cout<<ans<<endl;
    else cout<<"IMPOSSIBLE"<<endl;
    //for(auto u:mst)cout<<u.first<<" "<<u.second<<endl;
}