#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* 사이클이 발생하는지 검증하기 위한 Union-Find 알고리즘 */ 
int getParent(int parent[], int a){
	if( parent[a] == a ) return a;
	return parent[a] = getParent(parent, parent[a]);
}
int unionParent(int parent[], int a, int b){
	a = getParent(parent, a);
	b = getParent(parent, b);
	if( a < b ){
		parent[b] = a;
	}
	else{
		parent[a] = b;
	}
}
int findParent(int parent[], int a, int b){
	a = getParent(parent, a);
	b = getParent(parent, b);
	if( a==b ) return 1;
	return 0;
}

/* 간선 클래스 선언 */
class Edge{
	public:
		int node[2];		// 서로 연결된 두 개 의 노드 정보 
		int distance;
		Edge(int a, int b, int distance){
			this->node[0]=a;
			this->node[1]=b;
			this->distance=distance;
		}
		bool operator<(Edge &edge){	// 클래스 비교를 위해 연산자 오버로딩. 
			return this->distance<edge.distance;
		}
};

int main()
{
	int n=7;
	int m=11;
	
	vector<Edge> v;
	v.push_back(Edge(1, 2, 67));
	v.push_back(Edge(1, 4, 28));
	v.push_back(Edge(1, 5, 17));
	v.push_back(Edge(1, 7, 12));
	v.push_back(Edge(2, 4, 24));
	v.push_back(Edge(2, 5, 62));
	v.push_back(Edge(3, 5, 20));
	v.push_back(Edge(3, 6, 37));
	v.push_back(Edge(4, 7, 13));
	v.push_back(Edge(5, 6, 45));
	v.push_back(Edge(5, 7, 73));
	
	// 간선 비용 기준 오름차순 정렬 
	sort(v.begin(), v.end()); 
	
	// 각 정점이 포함된 그래프가 어디인지 저장
	int parent[n];
	for(int i=0; i<n; i++){
		parent[i]=i;
	} 
	int sum=0;
	for(int i=0; i<v.size(); i++){
		// 모든 간선에 대해 차례대로..
		// 사이클이 발생하지 않는 경우 그래프에 포함
		if( !findParent(parent, v[i].node[0]-1, v[i].node[1]-1)) {
			sum+=v[i].distance;
			unionParent(parent, v[i].node[0]-1, v[i].node[1]-1);		//-1을 하는 이유 : parent인덱스 0부터 시작하니까 
		}
	}
	cout<<sum<<'\n'; 
	return 0;
}
