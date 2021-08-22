//栈定义
#define MAX_NUM 5
typedef struct Statck
{
	int data[MAX_NUM];  //栈空间
	int top;			//栈顶位置
}SStack, *pSStack;


//初始化
void Stack_init(pSStack pStack)
{
		memset(pStack->data, 0, sizeof(pStack->data)); //元素初始化
		pStack->top = -1;                              //栈顶位置初始化
}

//为空
bool is_empty(pSStack pStack)
{
	return (pStack->top == -1? true:false);
}

//满
bool is_full(pSStack pStack)
{
	return (pStack->top == MAX_NUM-1? true:false);
}

//入栈
void push_stack(pSStack pStack, int value)   //需要修改栈元素则指针传参
{
	if(NULL == pStack)
	{
		printf("invaild stack \n");
	}
	else if(is_full(pStack))
	{
		printf("stack is full \n");
	}
	else
	{
		pStack->data[++(pStack->top)] = value;
	}
}

//出栈
int pop_stack(pSStack pStack) //需要修改栈元素则指针传参
{
	if(NULL == pStack)
	{
		printf("invaild stack \n");
		exit(-1);
	}
	else if(is_empty(pStack))
	{
		printf("stack is empty \n");
		exit(-1);
	}
	else
	{
		return pStack->data[(pStack->top)--];
	}
}

//栈元素个数
int stack_length(SStack Stack) //不需要修改栈元素则赋值传参
{
	return (Stack.top)+1;
}

//遍历
void Traverse_stack(SStack Stack) //不需要修改栈元素则赋值传参
{
	while(Stack.top != -1)
	{
		printf("%d ", Stack.data[Stack.top--]);
	}
	printf("\n");
}

