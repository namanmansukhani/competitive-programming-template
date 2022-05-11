# inspired by cses handbook and cp-algorithms.com

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
			int a,b,c;
			tie(a,b,c) = e;
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
