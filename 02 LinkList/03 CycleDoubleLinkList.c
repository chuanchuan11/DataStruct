//结点定义
typedef int data_t;
typedef struct dLinkList
{
	data_t data;
	struct dLinkList * pre;  //前驱
	struct dLinkList * next; //后继
}DClinkList, * pDClinkList;


//创建
pDClinkList list_creat()
{
  pDClinkList Head = (pDClinkList)malloc(sizeof(DClinkList));

  Head->next = Head;  //前驱和后继都指向自己
  Head->pre = Head;
}

//空
bool list_empty(pDClinkList head)
{
	bool result = true;
	pDClinkList cur = head;
	if(cur->next ！= head)
	{
      result = false;
	}
	return result;
}

//遍历
void list_show(pDClinkList head)
{
	pDClinkList cur = NULL;
	int i = 0;

  cur = cur->next;
  while(cur != head)  //结束
  {
    printf("list[%d]=%d \n", i, cur->data);
    ++i;
    cur = cur->next;
  }
}

//头插
void head_insert(pDClinkList head, int value)
{
	pDClinkList cur = head;
	pDClinkList pTemp = NULL;

	pTemp = (pDClinkList)malloc(sizeof(DClinkList));

  if(pTemp != NULL)
  {
    pTemp->data = value;

    pTemp->pre = cur;
    pTemp->next = cur->next;
    cur->next->pre = pTemp; //不能搞反
    cur->next = pTemp;
  }
}

//尾插
void tail_insert(pDClinkList head, int value)
{
	pDClinkList cur = head;
	pDClinkList pTemp = NULL;

  pTemp = (pDClinkList)malloc(sizeof(DClinkList));
  if(pTemp == NULL)
  {
    printf("insert failed \n");
    return;
  }
  else
  {
    pTemp->data = value;

    pTemp->pre = cur->pre;
    pTemp->next = cur;
    cur->pre->next = pTemp;
    cur->pre = pTemp;
  }
}

//查位置
pDClinkList pos_find(pDClinkList head,int pos)
{
	pDClinkList cur = head;
	pDClinkList result = NULL;
	int i = 0;

	if(cur == NULL)  printf("invaild list \n");
	else if(pos < 1) printf("invaild POS \n");
	else
	{
		if(cur->next == head && pos == 1) result = head;  //为空返回头结点
		else
		{
			while(cur->next != head && i<pos)
			{
				cur = cur->next;
				++i;
			}
			if(i>pos) printf("查找失败 \n");
			else      result = cur;  //返回当前位置
		}
	}
  
	return result;
}

//位置删除
void pos_delete(pDClinkList head, int pos)
{
	pDClinkList pTemp = pos_find(head, pos);

	if(pTemp == NULL)
	{
		printf("delete failed \n");
	}
	else
	{
		pTemp->pre->next = pTemp->next;
		pTemp->next->pre = pTemp->pre;

		free(pTemp);
		pTemp = NULL;
	}
}

//获取长度
int list_length(pDClinkList head)
{
	pDClinkList cur = head;
	int i =0;

	while(cur->next != head)
	{
		cur = cur->next;
		++i;
	}

	return i;
}




