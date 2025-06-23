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
const ll N=5e5+300;
vector<ll> graph[N];
vector<ll> graph1[N];
vector<ll> vis(N, 0);
vector<ll> top;
void topological_sort(ll node)
{
    vis[node] = 1;
    for (auto child : graph[node])
    {
        if (!vis[child])
        {
            topological_sort(child);
        }
    }
    top.push_back(node);
}
vector<ll> visited(N, 0);
vector<vector<ll>> component;
void dfs(ll node, vector<ll> &v)
{
    visited[node] = 1;
    v.push_back(node);
    for (auto child : graph1[node])
    {
        if (!visited[child])
        {
            dfs(child, v);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph1[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            topological_sort(i);
        }
    }
    reverse(all(top));
    ll ans = 0;
    for (auto node : top)
    {
        if (!visited[node])
        {
            vector<ll> v;
            dfs(node, v);
            component.push_back(v);
            ans++;
        }
    }
    cout << ans << endl;
    for (auto u : component)
    {
        cout << u.size() << " ";
        reverse(all(u));
        for (auto v : u)
            cout << v << " ";
        cout << endl;
    }
}