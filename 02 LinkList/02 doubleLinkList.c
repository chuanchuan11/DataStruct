//结点定义
typedef int data_t;
typedef struct dLinkList
{
	data_t data;
	struct dLinkList * pre;  //前驱
	struct dLinkList * next; //后继
}DLinkList, * pDlinkList;


//链表创建
pDlinkList creat_DlinkList()
{
	pDlinkList pHead = NULL;
	pHead = (pDlinkList)malloc(sizeof(DLinkList)); //头结点

	pHead->pre = NULL;    // 指向空
	pHead->next = NULL;   // 指向空

	return pHead;  //头指针
}

//为空
bool empty_DlinkList(pDlinkList pHead)
{
	return (pHead->next == NULL);  
}

//头插
void head_insert(pDlinkList pHead, int value)
{
	pDlinkList pTemp = pHead;
	pDlinkList pNewNode = NULL;

	pNewNode = (pDlinkList)malloc(sizeof(DLinkList));

	if(empty_DlinkList(pTemp)) //为空时插入
	{
		pNewNode->data = value;

		pNewNode->pre = pHead;        
		pNewNode->next = pHead->next;
		//pHead->next->pre = pNewNode; 为NULL
		pHead->next = pNewNode;	
	}
	else
	{
		pNewNode->data = value;

		pNewNode->pre = pHead;
		pNewNode->next = pHead->next;  
		pHead->next->pre = pNewNode;    
		pHead->next = pNewNode;	 
	}
}

//位置插
void pos_insert(pDlinkList pHead, int pos, int value)
{
	pDlinkList pTemp = pHead;
	pDlinkList pNewNode = NULL;
	int i = 0;
	while(pTemp != NULL && i < pos)  //查找位置
	{
		pTemp = pTemp->next;
		i++;
	}

	if(pTemp==NULL || i>pos) return;
	else
	{
		pNewNode = (pDlinkList)malloc(sizeof(DLinkList)); 

		pNewNode->data = value;

		pNewNode->pre = pTemp->pre;
		pNewNode->next = pTemp;
		pTemp->pre->next = pNewNode;  //注意不能与下方的顺序反
		pTemp->pre = pNewNode;	
	}
}

//删
void delete_value(pDlinkList pHead, int pos)
{
	pDlinkList pTemp =  pHead;
	int i = 0;

	while(pTemp != NULL && i<pos)
	{
	pTemp = pTemp->next;
	i++;
	}
	if(pTemp == NULL || i>pos)  return;
	else
	{
	pTemp->pre->next = pTemp->next;
	pTemp->next->pre = pTemp->pre;
	free(pTemp);
	pTemp = NULL;
	}
}

//改
void change_value(pDlinkList pHead, int pos, int value)
{
	pDlinkList pTemp = pHead;
	int i = 0;

	while(pTemp != NULL && i<pos)  //查位置
	{
		pTemp = pTemp->next;
		i++;
	}
	
	if(pTemp == NULL || i>pos) return; 
	else
	{
		pTemp->data = value;
	}
}



