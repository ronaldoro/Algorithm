#include "algorithmHeader.h"
#pragma once

#include <tuple> 

const int MAX = (int)2e9;

vector<int> adj[1010];
int dis[1010][1 << 11];


int nodes[1001][1001];

class Dijkstra {
public:
	int dist[1001];

	bool isTrap(int nodeIndex, const vector<int>& traps) {
		for (int i = 0; i < traps.size(); ++i) {
			if (nodeIndex == traps[i])
				return true;
		}
		return false;
	}

	int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {

		int teset = 6 ^ 2;

		int answer = MAX; map<int, int> tnum;
		map<pair<int, int>, int> edge; map<pair<int, int>, int> revedge;
		
		for (int i = 1; i <= n; i++)
			tnum[i] = 0;
		
		for (int i = 0; i < traps.size(); i++) {
			tnum[traps[i]] = i + 1; 
		} 
		
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j < (1 << 11); j++) 
				dis[i][j] = MAX; 
		}
		
		dis[start][0] = 0;
		
		for (auto e : roads) {
			if (edge.find({ e[0], e[1] }) == edge.end()) edge[{e[0], e[1]}] = e[2];
			else edge[{e[0], e[1]}] = min(edge[{e[0], e[1]}], e[2]);
			if (revedge.find({ e[1], e[0] }) == revedge.end()) revedge[{e[1], e[0]}] = e[2];
			else revedge[{e[1], e[0]}] = min(revedge[{e[1], e[0]}], e[2]); 

			adj[e[0]].push_back(e[1]);
			adj[e[1]].push_back(e[0]);
		} 
		
		priority_queue<tuple<int, int, int>> pq;
		pq.push(make_tuple(0, 0, start));
		
		while (!pq.empty()) {
			int cost, bit, u;
			tie(cost, bit, u) = pq.top();
			pq.pop();
			cost = -cost;
			
			for (int v : adj[u]) {
				bool f1 = (bit & (1 << tnum[u]));
				bool f2 = (bit & (1 << tnum[v]));
				
				if ((f1 && f2) || (!f1 && !f2)) {
					if (edge.find({ u, v }) != edge.end() && dis[v][bit] > cost + edge[{u, v}]) {
						dis[v][bit] = cost + edge[{u, v}];
						pq.push(make_tuple(-dis[v][bit], tnum[v] > 0 ? bit ^ (1 << tnum[v]) : bit, v));
					}
				}
				else if ((f1 && !f2) || (!f1 && f2)) {
					if (revedge.find({ u, v }) != revedge.end() && dis[v][bit] > cost + revedge[{u, v}]) {
						dis[v][bit] = cost + revedge[{u, v}];
						pq.push(make_tuple(-dis[v][bit], tnum[v] > 0 ? bit ^ (1 << tnum[v]) : bit, v));
					}
				}
			}
		
		}
		
		for (int i = 0; i < (1 << 11); i++) 
			answer = min(answer, dis[end][i]);
	
		return answer;
	}

	//int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {

	//	for (int i = 1; i <= n; ++i) {
	//		dist[i] = INT_MAX;
	//	}

	//	for (int i = 0; i < roads.size(); ++i) {
	//		nodes[roads[i][0]][roads[i][1]] = roads[i][2];
	//	}

	//	priority_queue<pair<int, int>, int> pq;
	//	//pq.push(make_pair(start, 0));

	//	//while (pq.empty() == false) {
	//	//	int curNodeIndex = pq.top().first;
	//	//	int distance = -pq.top().second;
	//	//	pq.pop();

	//	//	if (dist[curNodeIndex] < distance)
	//	//		continue;

	//	//	if (isTrap(curNodeIndex, traps) == true) {

	//	//		for (int i = 1; i <= n; ++i) {
	//	//			int temp = nodes[i][curNodeIndex];
	//	//			nodes[i][curNodeIndex] = nodes[curNodeIndex][i];
	//	//			nodes[curNodeIndex][i] = temp;
	//	//		}

	//	//	}

	//	//	for (int i = 1; i <= n; ++i) {
	//	//		if (nodes[curNodeIndex][i] != 0) {
	//	//			int nextDist = distance + nodes[curNodeIndex][i];
	//	//			if (dist[i] > nextDist || isTrap(nextDist, traps) == true) {
	//	//				dist[i] = nextDist;
	//	//				pq.push(make_pair(i, -nextDist));
	//	//			}
	//	//	
	//	//			if (i == end)
	//	//				return dist[i];
	//	//		}
	//	//	}
	//	//}

	//	return dist[end];
	//}
};
