#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	int arr[SIZE];
	int head;     //第一个数字下标
	int tail;     //最后一个数字的下一个下标
	int len;
}Queue;

//初始化队列
void init_queue(Queue* p_queue)
{	
	if(SIZE <= 0)
		exit(0);
	memset(p_queue->arr, 0, sizeof(Queue));
	p_queue->len = 0;
	p_queue->head = 0;
	p_queue->tail = 0;
}

//清空队列
void delete_queue(Queue* p_queue)
{
	 p_queue->len = 0;
         p_queue->head = 0;
         p_queue->tail = 0;

}

//获得队列个数
int size_queue(const Queue* p_queue)
{
	return p_queue->len;
}

//判断队列是否为满
int full_queue(const Queue* p_queue)
{
	return p_queue->len >= SIZE;
}

//判断队列是否为空
int empty_queue(const Queue* p_queue)
{
	return p_queue->len;
}

//入队
int push_queue(Queue* p_queue, int push_val)
{
	if(full_queue(p_queue))
	{
		printf("queue is full\n");
		return 0;
	}
	if(p_queue->tail == SIZE - 1)
		p_queue->tail = 0;
	p_queue->arr[p_queue->tail] = push_val;
	p_queue->tail++;
	p_queue->len++;

	return 1;

}

//出队
int pop_queue(Queue* p_queue, int* pop_val)
{
	if(!empty_queue(p_queue))
	{
		printf("queue is empty\n");
		return 0;
	}

	if(p_queue->head == SIZE - 1)
		p_queue->head = 0;
	*pop_val = p_queue->arr[p_queue->head];
	p_queue->head++;
	p_queue->len--;

	return 1;
}

//获取队头元素
int front_queue(Queue* p_queue)
{
	if(!empty_queue(p_queue))
	{
		printf("queue is empty\n");
		return 0;
	}

	return p_queue->arr[p_queue->head];

}

//获取队尾元素
int tail_queue(Queue* p_queue)
{
	if(!empty_queue(p_queue))
	{
		printf("queue is empty\n");
		return 0;
	}

	return p_queue->arr[p_queue->tail - 1];

}

//打印
void print_queue(const Queue* p_queue)
{
	if(!empty_queue(p_queue))
		return;

	for(int i = p_queue->head; i < p_queue->tail; i++)
		printf("%d ", p_queue->arr[i]);
	printf("\n");
}

//循环队列
void queue_structure_version_2()
{
	Queue queue = {0};
	int get_val = 0;
	init_queue(&queue);

	push_queue(&queue, 10); //这句结束tail = 1
	push_queue(&queue, 20);
	push_queue(&queue, 30);
	push_queue(&queue, 40);
	push_queue(&queue, 50);
	push_queue(&queue, 50);
	push_queue(&queue, 40);
	push_queue(&queue, 30);
	push_queue(&queue, 20); //这句结束tail = 9
	
	pop_queue(&queue, &get_val); //这句结束head = 1	
	
	push_queue(&queue, 666);

	printf("front_queue() = %d\n", front_queue(&queue));
	printf("tail_queue() = %d\n", tail_queue(&queue));

	//print_queue(&queue);

	while(1)
	{
		if(!pop_queue(&queue, &get_val))
		{
			printf("\n");
			break;
		}

		printf("%d ", get_val);
	}
}

int main(int args, char* argv[])
{
	queue_structure_version_2();

	return 0;
}
