#include <iostream>
#include <vector>
using namespace std;

int number = 7;		//노드의 개수 
int c[8];
vector<int> a[8];	//총 7개의 노드가 인접한 노드를 갖도록 저장. 

/* 깊이 우선 탐색 */
void dfs(int x)
{
	if(c[x]) return;	// 이 노드를 이미 방문했다면 함수를 종료
	c[x] = true;	// 방문 표시
	printf("%d ", x);	// 방문 순서대로 값 출력. 
	
	// 해당 노드의 인접노드를 하나씩 방문하며 dfs를 실행. 
	for(int i=0; i<a[x].size(); i++){
		int y = a[x][i];
		dfs(y);
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
	
	dfs(1);
	
	return 0; 
 } 
