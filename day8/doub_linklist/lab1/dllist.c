#include"dllist.h"

//�����ڲ����Һ���
static list_node* find_(LLIST* llp, const void* key, dllinst_cmp* cmp) {
	list_node* cur;
	for (cur = llp->head.next; cur != &llp->head; cur = cur->next) {
		if (cmp(key, cur->data) == 0) {
			break;
		}
	}
	return cur;
}

//��������
LLIST* dllist_create(int initsize) {
	LLIST* newnode;
	newnode = malloc(initsize);
	if (newnode==NULL) {
		return NULL;
	}
	newnode->head.data = NULL;
	newnode->head.next = &newnode->head;
	newnode->head.prev = &newnode->head;
	newnode->size = initsize;
	return newnode;
}
//����
int dllist_insert(LLIST* llp, const void* data, int mod) {
	struct dllist_node_st* newnode;
	newnode = malloc(sizeof(*newnode));
	if (newnode == NULL) {
		return -1;
	}

	newnode->data = malloc(llp->size);
	if (newnode->data==NULL) {
		return -2;
	}
	memcpy(newnode->data,data,llp->size);
	if (mod == LLIST_FORWARD) {
		newnode->prev = &llp->head;
		newnode->next = llp->head.next;
	}
	else if (mod==LLIST_BACKWORD) {
		newnode->prev = llp->head.prev;
		newnode->next = &llp->head;
	}
	else {
		return -3;
	}
	newnode->prev->next = newnode;
	newnode->next->prev = newnode;

	return 0;
}
//����
void *dllist_find(LLIST* llp, const void* key, dllinst_cmp* cmp) {
	return find_(llp, key, cmp)->data;
}
//����
void dllist_travel(LLIST* llp,dllist_op* op) {
	list_node* cur, * tmp ;
	for (cur = llp->head.next; cur != &llp->head;cur=cur->next) {
		op(cur->data);
	}
}

//ɾ��
int dllist_delete(LLIST* llp, const void* key, dllinst_cmp* op) {
	struct dllist_node_st* node;
	node = find_(llp,key,op);
	if (node==&llp->head) {
		return -1;
	}
	node->prev->next = node->next;
	node->next->prev = node->prev;//���󣡷ô��ͻδ���
	free(node->data);
	free(node);
	node = NULL;
	return 0;
}
//��ȡԪ��
int dllist_fetch(LLIST* llp, const void* key, dllinst_cmp* op, void* data) {
	list_node* node;
	node = find_(llp, key, op);
	if (node==&llp->head) {
		return -1;
	}
	node->prev->next = node->next;
	node->next->prev = node->prev;
	if (data!=NULL) {
		memcpy(data,node->data,llp->size);
	}
	free(node->data);
	free(node);
	node = NULL;
	return 0;
}
//����
void dllist_destory(LLIST* llp) {
	list_node* tmp,*cur;
	if (!llp) {
		return;
	}
	for (tmp = llp->head.next; tmp!=&llp->head;tmp=cur) {
		cur = tmp->next;
		free(tmp->data);
		free(tmp);
	}

	free(llp);
	tmp = NULL;
	cur = NULL;
}



