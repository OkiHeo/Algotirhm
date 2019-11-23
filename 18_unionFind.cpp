#include <cstdio>

/* 현재 노드의 부모노드를 찾는 함수 */
int getParent(int parent[], int x){
	if( parent[x] == x ) return x;	// 현재 노드 본인임.
	// x의 부모의 부모를 찾도록 재귀적으로 함수 구성. 
	return parent[x] = getParent(parent, parent[x]);
}

/* 두 부모 노드를 합치는 함수 */
int unionParent(int parent[], int a, int b){
	// 각각의 부모 노드를 찾는다
	a = getParent(parent, a);
	b = getParent(parent, b);
	// 더 작은값쪽으로 부모를 합침. 
	if( a<b ){
		parent[b] = a;
	}
	else{
		parent[a] = b;
	}
} 

/* 같은 부모를 갖는지 확인 */
int findParent(int parent[], int a, int b){
	a = getParent(parent, a);
	b = getParent(parent, b);
	if( a == b ) return 1;	// 부모가 같음
	return 0; 
} 
int main(){
	int parent[11];
	for(int i=1; i<11; i++){
		parent[i] = i;
	} 
	unionParent(parent, 1, 2);
	unionParent(parent, 2, 3);
	unionParent(parent, 3, 4);
	unionParent(parent, 6, 5);
	unionParent(parent, 6, 7);
	unionParent(parent, 7, 8);
	
	printf("1과 5는 연결되어있나요? %d\n", findParent(parent, 1, 5));
	unionParent(parent, 1, 5);
	printf("1과 5는 연결되어있나요? %d\n", findParent(parent, 1, 5));
	
	return 0;
}
