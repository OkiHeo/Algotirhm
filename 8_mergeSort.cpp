#include <iostream>

int sorted[8];
int number = 8;

void merge(int data[], int m, int middle, int n){
	int i = m;
	int k = m;
	int j = middle+1;
	// ���� ������� �迭�� �����Ѵ�.
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
	// �� ���� �����ٸ� ���� ������ ����
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
	// ������ ���� �迭 sorted�� ���� �迭�� ����
	for( int i=m; i<=n; i++){	/* ���ĵ� �迭�� �ε��� ������ m ~ n */
		data[i] = sorted[i];
	} 
}

void mergeSort(int data[], int m, int n){
	// ������ ũ�Ⱑ 1���� ū ��쿡��
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
