#include "queue.h"
static void always_match(const void*p1,const void*p2) {
	return 0;
}
Queue* queue_create(int size) {
	return dllist_create(size);
}
int queue_enqueue(Queue* q, const void* data) {
	return dllist_insert(q,data,LLIST_BACKWORD);//β�巨
}
int queue_dequeue(Queue* q, void* data) {
	return dllist_fetch(q,(void*)0,always_match,data);//���ݼٲ���ʵ��ͷɾ��
}
void queue_destory(Queue* q) {
	dllist_destory(q);
}