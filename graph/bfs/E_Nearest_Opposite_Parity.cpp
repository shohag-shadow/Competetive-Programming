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
void bfs(ll root,vector<ll>graph[],vector<ll>&nep,vector<ll>&nop)
{
    queue<ll>q;
    q.push(root);
    while(q.size())
    {
        ll par=q.front();
        q.pop();
        for(auto child:graph[par])
        {
            if(nop[child]>nop[par]+1||nep[child]>nep[par]+1)
            {
                nop[child]=min(nop[child],nop[par]+1);
                nep[child]=min(nep[child],nep[par]+1);
                q.push(child);
            }
        }
    }
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n; 
    cin>>n;
    ll arr[n];
    vector<ll>nep(n,M);
    vector<ll>nop(n,M);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]%2)nop[i]=0;
        else nep[i]=0;
    }
    vector<ll>graph[n+1];
    for(int i=0;i<n;i++)
    {
        if(i+arr[i]<n)
        {
            graph[i+arr[i]].push_back(i);
        }
        if(i-arr[i]>=0)
        {
            graph[i-arr[i]].push_back(i);
        }
    }
    for(int i=0;i<n;i++)
    {
        bfs(i,graph,nep,nop);
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]%2)
        {
            if(nep[i]==M)cout<<-1<<" ";
            else cout<<nep[i]<<" ";
        }
        else
        {
            if(nop[i]==M)cout<<-1<<" ";
            else cout<<nop[i]<<" ";
        }
    }
}