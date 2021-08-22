//结点定义
typedef struct node
{
	char data;
	struct node * Lchild;
	struct node * Rchild;
}BTnode, *pBTnode;

//传参初始化
void creat_BT(pBTnode * root) //注意必须是二级指针，否则就是赋值，无法改变外部的值
{
	char ch;
	scanf("%c", &ch);
	if(ch == '#'|| ch == '\n'){ //注意回车结束
		*root = NULL;
	}else
  {
		*root = (pBTnode)malloc(sizeof(BTnode)); //给外部指针赋值
		if(*root != NULL){
			(*root)->data = ch;
			creat_BT(&(*root)->Lchild); //同样需要传入指针的地址
			creat_BT(&(*root)->Rchild);
		}
		else{
			printf("creaat failed \n");
			exit(-1);
		}
	}
	return;
}

//返回值初始化
pBTnode creat2_BT(void)
{
	char ch;
	pBTnode root = NULL;
	scanf("%c", &ch);
	if(ch == '#' || ch == '\n'){
		root = NULL;
	}
	else{
		root = (pBTnode)malloc(sizeof(BTnode));
		if(root != NULL){
			root->data = ch;
			root->Lchild = creat2_BT();
			root->Rchild = creat2_BT();
		}else
		{
			printf("creaat failed \n");
			exit(-1);
		}
	}
	return root;
}

//先序遍历
void pre_order_BT(pBTnode root)
{
	if(root == NULL)
	{
		return;
	}
	else
	{
		printf("%c", root->data);
		pre_order_BT(root->Lchild);
		pre_order_BT(root->Rchild);
	}
}

//中序遍历
void in_order_BT(pBTnode root)
{
	if(root == NULL){
		return;
	}else
	{
		in_order_BT(root->Lchild);
		printf("%c", root->data);
		in_order_BT(root->Rchild);
	}
}

//后序遍历
void post_order_BT(pBTnode root)
{
	if(root == NULL){
		return;
	}else
	{
		post_order_BT(root->Lchild);
		post_order_BT(root->Rchild);
		printf("%c", root->data);
	}
}





