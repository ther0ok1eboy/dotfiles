#include <stdio.h>
#include "stack.h"

//初始化栈
void init_stack(Stack* p_stack)
{
	p_stack->num = 0;

}

//清空栈
void delete_stack(Stack* p_stack)
{
	p_stack->num = 0;
}

//得到栈的个数
int num_stack(const Stack* p_stack)
{
	return p_stack->num;
}

//判断栈是否满了
int full_stack(const Stack* p_stack)
{
	return p_stack->num >= SIZE;
}

//判断栈是否为空
int empty_stack(const Stack* p_stack)
{
	return (!p_stack->num); // 1 表示空
}

int push_stack(Stack* p_stack, int val)
{
	if(full_stack(p_stack))
	{
		printf("stack is full\n");
		return 0; //表示插入失败
	}

	p_stack->arr[p_stack->num] = val;
	p_stack->num++;
	
	return 1;         //表示插入成功
}

int pop_stack( Stack* p_stack, int* gain_val)
{
	if(empty_stack(p_stack))
	{
		printf("stack is empty\n");
		return 0;
	}

	*gain_val = p_stack->arr[p_stack->num - 1];
	p_stack->num--;

	return 1;
}

int top_stack(const Stack* p_stack, int* gain_val)
{

	if(empty_stack(p_stack))
	{
		printf("stack is empty\n");
		return 0;
	}

	*gain_val = p_stack->arr[p_stack->num - 1];
	
	return 1;
}

void print_stack(const Stack* p_stack)
{
	if(empty_stack(p_stack))
		return;

	for(int i = 0; i < p_stack->num; i++)
		printf("%d ", p_stack->arr[i]);

}

int bubble_sort(Stack* p_stack)
{
	if(empty_stack(p_stack))
	{
		printf("stack is empty\n");
		return 0;
	}

	int temp = 0;
	for(int i = 0; i < p_stack->num; i++)
		for(int j = i + 1; j < p_stack->num; j++)
		{
			if(p_stack->arr[i] > p_stack->arr[j])
			{
				temp = p_stack->arr[i];		
				p_stack->arr[i] = p_stack->arr[j];
				p_stack->arr[j] = temp;
			}
		
		}


	return 1;
}

