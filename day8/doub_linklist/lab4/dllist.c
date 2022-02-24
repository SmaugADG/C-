#include"dllist.h"

struct dllist_node_st {
	struct dllist_node_st* prev;
	struct dllist_node_st* next;
	char data[1];//C99��׼����Ϊ0��֮ǰ�İ汾����Ϊ0
};

struct dllist_head_st {
	int size;
	struct dllist_node_st head;
};

//�����ڲ����Һ���
static struct dllist_node_st* find_(struct dllist_head_st* lp, const void* key, dllinst_cmp* cmp) {
	struct dllist_head_st* llp=lp;
	struct dllist_node_st* cur;
	
	for (cur = llp->head.next; cur != &llp->head; cur = cur->next) {
		if (cmp(key, cur->data) == 0) {
			break;
		}
	}
	return cur;
}

//��������
LLIST* dllist_create(int initsize) {
	struct dllist_head_st* newnode;
	newnode = malloc(initsize);
	if (newnode==NULL) {
		return NULL;
	}
	newnode->head.next = &newnode->head;
	newnode->head.prev = &newnode->head;
	newnode->size = initsize;
	return newnode;
}
//����
int dllist_insert(struct dllist_head_st* lp, const void* data, int mod) {
	struct dllist_head_st* llp=lp;
	struct dllist_node_st* newnode;
	newnode = malloc(sizeof(*newnode)+llp->size-4);//���node��Ϊdata[0]���Ͳ���-4
	if (newnode == NULL) {
		return -1;
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
void *dllist_find(struct dllist_head_st* lp, const void* key, dllinst_cmp* cmp) {
	struct dllist_head_st* llp=lp;
	struct dllist_node_st* node;
	node = find_(llp,key,cmp);
	if (node==&llp->head) {
		return NULL;
	}
	return node->data;

}
//����
void dllist_travel(struct dllist_head_st* lp,dllist_op* op) {

	struct dllist_head_st* llp=lp ;
	struct dllist_node_st* cur, * tmp ;
	for (cur = llp->head.next; cur != &llp->head;cur=cur->next) {
		op(cur->data);
	}
}

//ɾ��
int dllist_delete(struct dllist_head_st* lp, const void* key, dllinst_cmp* op) {
	struct dllist_node_st* node;
	struct dllist_head_st* llp=lp;
	node = find_(llp,key,op);
	if (node==&llp->head) {
		return -1;
	}
	node->prev->next = node->next;
	node->next->prev = node->prev;//���󣡷ô��ͻδ���
	free(node);
	node = NULL;
	return 0;
}
//��ȡԪ��
int dllist_fetch(struct dllist_head_st* lp, const void* key, dllinst_cmp* op, void* data) {
	struct dllist_head_st* llp=lp;
	struct dllist_node_st* node;
	node = find_(llp, key, op);
	if (node==&llp->head) {
		return -1;
	}
	node->prev->next = node->next;
	node->next->prev = node->prev;
	if (data!=NULL) {
		memcpy(data,node->data,llp->size);
	}
	free(node);
	node = NULL;
	return 0;
}
//����
void dllist_destory(struct dllist_head_st* lp) {
	struct dllist_head_st* llp=lp;
	struct dllist_node_st* tmp,*cur;
	if (!llp) {
		return;
	}
	for (tmp = llp->head.next; tmp!=&llp->head;tmp=cur) {
		cur = tmp->next;
		free(tmp);
	}

	free(llp);
	tmp = NULL;
	cur = NULL;
}



