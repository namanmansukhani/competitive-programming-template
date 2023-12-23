//inspired by cses handbook and cp-algorithms.com

void dfs(int v) {
	visited[v] = true;
	for (auto u: adj[v]) {
		if (!visited[u]) dfs(u);
	}
}

void bfs(int source){
	queue<int> q; q.push(source);
	dis[source] = 0;
	visited[source] = true;
	while(!q.empty()){
		int a = q.front(); q.pop();
		for(auto b: adj[a]){
			if(visited[b]) continue;
			visited[b] = true;
			dis[b] = dis[a] + 1;
			q.push(b);
		}
	}
}

void bellman(int source){
	dis[source] = 0;
	for(int i=0;i<n-1;i++){
		for(auto e: edges){
			int a,b,w;
			tie(a,b,w) = e;
			dis[b] = min(dis[a] + w, dis[b]);
		}
	}
}

void floyd(int source){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i == j) dis[i][j] = 0;
			if(adj[i][j]) dis[i][j] = adj[i][j];
			else dis[i][j] = inf;
		}
	}
	for(int k=1;k<=n;i++){
		for(int a=1;a<=n;a++){
			for(int b=1;b<=n;b++){
				dis[a][b] = min(dis[a][b], dis[a][k] + dis[k][b]);
			}
		}
	}
}

void dijk(int source){
	priority_queue<int> pq;
	pq.push(mp(0, source));
	dis[source] = 0;
	while(!pq.empty()){
		int a = pq.front().second; pq.pop();
		if(processed[a]) continue;
		processed[a] = true;
		for(auto u: adj[a]){
			int b = u.first, w = u.second;
			if(dis[b] > dis[a] + w){
				dis[b] = dis[a] + w;
				pq.push(mp(-dis[b], b));
			}
		}
	}
}

struct FlowNetwork {
    int n;
    vector<vector<pii>> adj;
    vector<int> capacity;
    vector<pii> parent;
    vector<int> dis;
    vector<int> used;

    int edge_num = 0;
    int s;
    int t;

    FlowNetwork(int lim, int source, int sink) {
        n = lim;
        adj = vector<vector<pii>>(n);
        s = source;
        t = sink;
        parent = vector<pii>(n);
        dis = vector<int>(n);
        used = vector<int>(n);
    }

    void add_edge(int i, int j) {
        adj[i].pb({j, edge_num});
        capacity.pb(1);
        edge_num++;
        adj[j].pb({i, edge_num});
        capacity.pb(0);
        edge_num++;
    }

    bool dfs(int v) {
        if (v == t) return true;

        int lim = adj[v].size();

        for (int i=used[v]; i < lim; i++) {
            used[v]++;
            int u = adj[v][i].first;
            int edge_u = adj[v][i].second;

            if (capacity[edge_u] <= 0) continue;
            if (dis[u] != dis[v] + 1) continue;
            if (!dfs(u)) continue;

            capacity[edge_u]--;
            int back_edge = edge_u;
            if (back_edge % 2 == 0) back_edge++;
            else back_edge--;
            capacity[back_edge]++;
            return true;

        }
        return false;
    }

    bool bfs () {
        queue<int> q;
        // doubles as visited array
        // vector<int> dis(n, -1);
        for (int i=0;i<n;i++) dis[i] = -1;
        dis[s] = 0;
        q.push(s);

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (auto [u, edge_u]: adj[v]) {
                if (dis[u] != -1 or capacity[edge_u] <= 0) continue;
                dis[u] = dis[v] + 1;
                q.push(u);
                parent[u] = {v, edge_u};
            }
        }
        if (dis[t] == -1) return false;
        return true;
    }

    int find_flow () {
        int flow = 0;
        while (true) {
            for (int i=0;i<n;i++) parent[i] = {-1, -1};
            for (int i=0;i<n;i++) used[i] = 0;
            if (!bfs()) break;
            while (dfs(s)) flow++;
        }
        return flow;
    }
};