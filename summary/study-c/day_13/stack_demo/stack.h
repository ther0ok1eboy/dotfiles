#ifndef __STACK_H__
#define __STACK_H__

typedef struct
{
	int arr[SIZE];
	int num;       //stack里的有效数据
}Stack;

//初始化栈
void init_stack(Stack* p_stack);

//清空栈
void delete_stack(Stack* p_stack);

//得到栈的个数
int num_stack(const Stack* p_stack);

//判断栈是否满了
int full_stack(const Stack* p_stack);

//判断栈是否为空
int empty_stack(const Stack* p_stack);

//插入
int push_stack(Stack* p_stack, int val);

//弹出栈顶元素
int pop_stack( Stack* p_stack, int* gain_val);

//获取栈顶元素
int top_stack(const Stack* p_stack, int* gain_val);

//打印
void print_stack(const Stack* p_stack);

//排序
int bubble_sort(Stack* p_stack);

#endif //__STACK_H__	
