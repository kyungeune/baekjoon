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
void push(QueueType* q, int size, int k)
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
		int i = q->front;
		do {
			i = (i + 1) % size;
			if (i == q->rear)
				break;
		} while (i != q->front);

		q->rear = (q->rear + 1) % size;
		q->data[q->rear] = item;
	}
}
int pop(QueueType* q, int size)
{
	if (is_empty(q))
		return -1;
	int k = q->data[q->front + 1].num;
	q->front = (q->front + size + 1) % size;
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
	else
		return q->data[q->front + 1].num;
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
	queue.data = (element*)malloc(sizeof(element) * n);
	queue.front = queue.rear = 0;

	for (int i = 0; i < n; i++) {
		char s[10];
		scanf("%s", s);

		if (strcmp(s, "push") == 0) {
			int k;
			scanf("%d", &k);
			push(&queue, size, k);
		}
		else if (strcmp(s, "pop") == 0) {
			printf("%d\n", pop(&queue, size));
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