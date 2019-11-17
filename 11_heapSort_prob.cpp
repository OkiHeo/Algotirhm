#include <iostream>

void heapSort(int heap[], int number){
	// 최대 힙을 구성한다.
	for( int i=1; i<number; i++){
		int c = i;
		do{
			int root = (c-1)/2;
			if( heap[root] < heap[c] ){
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			c = root;
		}while( c!=0 );
	}
	for(int i=0; i<number; i++){
		std::cout<<heap[i]<<' ';
	}
	std::cout<<'\n';
	
	// 힙 정렬을 수행한다. 
	for( int i=number-1; i>=0; i--){
		int temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;
		int root = 0;
		int c = 1;
		do{
			c = 2*root+1;
			//root의자식 중 더 큰 값 찾기 
			if( c<i-1&&heap[c] < heap[c+1] ){
				c++;
			}
			// root의 자식이 root 보다 크면 교환 
			if( c<i&& heap[c] > heap[root]){
				int temp = heap[c];
				heap[c] = heap[root];
				heap[root] = temp;
			}
			root = c;
		}while(c<i/2);
		for( int i=0; i<number; i++){
			std::cout<<heap[i]<<' ';
		}
		std::cout<<'\n';
	}
}

int main(){
	int number;
	std::cin>>number;
	int *heap = new int[number];
	for(int i=0; i<number; i++){
		std::cin>>heap[i];
	}
	heapSort(heap, number);
	return 0;
} 
