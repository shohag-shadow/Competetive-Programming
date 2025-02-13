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
bool dfs(ll node,vector<ll>graph[],vector<ll>&vis,stack<ll>&st,vector<ll>&flag)
{
    if(vis[node])return flag[node]==0;
    vis[node]=1;
    flag[node]=1;
    bool ans=true;
    for(auto child:graph[node])
    {
        ans &=dfs(child,graph,vis,st,flag);
    }
    st.push(node);
    flag[node]=0;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<ll>graph[n+1];
    for(int i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    for(int i=1;i<=n;i++)sort(all(graph[i]),greater<ll>());
    vector<ll>vis(n+1,0);
    vector<ll>flag(n+1,0);
    stack<ll>st;
    bool ans=true;
    for(int i=n;i>=1;i--)
    {
        if(vis[i]==0)
        {
            ans &=dfs(i,graph,vis,st,flag);
        }
    }
    if(ans==false)
    {
        cout<<"No"<<endl;
        return 0;
    }
    vector<ll>out;
    while (st.size())
    {
        out.push_back(st.top());
        st.pop();
    }
    for(int i=1;i<=n;i++)reverse(all(graph[i]));
    for(auto &u:vis)u=0;
    for(auto &u:flag)u=0;
    
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            dfs(i,graph,vis,st,flag);
        }
    }
    vector<ll>out1;
    while (st.size())
    {
        out1.push_back(st.top());
        st.pop();
    }
    bool final_out=true;
    if(out.size()!=out1.size())
    {
        cout<<"No"<<endl;
        return 0;
    }
    for(int i=0;i<out.size();i++)
    {
        if(out[i]!=out1[i])
        {
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    ll output[n+1];
    for(int i=0;i<out.size();i++)output[out[i]]=i+1;
    for(int i=1;i<=n;i++)cout<<output[i]<<" ";
    cout<<endl;
    return 0;
}