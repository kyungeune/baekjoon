#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	int cnt;
	int num;
}element;
typedef struct {
	element* data;
	int  front, rear;
} QueueType;
int parent(int i) {
	return i / 2;
}

int left(int i) {
	return 2 * i + 1;
}

int right(int i) {
	return 2 * i + 2;
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Max_Heapify(element* A, int i, int size) {
	int l = left(i);
	int r = right(i);
	int largest;

	if (l < size && A[l].num < A[i].num) {
		largest = l;
	}
	else {
		largest = i;
	}

	if (r < size && A[r].num < A[largest].num) {
		largest = r;
	}

	if (largest != i) {
		swap(&A[i], &A[largest]);
		Max_Heapify(A, largest, size);
	}
}

void Build_Max_Heap(int* A, int size) {
	for (int i = size / 2; i >= 0; i--) {
		Max_Heapify(A, i, size);
	}
}

void HeapSort(int* A, int size) {
	Build_Max_Heap(A, size);

	for (int i = size - 1; i > 0; i--) {
		swap(&A[0], &A[i]);
		Max_Heapify(A, 0, i);
	}
}
//int compare(const void* a, const void* b) // queue.data 전달받은 상태
//{
//	if (((element*)a)->num > ((element*)b)->num)
//		return 1;
//	else if (((element*)a)->num < ((element*)b)->num)
//		return -1;
//	else
//		return 0;
//}

int search(QueueType* q, int st, int ed, int find) // 이진탐색
{
	int mid = -1;

	while (st <= ed) {
		mid = (st + ed) / 2;

		if (q->data[mid].num >= find) {
			if (q->data[mid].num == find)
				return mid;
			ed = mid - 1;
		}
		else {
			st = mid + 1;
		}
	}
	return -1;
}
void push(QueueType* q, int size, int k)
{
	element item;
	item.cnt = 1;
	item.num = k;

	if (is_full(q, size))
		return;
	else if (is_empty(q)) {
		q->front = q->rear = 0;
		q->rear = (q->rear + 1) % size;
		q->data[q->rear] = item;
		Build_Max_Heap(q->data, size);
	}
	else {
		int nowSize = getSize(q, size);
		int sR = search(q, q->front + 1, q->rear, k);
		if (sR == -1) {
			q->rear = (q->rear + 1) % size;
			q->data[q->rear] = item;
			Build_Max_Heap(q->data, nowSize + 1);
		}
		else {
			q->data[sR].cnt++;
			Build_Max_Heap(q->data, nowSize);
		}
	}
}
int getCnt(QueueType* q, int size, int k)
{
	int sR = search(q, q->front + 1, q->rear, k);
	if (sR != -1) {
		return q->data[sR].cnt;
	}
	return 0;
}
void destroy_queue(QueueType* q)
{
	free(q->data);
}
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}
int is_full(QueueType* q, int size)
{
	return ((q->rear + 1) % size == q->front);
}
int getSize(QueueType* q, int size)
{
	return (size + q->rear - q->front) % size;
}

int main(void)
{
	QueueType queue;
	int n = 0, m = 0, nowSize = 0;
	scanf("%d", &n);
	int size = n + 1; // 큐의 first는 비워져있기 때문
	queue.data = (element*)malloc(sizeof(element) * size); // size만큼 준 이유는 size보다는 적은 양이 입력될 것이기 때문
	queue.front = queue.rear = 0; // 큐 초기화

	for (int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);
		push(&queue, size, k); // 삽입
		// nowSize = getSize(&queue, size); // 삽입한 직후 queue의 크기
		// 최악의 경우 n ^ 2 정렬, nlogn이 보장된 정렬방법 사용해야 함
		// qsort(queue.data, nowSize + 1, sizeof(element), compare); // qsort 
		// HeapSort(queue.data, nowSize + 1);
		
	}
	// 넣기 끝!

	nowSize = getSize(&queue, size);

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int k;
		scanf("%d", &k);
		printf("%d ", getCnt(&queue, nowSize, k));
	}

	destroy_queue(&queue);
	return 0;
}