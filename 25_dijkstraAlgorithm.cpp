#include <iostream>
using namespace std;

#define INF 1000000000 		// 무한대의 값을 정의 
int number = 6;	// 노드의 개수 

// 전체 그래프를 초기화한다.
// 특정한 행에서 열로 가는 비용. 
int a[6][6] = {
	{0, 2, 5, 1, INF, INF},
	{2, 0, 3, 2, INF, INF},
	{5, 3, 0, 3, 1, 5},
	{1, 2, 3, 0, 1, INF},
	{INF, INF, 1, 1, 0, 2},
	{INF, INF, 5, INF, 2, 0}
};

bool visit[6];		// 방문한 노드 
int d[6];			// 최단 거리를 저장 

// 현재 노드 기준, 가장 최소 거리를 가지는 노드를 반환한다.
int getSmallIndex(){
	int min=INF;
	int idx = 0;
	for(int i=0; i<number; i++){
		if( d[i]<min && !visit[i]){
			min = d[i];
			idx = i;
		}
	}
	return idx;
} 

// 다익스트라를 수행하는 함수
void dijkstra(int start){
	for(int i=0; i<number; i++){
		d[i] = a[start][i];
	}
	visit[start] = true;
	for(int i=0; i<number-2; i++){
		int current = getSmallIndex();	// 시작 노드에서 가장 비용이 적게 드는 노드 선택 
		visit[current] = true;
		for(int j=0; j<number; j++){
			// 시작 노드에서 현재 위치를 거쳐서 j까지 가는 것이 시작-j까지보다 적다면 
			if( d[current]+a[current][j] < d[j] ){
				d[j] = d[current]+a[current][j];		// 업데이트 
			}
		}
	}
} 
int main(){
	dijkstra(0);
	for(int i=0; i<number; i++){
		cout<<d[i]<<' ';
	}
	return 0;
}
