#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* ����Ŭ�� �߻��ϴ��� �����ϱ� ���� Union-Find �˰��� */ 
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

/* ���� Ŭ���� ���� */
class Edge{
	public:
		int node[2];		// ���� ����� �� �� �� ��� ���� 
		int distance;
		Edge(int a, int b, int distance){
			this->node[0]=a;
			this->node[1]=b;
			this->distance=distance;
		}
		bool operator<(Edge &edge){	// Ŭ���� �񱳸� ���� ������ �����ε�. 
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
	
	// ���� ��� ���� �������� ���� 
	sort(v.begin(), v.end()); 
	
	// �� ������ ���Ե� �׷����� ������� ����
	int parent[n];
	for(int i=0; i<n; i++){
		parent[i]=i;
	} 
	int sum=0;
	for(int i=0; i<v.size(); i++){
		// ��� ������ ���� ���ʴ��..
		// ����Ŭ�� �߻����� �ʴ� ��� �׷����� ����
		if( !findParent(parent, v[i].node[0]-1, v[i].node[1]-1)) {
			sum+=v[i].distance;
			unionParent(parent, v[i].node[0]-1, v[i].node[1]-1);		//-1�� �ϴ� ���� : parent�ε��� 0���� �����ϴϱ� 
		}
	}
	cout<<sum<<'\n'; 
	return 0;
}
