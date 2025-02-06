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
ll bfs(ll root,vector<ll>graph[],vector<ll>&type)
{
    queue<pair<ll,ll>>q;
    type[root]=0;
    q.push({root,0});
    ll zero=1,one=0;
    while(q.size())
    {
        pair<ll,ll>par=q.front();
        q.pop();
        for(auto u:graph[par.first])
        {
            if(type[u]==-1)
            {
                if(par.second==1)
                {
                    zero++;
                    type[u]=0;
                    q.push({u,0});
                }
                else
                {
                    one++;
                    type[u]=1;
                    q.push({u,1});
                }
            }
        }
    }
    if(zero<one)return 0;
    else return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tst;
    cin>>tst;
    for(ll test=1;test<=tst;test++)
    {
        //cout<<"Case "<<test<<": ";
        ll n,m;
        cin>>n>>m;
        vector<ll>graph[n+1];
        for(int i=0;i<m;i++)
        {
            ll a,b;
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        vector<ll>type(n+1,-1);
        ll x=bfs(1,graph,type);
        vector<ll>ans;
        for(int i=1;i<=n;i++)
        {
            if(type[i]==x)ans.push_back(i);
           
        }
        cout<<ans.size()<<endl;
        for(auto u:ans)cout<<u<<" ";
        cout<<endl;
    }
}