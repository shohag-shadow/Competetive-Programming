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
    ll n;
    cin>>n;
    string arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<ll>graph[500];
    bool possible=true;
    for(int i=1;i<n;i++)
    {
        ll len=min(arr[i].size(),arr[i-1].size());
        ll pos=-1;
        for(int j=0;j<len;j++)
        {
            if(arr[i][j]!=arr[i-1][j])
            {
                pos=j;
                break;
            }
        }
        if(pos==-1)
        {
            if(arr[i].size()<arr[i-1].size())
            {
                possible=false;
            }
        }
        else
        {
            graph[arr[i-1][pos]].push_back(arr[i][pos]);
        }
    }
    if(possible==false)
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
    vector<ll>vis(500,0);
    vector<ll>flag(500,0);
    stack<ll>st;
    bool ans=true;
    for(int i='a';i<='z';i++)
    {
        if(vis[i]==0)
        {
            ans &=dfs(i,graph,vis,st,flag);
        }
    }
    if(ans==false)
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
    while (st.size())
    {
        cout<<(char)(st.top());
        st.pop();
    }
    cout<<endl;
    return 0;
}