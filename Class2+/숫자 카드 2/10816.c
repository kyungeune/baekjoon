#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OFFSET 10000000  // 최소값이 -10,000,000 이므로 이를 상쇄하기 위한 오프셋
#define MAX_NUM 20000001 // -10,000,000 ~ 10,000,000의 범위를 다루기 위한 배열 크기

typedef struct {
    int* data;   // 숫자의 등장 횟수를 저장하는 배열
    int front, rear; // 큐의 앞(front)과 뒤(rear) 인덱스
} QueueType;

void push(QueueType* q, int size, int k)
{
    q->data[k + OFFSET]++;  // 해당 숫자의 카운트를 1 증가
}

int getCnt(QueueType* q, int k)
{
    return q->data[k + OFFSET];  // 해당 숫자의 등장 횟수를 반환
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

int main(void)
{
    QueueType queue;
    int n = 0, m = 0;
    scanf("%d", &n);
    int size = MAX_NUM;
    queue.data = (int*)calloc(size, sizeof(int));  // 카운트 배열 초기화
    queue.front = queue.rear = 0;

    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        push(&queue, size, k); // 삽입
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int k;
        scanf("%d", &k);
        printf("%d ", getCnt(&queue, k));
    }

    destroy_queue(&queue);
    return 0;
}