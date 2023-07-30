#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int number = 9;
int heap[9] = { 7, 6, 5, 8, 3, 5, 9, 1, 6 };

int main(void) {
	// ��ü Ʈ�� ������ �ִ� �� ������ �ٲ� 
	for (int i = 1; i < number; i++) {
		int child = i;
		do {
			int parent = (child - 1) / 2;
			if (heap[parent] < heap[child]) {
				int temp = heap[parent];
				heap[parent] = heap[child];
				heap[child] = temp;
			}
			child = parent;
		} while (child != 0);
	}
	// ũ�⸦ ���̸� �ݺ������� �� ���� 
	for (int i = number - 1; i >= 0; i--) {
		// ���� ū ���� ���������� ���� 
		int temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;
		int parent = 0;
		int child = 1;
		do {
			child = 2 * parent + 1;
			// �ڽ� �� �� ū �� ã�� 
			if (heap[child] < heap[child + 1] && child < i - 1) {
				child++;
			}
			// �θ𺸴� �ڽ��� �� ũ�ٸ� swap 
			if (heap[parent] < heap[child] && child < i) {
				int temp = heap[parent];
				heap[parent] = heap[child];
				heap[child] = temp;
			}
			parent = child;
		} while (child < i);
	}
	for (int i = 0; i < number; i++) {
		printf("%d ", heap[i]);
	}
}