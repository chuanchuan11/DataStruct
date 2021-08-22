//队列定义
#define MAX_NUM 6

typedef struct queue
{
	int data[MAX_NUM];  //队列数据域
	int front;			    //队列第一个元素位置
	int rear;			      //队列最后一个有效元素的下一个位置
}Queue, * pQueue;


//初始化
void Queue_init(pQueue queue)
{
	memset(queue->data, 0, sizeof(queue->data)); 
	queue->front = 0;         //初始化front和rear为0
	queue->rear = 0;
}

//为空
bool is_empty(Queue queue)
{
	return queue.front == queue.rear? true:false;
}

//满
bool is_full(Queue queue)
{
	return ((queue.rear+1)%MAX_NUM == queue.front)?true:false;
}

//入队
void in_queue(pQueue queue, int value)
{
	if(is_full(*queue))
	{
		printf("queue is full \n");
	}
	else
	{
		queue->data[queue->rear] = value;      //先放值
		queue->rear = (++queue->rear)%MAX_NUM; //移动rear位置
	}
}

//出队
int out_queue(pQueue queue)
{
	if(is_empty(*queue))
	{
		printf("queue is empty \n");
	}
	else
	{
		int result = queue->data[queue->front];  //保存值
		queue->front = (++queue->front)%MAX_NUM; //移动front位置
		return result;
	}
}

//遍历
void traverse(Queue queue)
{
	while(queue.front != queue.rear)
	{
		printf("%d ", queue.data[queue.front]);  //遍历数据
		queue.front = (++queue.front)%MAX_NUM;	 //移动位置
	}

	printf("\n");
}
