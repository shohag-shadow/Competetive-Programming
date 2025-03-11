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
ll k;
ll par[500000+1];
ll find_parent(ll n)
{
    if(par[n]==n)return n;
    else return par[n]=find_parent(par[n]);
}
bool union_set(ll a,ll b)
{
    a=find_parent(a);
    b=find_parent(b);
    if(a==b)return false;
    par[a]=b;
    return true;
}
vector<pair<ll,pair<ll,ll>>>graph;
vector<pair<ll,ll>>mst;

ll minimum_spanning_tree()
{
    ll ans=0;
    sort(all(graph));
    reverse(all(graph));
    ll i=1;
    for(auto u:graph)
    {
        if(union_set(u.second.first,u.second.second))
        {
            ans+=u.first;
        }
        else
        {
            mst.push_back({u.first,i});
            //cout<<u.second.first<<" "<<u.second.second<<endl;
        } 
        i++;
    }
    vector<ll>out;
    sort(all(mst));
    for(auto u:mst)
    {
        if(u.first>k)break;
        else 
        {
            k-=u.first;
            out.push_back(u.second);
        }
    }
    cout<<out.size()<<endl;
    sort(all(out));
    for(auto u:out)cout<<u<<" ";
    cout<<endl;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        graph.push_back({c,{a,b}});
    }
    for(int i=1;i<=n;i++)par[i]=i;
    ll ans=minimum_spanning_tree();
    
}