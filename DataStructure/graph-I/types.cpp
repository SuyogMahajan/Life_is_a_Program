#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// this is with adjecency list
class Graph{
    public:

    // number of vertices;
    int v;
    // number of edges
    int e;
    vector<vector<int>> adj;

    Graph(int n) {
        adj = vector<vector<int>>(n,vector<int>(n,0));
        v = n;
    }

    // using int for visited cna save space but it have will be limited bits
    // so we can use a vector or map

    void dfs(int s,int &vis) {
        if(vis == (1<<v)-1) return;

        vis = vis | (1<<s);
        
        cout << s <<"--> ";

        for(int i = 0 ;i<v;i++) {
            if(adj[s][i] == 1 && !(vis&(1<<i))) {
                dfs(i,vis);
            }
        }
    }

    void bfs(int s) {

        queue<int> q;
        q.push(s);
        int vis = (1<<s);

        while(!q.empty() ) {
        
            int t = q.front();
            q.pop();

            cout << t <<"-->";

            for(int i = 0; i <v;i++) {
                if(!(vis&(1<<i)) && adj[t][i]) {
                    vis |= (1<<i);
                    q.push(i);
                }
            }
        }

    }

};

Graph* makeAdjGraph() {
    int v,e;
    cin >> v >> e;
    Graph* g = new Graph(v);

    for(int i = 0;i < e;i++) {
        int a,b;
        cin >> a >> b;

        g->adj[a][b] = 1;
    }
    g->e = e;

    cout << endl;
    for(auto x:g->adj) {
        for(auto y:x) cout << y <<" ";
        cout << endl;
    }

    return g;
}


int main() {
    Graph* g = makeAdjGraph();
    // int vis = 0;
    // g->dfs(0,vis);
    // cout << endl;
    // vis = 0;
    // g->dfs(1,vis);
    // cout << endl;
    // vis = 0;
    // g->dfs(2,vis);
    // cout << endl;
    // vis = 0;
    // g->dfs(3,vis);
    // cout << endl;
    g->bfs(0);
    return 0;
}