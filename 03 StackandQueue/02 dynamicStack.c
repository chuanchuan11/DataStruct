//结点定义
typedef struct node
{
	int data;
	struct node * pnext;
}node, *pnode;

//栈定义
typedef struct stack
{
	pnode top;
	pnode bottom;
}Stack, *pStack;

//初始化
void init_stack(pStack ss)
{
		ss->bottom = (pnode)malloc(sizeof(node)); //创建栈底结点
		ss->bottom->pnext = NULL;                 //栈底结点不存放数据
		ss->top = ss->bottom;					            //空栈
}

//为空
bool is_empty(Stack ss)
{
	return ss.top == ss.bottom? true:false;
}

//入栈
void push_stack(pStack ss, int value)
{
	pnode newNode = NULL;
	if(NULL == ss)
	{
		printf("invaild stack \n");
	}
	else
	{
		newNode = (pnode)malloc(sizeof(node));
		newNode->data = value;     //放值
		newNode->pnext = ss->top;  //新结点指向top
		ss->top = newNode;		     //top移动指向新结点
	}
}

//遍历
void traverse(pStack ss)
{
	pnode pTemp = ss->top;
	while(pTemp != ss->bottom)
	{
		printf("%d ", pTemp->data);
		pTemp = pTemp->pnext;
	}

	printf("\n");
}

//出栈
int pop_stack(pStack ss)
{
	if(is_empty(*ss))
	{
		printf("stack is empty \n");
		exit(-1);
	}
	else
	{
		pnode pTemp = ss->top;      //保存指针
		int result = ss->top->data; //保存值
		ss->top=pTemp->pnext;		    //top移动位置
		free(pTemp);				        //释放废弃空间
		pTemp = NULL;
		return result;
	}
}

//清空
void clear(pStack ss)
{
	while(!is_empty(*ss))
	{
		pnode pTemp = ss->top;  //保存指针
		ss->top=pTemp->pnext;		//top移动位置
		free(pTemp);				    //释放废弃空间
		pTemp = NULL;
	}
}



