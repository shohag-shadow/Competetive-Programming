#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll N=1e5+100;     //maximum size of graph
ll n;                   //number of nodes
vector<ll>graph[N+1];   //graph


void bfs(ll source)
{
    queue<ll>q;
    ll vis[n+1]={0};
    vis[source]=1;
    q.push(source);
    while(q.size()>0)
    {
        ll parent=q.front();
        q.pop();                //removed the front element from queue
        cout<<parent<<" ";
        for(auto child:graph[parent])   //get the child of this parent
        {
            if(vis[child]==0)           //if the child is not visited already
            {
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
}