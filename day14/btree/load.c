#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define NAMESIZE 32
#define FNAME "btree/save/save.txt"
struct node_st {
	struct node_st* lchild,*rchild;
	char data;
};
/**
*��������
*/

//��������ӡ��ʾ��
static void draw_(struct node_st* root, int level) {
	int i;
	if (root == NULL) {
		return;
	}
	draw_(root->rchild, level + 1);
	for (i = 0; i < level; i++) {//{1,3,2,7,6,5,9,8,4 };
		printf("|----");
		
	}
	printf("%c\n", root->data);
	draw_(root->lchild, level + 1);
}
static void draw(struct node_st* root) {
	draw_(root, 0);
	printf("=================================================\n");
}
struct node_st* load_(FILE *fp) {
	int c;
	struct node_st* root=NULL;
	c = fgetc(fp);
	if (c!='(') {
		fprintf(stderr,"fget() fail!");
		exit(1);
	}
	c = fgetc(fp);
	if (c!=')') {
		root = malloc(sizeof(*root));
		if (root == NULL) {
			exit(1);
		}
		root->data = c;
		root->lchild = load_(fp);
		root->rchild = load_(fp);
		fgetc(fp);
	}
	return root;
}
/**
*���ܺ���
*/
struct node_st* load(const char* path) {
	struct node_st *root;
	FILE* fp;
	fp = fopen(path,"r");
	if (fp==NULL) {
		return NULL;
	}

	root=load_(fp);
	fclose(fp);
	return root;
}


//����
void destory(struct node_st* root) {
	struct node_st* cur;
	if (root==NULL) {
		return;
	}
	destory(root->lchild);
	destory(root->rchild);
	free(root);
}

int main() {
	struct node_st* tree;
	tree = load(FNAME);
	//��ӡ��ʾ
	draw(tree);

	//����
	destory(tree);
	tree = NULL;
	exit(0);
}