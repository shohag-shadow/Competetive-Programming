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
    ll n,m;
    cin>>n>>m;
    vector<pair<pair<ll,ll>,ll>>edges;
    vector<ll>graph[n+1];
    for(int i=0;i<m;i++)
    {
        ll a,b,v;
        cin>>a>>b>>v;
        edges.push_back({{a,b},v});
        graph[a].push_back(b);
    }
    vector<ll>dis(n+1,0);
    vector<ll>par(n+1,-1);
    ll p;
    for(int i=1;i<=n;i++)
    {
        p=-1;
        for(auto e:edges)
        {
            if(dis[e.first.second]>dis[e.first.first]+e.second)
            {
                dis[e.first.second]=dis[e.first.first]+e.second;
                par[e.first.second]=e.first.first;
                p=e.first.second;
            }
        }
    }
    
    if(p==-1)cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        vector<ll>vis(n+1,0);
        for(int i=0;i<n;i++)p=par[p];
        vector<ll>out;
        out.push_back(p);
        ll q=p;
        p=par[p];
        while(p!=q)
        {
            out.push_back(p);
            p=par[p];
        }
        out.push_back(p);
        reverse(all(out));
        for(auto u:out)cout<<u<<" ";
        cout<<endl;

    }
}