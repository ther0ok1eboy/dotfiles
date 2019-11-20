#include <stdio.h>
#include <stdlib.h>

//逻辑结构
// a 集合结构 b 线性结构 c 树状结构 d 网状结构

//物理结构
// a 顺序结构 b 链式结构

typedef struct Node
{
	int val;
	struct Node* next;
}node;

void insert(int val)
{

	node num1 = {233, NULL}, num2 = {999, NULL}, num3 = {6666, NULL}, num4 = {6669, NULL};
	node head = {0, NULL}, tail = {0, NULL};
	head.next = &num1;
	num1.next = &num2;
	num2.next = &num3;
	num3.next = &num4;
	num4.next = &tail;
	tail.next = NULL;

	node new_node = {val, NULL};

	node* p_node = NULL;
	for(p_node = head.next; p_node != &tail; p_node = p_node->next)
	{
		node* p_first = p_node;
		node* p_mid = p_first->next;
		node* p_last = p_mid->next;
		if(p_mid == &tail || p_mid->val > val)
		{
			p_first->next = &new_node;
			new_node.next = p_mid;
			break;
		}
	}


	for(p_node = head.next; p_node != &tail; p_node = p_node->next)
		printf("num = %d\n", p_node->val);
	printf("\n");
}


void delete(int val)
{

	node num1 = {233, NULL}, num2 = {999, NULL}, num3 = {666, NULL}, num4 = {6669, NULL};
	node head = {0, NULL}, tail = {0, NULL};
	head.next = &num1;
	num1.next = &num2;
	num2.next = &num3;
	num3.next = &num4;
	num4.next = &tail;

	node* p_node = NULL;
	for(p_node = head.next; p_node != &tail; p_node = p_node->next)
	{
		node* p_first = p_node;
		node* p_mid = p_first->next;
		node* p_last = p_mid->next;
		if(p_mid != &tail && p_mid->val == val)
			p_first->next = p_last;
	}


	for(p_node = head.next; p_node != &tail; p_node = p_node->next)
		printf("num = %d\n", p_node->val);
	printf("\n");
}

void main01()
{
	node num1 = {233, NULL}, num2 = {999, NULL}, num3 = {666, NULL};
	node head = {0, NULL}, tail = {0, NULL};
	head.next = &num1;
	num1.next = &num2;
	num2.next = &num3;
	num3.next = &tail;
	printf("num3.val = %d\n", head.next->next->next->val);

	node* p_node = NULL;
	for(p_node = head.next; p_node != &tail; p_node = p_node->next)
		printf("num = %d\n", p_node->val);
	printf("\n");

}

void main02()
{
	node tail = {0, NULL}, head = {0, NULL};
	head.next = &tail;

	for(int i = 0; i < 5; i++)
	{
		printf("please input data without -num\n");
		node* new_node = (node* )malloc(sizeof(node));
		if(!new_node){continue;}
		scanf("%d", &(new_node->val));
		new_node->next = NULL;

		for(node* p_node = &head; p_node != &tail; p_node = p_node->next)
		{	
			node* p_first = p_node;
			node* p_mid = p_first->next;
			node* p_last = p_mid->next;
			
			//从小到大插入
			if(p_mid == &tail || p_mid->val > new_node->val)
			{
				p_first->next = new_node;
				new_node->next = p_mid;
				break;
			
			}
		}
	}


	for(node* p_node = &head; p_node != &tail; p_node = p_node->next)
	{	
		node* p_first = p_node;
		node* p_mid = p_first->next;
		node* p_last = p_mid->next;
	
		if(p_mid != &tail)
			printf("%d ", p_mid ->val);
	
	}

/**********************我的遍历方式************************		
       	node* p_node = head.next;
	while(1)
	{
		if(p_node == &tail)
			break;
		printf("%d ", p_node->val);
		p_node = p_node->next;
		
	}
	
**********************************************************/	
	while(head.next != &tail)
	{	
		node* p_first = &head;
		node* p_mid = p_first->next;
		node* p_last = p_mid->next;
	
		p_first->next = p_last;
		free(p_mid);
		p_mid = NULL;
			
	}

/*********************我的释放**************************
		
		node* p_temp = NULL;
		node* p_node = head.next;
		while(1)
		{	
			if(p_node == &tail)
				break;
		
			p_temp = p_node->next;
			free(p_node);
			p_node = p_temp;

		}

*******************************************************/		
}

void main(int args, char* argv[])
{

	//main01();
	main02();
	//insert(8888);
	//delete(6669);

}
