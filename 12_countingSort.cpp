#include <iostream>

int count[5];
/* countingSort�� ������ ������ ũ�Ⱑ �����Ǿ������� ���� */
int array[30] = {1, 3, 2, 4, 3, 2, 5, 3, 1, 2,
				 3, 4, 4, 3, 5, 1, 2, 3, 5, 2,
				 3, 1, 4, 3, 5, 1, 2, 1, 1, 1};
int main()
{
	// count �迭�� 0���� �ʱ�ȭ�Ѵ�.
	for(int i=0; i<5; i++){
		count[i] = 0;
	}
	// ��� ���� ����
	for(int i=0; i<30; i++){
		count[array[i]-1]++;
	}
	// ��� ���� ��� ���
	for(int i=0; i<5; i++){
		for(int j=0; j<count[i]; j++){
			printf("%d ", i+1);
		}
	} 
	return 0;
}
