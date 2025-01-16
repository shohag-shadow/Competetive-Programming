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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,k,d;
    cin>>n>>k>>d;
    queue<ll>q;
    vector<ll>dis(n+1,1000000000000);
    ll parent[n+1];
    for(int i=0;i<k;i++)
    {
        ll t;
        cin>>t;
        q.push(t);
        dis[t]=0;
        parent[t]=t;
    }
    vector<ll>graph[n+1];
    vector<pair<ll,ll>>edges;
    for(int i=1;i<n;i++)
    {
        ll a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        edges.push_back({a,b});
    }
    while(q.size())
    {
        ll par=q.front();
        q.pop();
        for(auto child:graph[par])
        {
            if(dis[child]>dis[par]+1)
            {
                dis[child]=dis[par]+1;
                q.push(child);
                parent[child]=par;
            }
        }
    }
    vector<ll>ans;
    for(int i=0;i<edges.size();i++)
    {
        ll a=edges[i].first;
        ll b=edges[i].second;
        if(a==parent[b]||b==parent[a]);
        else ans.push_back(i+1);
    }
    cout<<ans.size()<<endl;
    for(auto u:ans)cout<<u<<" ";
    cout<<endl;
}