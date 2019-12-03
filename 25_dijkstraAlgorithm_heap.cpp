#include <iostream>
#include <vector>
#include <queue>		// c++에서 제공하는 우선순위 큐가 힙처럼 작동하기때문에 
using namespace std;

#define INF 1000000000 		// 무한대의 값을 정의 
int number = 6;	// 노드의 개수 

vector< pair<int, int> > a[7];		// 간선 정보 저장  
int d[7];			// 최단 거리를 저장 

// 다익스트라를 수행하는 함수
void dijkstra(int start){
	d[start] = 0;
	priority_queue<pair<int,int> > pq;	// 힙 구조를 생성
	pq.push(make_pair(start, 0)); 
	// 가까운 순서대로 처리하므로 큐를 사용한다.
	
	while(!pq.empty()){
		int current = pq.top().first;	//  가장 적은 비용을 가지는 노드
		// 비용이 작은 것이 먼저 오도록 음수화(-)해준다. -> 제일 큰 것이 제일 작아진다.
		int distance = -pq.top().second;
		pq.pop();
		// 최단거리가 아닌 경우 패스.
		if( d[current]<distance ) continue;
		for(int i=0; i<a[current].size(); i++){
			// 선택된 노드의 인접노드
			int next = a[current][i].first;
			// 선택된 노드를 거쳐서 인접 노드로 가는 비용
			int nextDistance = distance + a[current][i].second;
			// 기존 최소 비용보다 더 적다면 갱신
			if( nextDistance < d[next] ){
				d[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));	// 음수화해서 저장했으므로 다시 양수화. 
			} 
		} 
	} 
} 
int main(){
	// 기본적으로 연결되지 않은 경우 비용은 무한.
	for(int i=1; i<=number; i++){
		d[i] = INF;
	} 
	a[1].push_back(make_pair(2, 2));
	a[1].push_back(make_pair(3, 5));
	a[1].push_back(make_pair(4, 1));
	
	a[2].push_back(make_pair(1, 2));
	a[2].push_back(make_pair(3, 3));
	a[2].push_back(make_pair(4, 2));
	
	a[3].push_back(make_pair(1, 5));
	a[3].push_back(make_pair(2, 3));
	a[3].push_back(make_pair(4, 3));
	a[3].push_back(make_pair(5, 1));
	a[3].push_back(make_pair(6, 5));
	
	a[4].push_back(make_pair(1, 1));
	a[4].push_back(make_pair(2, 2));
	a[4].push_back(make_pair(3, 3));
	a[4].push_back(make_pair(5, 1));
	
	a[5].push_back(make_pair(3, 1));
	a[5].push_back(make_pair(4, 1));
	a[5].push_back(make_pair(6, 2));
	
	a[6].push_back(make_pair(3, 5));
	a[6].push_back(make_pair(5, 2));
	
	dijkstra(1);
	
	// 결과를 출력
	for(int i=1; i<=number; i++){
		cout<<d[i]<<' ';
	} 
	return 0;
}
