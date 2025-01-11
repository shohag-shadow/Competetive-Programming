#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll N=1e5+100;     //maximum size of graph
ll n;                   //number of nodes
vector<ll>graph[N+1];   //graph
ll parent[N+1];
ll dis[N+1];

void bfs(ll source)
{
    queue<ll>q;
    ll vis[n+1]={0};
    
    parent[source]=source;
    dis[source]=1;
    vis[source]=1;
    q.push(source);
    while(q.size()>0)
    {
        ll par=q.front();
        q.pop();                //removed the front element from queue
        //cout<<par<<" ";
        for(ll child:graph[par])   //get the child of this parent
        {
            if(vis[child]==0)           //if the child is not visited already
            {   parent[child]=par;
                dis[child]=dis[par]+1;
                vis[child]=1;           //visit it and push it in queue
                q.push(child);
            }
        }
    }
    cout<<endl;
}
int main()
{
    cin>>n;
    ll m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bfs(1);
    if(dis[n]==0)cout<<"IMPOSSIBLE"<<endl;
    else
    {
        cout<<dis[n]<<endl;
        vector<ll>path;
        ll j=n;
        while(1)
        {
            if(j==1)
            {
                path.push_back(1);
                break;
            }
            else
            {
                path.push_back(j);
                j=parent[j];
            }
        }
        reverse(path.begin(),path.end());
        for(auto u:path)cout<<u<<" ";
        cout<<endl;
    } 
}