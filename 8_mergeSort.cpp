#include <iostream>

int sorted[8];
int number = 8;

void merge(int data[], int m, int middle, int n){
	int i = m;
	int k = m;
	int j = middle+1;
	// 작은 순서대로 배열에 삽입한다.
	while( i<=middle && j <=n){
		if( data[i]<=data[j]){
			sorted[k] = data[i];
			i++;
		}
		else{
			sorted[k] = data[j];
			j++;
		}
		k++;
	}
	// 한 쪽이 끝났다면 남은 데이터 삽입
	if( i>middle ){
		for(int t = j; t<=n; t++){
			sorted[k] = data[t];
			k++;
		}	
	}
	else{
		for(int t = i; t<=middle; t++){
			sorted[k] = data[t];
			k++;
		}
	}
	// 정렬이 끝난 배열 sorted를 원래 배열에 대입
	for( int i=m; i<=n; i++){	/* 정렬된 배열의 인덱스 범위는 m ~ n */
		data[i] = sorted[i];
	} 
}

void mergeSort(int data[], int m, int n){
	// 원소의 크기가 1보다 큰 경우에만
	if(m<n){
		int middle = (m+n)/2;
		mergeSort(data, m, middle);
		mergeSort(data, middle+1, n);
		merge(data, m, middle, n);
	} 
}

int main()
{
	int data[8] = { 3, 5, 2, 7, 4, 9, 6, 8};
	mergeSort(data, 0, 7);
	for(int i=0; i<8; i++){
		printf("%d ", data[i]);
	}
	return 0;
}
