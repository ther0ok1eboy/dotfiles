#include <stdio.h>
#include "stack.h"

//栈的框架
void stack_structure()
{
	Stack stack = {0};
	init_stack(&stack);
	push_stack(&stack, 10);
	push_stack(&stack, 30);
	push_stack(&stack, 20);
	push_stack(&stack, 50);
	push_stack(&stack, 40);

	int get_val = 0;
	top_stack(&stack, &get_val);
	printf("top_stack() = %d\n", get_val);
	printf("num_stack() = %d\n\n", num_stack(&stack));

	pop_stack(&stack, &get_val);
	printf("pop_stack() = %d\n", get_val);
	printf("num_stack() = %d\n\n", num_stack(&stack));
	
	bubble_sort(&stack);
	print_stack(&stack);

	printf("\n");
	while(1)
	{
		if(!pop_stack(&stack, &get_val))
			break;
		printf("%d ", get_val);
	
	}

	delete_stack(&stack);
}

//主函数
void main(int args, char* argv[])
{
	stack_structure();

}
