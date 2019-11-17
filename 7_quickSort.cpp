#include <iostream>

void quickSort(int *data, const int start, const int end){
	int small, big, temp;
	
	if(start>=end){
		// 원소가 하나인 경우에는 그냥 리턴한다. 
		return;
	}
	
	int key = start;
	big = start + 1;
	small = end;
	while(big<=small){
	// small 이 big보다 오른쪽에 위치한동안 반복 
		while(data[big]<=data[key]){
			// key의 바로 다음부터 key값보다 큰 값을 찾아나감
			big++;
		}
		while(data[small]>=data[key] && small>start){
			// key보다 작은 값을 오른쪽에서부터 찾아나감
			small--;
		}
		
		if(small<big){
			// 작은값이 큰 값보다 왼쪽에 있으면 엇갈린것.
			temp = data[key];
			data[key] = data[small];
			data[small] = temp;
			// 작은값과 key값을 교환해준다. 
		}
		else{
			temp = data[small];
			data[small] = data[big];
			data[big] = temp;
			// 아직 엇갈리지 않았으니까 작은값과 큰 값 자리 바꿈 
		}
	}
	quickSort(data, start, small-1);
	quickSort(data, small+1, end); 
}

int main()
{
	int data[] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
	int size = sizeof(data)/sizeof(int);
	
	quickSort(data, 0, size);
	
	for(int i=0; i<size; i++){
		std::cout<<data[i]<<' ';
	}
	return 0;
}
