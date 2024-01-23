#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// deque = double - ended queue의 줄임말으로, 큐의 앞, 뒤 모두에서 삽입 및 삭제가 가능한 큐
typedef struct {
	int cnt;
	int num;
}element;
typedef struct {
	element* data;
	int  front, rear;
} QueueType;
void push_front(QueueType* q, int size, int k)
{
	element item;
	item.cnt = 0;
	item.num = k;

	if (is_full(q, size))
		return;
	else if (is_empty(q)) {
		q->rear = (q->rear + 1) % size;
		q->data[q->rear] = item;
	}
	else {
		q->data[q->front] = item;
		q->front = (q->front - 1 + size) % size;
	}
}
void push_back(QueueType* q, int size, int k)
{
	element item;
	item.cnt = 0;
	item.num = k;

	if (is_full(q, size))
		return;
	else if (is_empty(q)) {
		q->rear = (q->rear + 1) % size;
		q->data[q->rear] = item;
	}
	else {
		q->rear = (q->rear + 1) % size;
		q->data[q->rear] = item;
	}
}
int pop_front(QueueType* q, int size)
{
	if (is_empty(q))
		return -1;
	q->front = (q->front + size + 1) % size;
	return (q->data[q->front].num);
}
int pop_back(QueueType* q, int size)
{
	if (is_empty(q))
		return -1;
	int k = q->data[q->rear].num;
	q->rear = (q->rear + size - 1) % size;
	return k;
}
int getSize(QueueType* q, int size)
{
	int sum = 0;
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % size;
			sum++;
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	return sum;
}
int top(QueueType* q, int size)
{
	if (is_empty(q))
		return -1;
	else
		return q->data[q->rear].num;
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
int front(QueueType* q, int size)
{
	if (is_empty(q))
		return -1;
	
	int imsi = (q->front + 1 + size) % size;

	return q->data[imsi].num;
}
int back(QueueType* q, int size)
{
	if (is_empty(q))
		return -1;
	else
		return q->data[q->rear].num;
}

int main(void)
{
	QueueType queue;
	int n, i = 0;
	scanf("%d", &n);
	int size = n + 1;
	queue.data = (element*)malloc(sizeof(element) * size);
	queue.front = queue.rear = 0;

	for (int i = 0; i < n; i++) {
		char s[31];
		scanf("%s", s);

		if (strcmp(s, "push_front") == 0) {
			int k;
			scanf("%d", &k);
			push_front(&queue, size, k);
		}
		else if (strcmp(s, "push_back") == 0) {
			int k;
			scanf("%d", &k);
			push_back(&queue, size, k);
		}
		else if (strcmp(s, "pop_front") == 0) {
			printf("%d\n", pop_front(&queue, size));
		}
		else if (strcmp(s, "pop_back") == 0) {
			printf("%d\n", pop_back(&queue, size));
		}
		else if (strcmp(s, "size") == 0) {
			printf("%d\n", getSize(&queue, size));
		}
		else if (strcmp(s, "empty") == 0) {
			printf("%d\n", is_empty(&queue));
		}
		else if (strcmp(s, "front") == 0) {
			printf("%d\n", front(&queue, size));
		}
		else if (strcmp(s, "back") == 0) {
			printf("%d\n", back(&queue, size));
		}
	}

	destroy_queue(&queue);
	return 0;
}