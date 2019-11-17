#include <iostream>

int number = 9;
int heap[9] = {7, 6, 5, 8, 3, 5, 9, 1, 6};

void heapSort(int data[], int number){
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
			if( heap[c] < heap[c+1] && c<i-1){
				c++;
			}
			// root의 자식이 root 보다 크면 교환 
			if( heap[c] > heap[root] && c<i){
				int temp = heap[c];
				heap[c] = heap[root];
				heap[root] = temp;
			}
			root = c;
		}while(c<i);
	}
}
int main(){
	for(int i=0; i<number; i++){
		std::cout<<heap[i]<<' ';
	}
	std::cout<<std::endl;
	heapSort(heap, number);
	for(int i=0; i<number; i++){
		std::cout<<heap[i]<<' ';
	}
	return 0;
}
