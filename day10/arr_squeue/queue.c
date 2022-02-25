#include"queue.h"
//����
Queue* queue_create() {
	Queue* queue;
	queue = malloc(sizeof(*queue));
	if (!queue) {
		return NULL;
	}
	queue->head = 0;
	queue->tail = 0;

	return queue;
}
//�п�
int queue_isempty(Queue* q) {
	return (q->tail) - (q->head);//0Ϊ��
}
//����
static int queue_isfull(Queue* q) {
	return ((q->tail + 1) % MAXSIZE) - (q->head);//0Ϊ��
}
//���
int queue_enqueue(Queue* q, datatype* dp) {
	if (!queue_isfull(q)) {
		return -1;
	}
	q->tail = (q->tail + 1) % MAXSIZE;
	q->data[q->tail] = *dp;
	return 0;
}
//����
int queue_dequeue(Queue* q, datatype* dp) {
	if (!queue_isempty(q)) {
		return -1;
	}
	q->head = (q->head + 1) % MAXSIZE;
	*dp = q->data[q->head];
	return 0;
}
//����
void queue_travel(Queue* q){
	int i;
	if (!queue_isempty(q)) {
		return;
	}
	i = (q->head + 1) % MAXSIZE;
	while (i!=q->tail) {
		printf("%d ",q->data[i]);
		i = (i + 1) % MAXSIZE;
	}
	printf("%d\n",q->data[i]);
}
//���
void queue_clear(Queue* q){
	q->tail = q->head;
}
//����
void queue_destory(Queue* q) {
	free(q);
}