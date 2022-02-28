#include"sqstack.h"


//����
sqstack* st_create(void) {
	sqstack* sp;
	sp = malloc(sizeof(*sp));
	if (sp==NULL) {
		return NULL;
	}
	sp->top = -1;
	return sp;
}
//�п�
int st_isempty(sqstack* sp) { 
	return (sp->top==-1);
}
//��ջ
int st_push(sqstack* sp, type* dp) {
	if (sp->top==SIZE) {
		return -1;
	}
	sp->top++;
	sp->data[sp->top] = *dp;
//	sp->data[++sp->top] = *dp;
	return 0;
}
//��ջ
int st_pop(sqstack* sp, type* dp) {
	if (st_isempty(sp)) {
		return -1;
	}
	*dp = sp->data[sp->top];
	sp->top--;
	return 0;
}
//ȡջ��
int st_top(sqstack* sp, type* dp) { 
	if(st_isempty(sp)) {
		return -1;
	}
	*dp = sp->data[sp->top];

	return sp;
}
//����
void st_travel(sqstack* sp) {
	if (st_isempty(sp)) {
		return;
	}
	int i;
	for (i = 0; i <= sp->top; i++) {
		printf("%d  ", sp->data[i]);
	}
	printf("\n");
}
//����
void st_destory(sqstack* sp) {
	free(sp);
}
