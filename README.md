数据结构代码实现：

## 01 顺序表
```
    待更新
```
## 02 双向链表
```
* 初始化：
   Head->pre = Head->next = NULL //指向空
* 头插入：
   为空时：//pHead->next->pre = pNewNode; //不需要，因为该指针为NULL
   非空时：pHead->next->pre = pNewNode;   //需要

```
## 03双向循环链表
```
 * 初始化：
     Head->pre = Head->next = Head; //指向自身
 * 为空：
     Head->next = Head;
 * 遍历结束：
     cur->next = Head;
```
