vector<pii> findCycle(vector<vi>& adj, int n){
    vi vis(n + 1), par(n + 1, -1);
    vector<pii> cyc;

    for(int s = 1; s <= n; s++){
        if(vis[s]) continue;

        stack<pii> st;
        st.push({s, 0});
        vis[s] = 1;

        while(!st.empty()){
            int u = st.top().fi;
            int &i = st.top().se;

            if(i == sz(adj[u])){
                vis[u] = 2;
                st.pop();
                continue;
            }

            int v = adj[u][i++];

            if(!vis[v]){
                par[v] = u;
                vis[v] = 1;
                st.push({v, 0});
            }
            else if(vis[v] == 1){
                cyc.pb({u, v});

                while(u != v){
                    cyc.pb({par[u], u});
                    u = par[u];
                }

                return cyc;
            }
        }
    }

    return {};
}
