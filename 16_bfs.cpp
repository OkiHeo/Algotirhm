#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int number = 7;	// 7개의 노드들을 너비 탐색 할것임. 
int c[7];
vector<int> a[8];	// 각 노드의 인덱스가 1부터 시작할 수 있도록 하기 위해.
 
void bfs(int start){
	queue<int> q;
	q.push(start);
	c[start] = true;	// 이 노드에는 방문했음을 표시. 
	while(!q.empty()){
		// 큐의 맨 앞에 있는 원소 꺼내서 출력하고 삭제. 
		int x = q.front();
		q.pop(); 
		printf("%d ", x);
		
		for(int i=0; i<a[x].size(); i++){
			int y = a[x][i];
			if(!c[y]){
				// 큐의 맨 앞에 있는 원소의 자식들 중
				// 방문하지 않은 노드들 큐에 넣고 방문 표시. 
				q.push(y);
				c[y] = true; 
			}
		}
	}
} 
int main()
{
	// 1과 2를 연결 
	a[1].push_back(2);
	a[2].push_back(1);
	
	// 1과 3을 연결 
	a[1].push_back(3);
	a[3].push_back(1);
	
	// 2와 3을 연결 
	a[2].push_back(3);
	a[3].push_back(2);
	
	// 2와 4를 연결 
	a[2].push_back(4);
	a[4].push_back(2);
	
	// 2와 5를 연결 
	a[2].push_back(5);
	a[5].push_back(2);
	
	// 4와 5를 연결 
	a[4].push_back(5);
	a[5].push_back(4);
	
	// 3과 6을 연결 
	a[3].push_back(6);
	a[6].push_back(3);
	 
	// 3과 7을 연결 
	a[3].push_back(7);
	a[7].push_back(3);
	
	// 6과 7을 연결 
	a[6].push_back(7);
	a[7].push_back(6);
	
	bfs(1);
	
	return 0; 
}
