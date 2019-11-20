#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* next;

}Node;

typedef struct
{
	int count;
	Node* head;
	Node* tail;
}Link;

void init_link(Link* p_link)
{
	p_link->count = 0;
	p_link->head->next = p_link->tail;
	p_link->tail->next = NULL;
}

void delete_link(Link* p_link)
{
	while(1/*p_link->head->next != p_link->tail*/)
	{
		Node* p_first = p_link->head;
		Node* p_mid = p_first->next;
		Node* p_last = p_mid->next;

		if(p_mid == p_link->tail)
			break;

		p_first->next = p_last;
		free(p_mid);
		p_mid = NULL;
	
	}
}

int size_link(const Link* p_link)
{
	/*return p_link->count;*/

	int num = 0;
	for(Node* p_node = p_link->head; p_node != p_link->tail; p_node = p_node->next)
	{
		Node* p_first = p_node;
		Node* p_mid = p_first->next;
		Node* p_last = p_mid->next;

		if(p_mid != p_link->tail)
			num++;
	}

	return num;
}

int empty_link(const Link* p_link)
{
	/*return p_link->count;*/
	return !(p_link->head == p_link->tail);

}

int head_insert_link(Link* p_link, int insert_val)
{

	Node* new_node = (Node* )malloc(sizeof(Node));
	if(!new_node){return 0;}

	new_node->data = insert_val;
	new_node->next = NULL;
	p_link->count++;

	Node* p_first = p_link->head;
	Node* p_mid = p_first->next;
	Node* p_last = p_mid->next;

	p_first->next = new_node;
	new_node->next = p_mid;

	return 1;
}

int tail_insert_link(Link* p_link, int insert_val)
{

	Node* new_node = (Node* )malloc(sizeof(Node));
	if(!new_node){return 0;}

	new_node->data = insert_val;
	new_node->next = NULL;
	p_link->count++;

	for(Node* p_node = p_link->head; p_node != p_link->tail; p_node = p_node->next)
	{
		Node* p_first = p_node;
		Node* p_mid = p_first->next;
		Node* p_last = p_mid->next;
		
		if(p_mid == p_link->tail)
		{
			p_first->next = new_node;
			new_node->next = p_mid;
			break;      //这个不能丢
		}
		
	}

	return 1;


}

int sort_insert_link(Link* p_link, int insert_val)
{
	Node* new_node = (Node* )malloc(sizeof(Node));
	if(!new_node){return 0;}

	new_node->data = insert_val;
	new_node->next = NULL;
	p_link->count++;

	for(Node* p_node = p_link->head; p_node != p_link->tail; p_node = p_node->next)
	{
		Node* p_first = p_node;
		Node* p_mid = p_first->next;
		Node* p_last = p_mid->next;
		
		if(p_mid == p_link->tail || p_mid->data > new_node->data)//位置不能换 想想为什么？？
		{
			p_first->next = new_node;
			new_node->next = p_mid;
			break;      //这个不能丢
		}

	}

	return 1;
}

int front_remove_link(Link* p_link)
{	
	if(p_link->head->next == p_link->tail)
		return 0;

	Node* p_first = p_link->head;
	Node* p_mid = p_first->next;
	Node* p_last = p_mid->next;

	p_first->next = p_last;
	free(p_mid);
	p_mid = NULL;

	return 1;
}

int tail_remove_link(Link* p_link)
{	

	for(Node* p_node = p_link->head; p_node != p_link->tail; p_node = p_node->next)
	{
		Node* p_first = p_node;
		Node* p_mid = p_first->next;
		Node* p_last = p_mid->next;

		if(p_last == p_link->tail)
		{
			p_first->next = p_last;
			free(p_mid);
			p_mid = NULL;
			return 1;
		}
	}

	//考虑到只有头尾结点的时候p_first->next永远到不了p_last
	return 0;
}

int remove_link(Link* p_link, int remove_val)
{

	if(p_link->head->next == p_link->tail)
		return 0;

	for(Node* p_node = p_link->head; p_node != p_link->tail; p_node = p_node->next)
	{
		Node* p_first = p_node;
		Node* p_mid = p_first->next;
		Node* p_last = p_mid->next;

		if(p_mid != p_link->tail && p_mid->data == remove_val)
		{
			p_first->next = p_last;
			free(p_mid);
			p_mid = NULL;
			return 1;
		}
	}

	return 0;
}

int get_head_link(const Link* p_link, int* get_val)
{	
	if(p_link->head->next == p_link->tail)
		return 0;
	
	Node* p_first = p_link->head;
	Node* p_mid = p_first->next;
	Node* p_last = p_mid->next;

	*get_val = p_mid->data;
	
	return 1;
}

int get_tail_link(const Link* p_link, int* get_val)
{	
	if(p_link->head->next == p_link->tail)
		return 0;

	for(Node* p_node = p_link->head; p_node != p_link->tail; p_node = p_node->next)
	{
		Node* p_first = p_node;
		Node* p_mid = p_first->next;
		Node* p_last = p_mid->next;

		if(p_last == p_link->tail)
		{
			*get_val = p_mid->data;
			return 1;
		}
	}

}

int get_data_link(const Link* p_link, int* get_val, int pos)
{
	if(p_link->head->next == p_link->tail || p_link->count - 1 < pos) 
		return 0;

	int count = -1;
	for(Node* p_node = p_link->head; p_node != p_link->tail; p_node = p_node->next)
	{
		Node* p_first = p_node;
		Node* p_mid = p_first->next;
		Node* p_last = p_mid->next;

		count++;
		if(p_mid != p_link->tail && count == pos)
		{
			*get_val = p_mid->data;
			return 1;
		}

	}

	return 0;
}

void print_link(const Link* p_link)
{
	if(p_link->head->next == p_link->tail)
	       return;	

	for(Node* p_node = p_link->head; p_node != p_link->tail; p_node = p_node->next)
	{
		Node* p_first = p_node;
		Node* p_mid = p_first->next;
		Node* p_last = p_mid->next;

		if(p_mid != p_link->tail)
			printf("%d ", p_mid->data);
	}

}

void link_data_framework()
{
	int data = 0;
	Node head = {0};
	Node tail = {0};
	head.next = &tail;

	while(1)
	{
		scanf("%d", &data);
		if(data < 0)
			break;
		Node* new_node = (Node* )malloc(sizeof(Node));
		new_node->data = data;
		new_node->next = NULL;

		for(Node* p_node = &head; p_node != &tail; p_node = p_node->next)
		{
			Node* p_first = p_node;
			Node* p_mid = p_first->next;
			Node* p_last = p_mid->next;

			if(p_mid == &tail || p_mid->data > new_node->data)
			{
				p_first->next = new_node;
				new_node->next = p_mid;
				break;  // 这个不能丢
			}
		
		}
	
	}


	for(Node* p_node = &head; p_node != &tail; p_node = p_node->next)
	{
		Node* p_first = p_node;
		Node* p_mid = p_first->next;
		Node* p_last = p_mid->next;

		if(p_mid != &tail)
			printf("%d ", p_mid->data);
	
	}
	printf("\n");

	while(1)
	{
		Node* p_first = &head;
		Node* p_mid = p_first->next;
		Node* p_last = p_mid->next;

		if(p_mid == &tail)
			break;

		p_first->next = p_last;
		free(p_mid);
		p_mid = NULL;
	}


}

void main(int args, char* argv[])
{

	// link_data_framework();

	 
	 
	 
	 
	Link link = {0};
	sort_insert_link(&link, 20);
	sort_insert_link(&link, 10);
	sort_insert_link(&link, 50);
	sort_insert_link(&link, 30);
	sort_insert_link(&link, 40);
	sort_insert_link(&link, 60);

	print_link(&link);
	int val = 0;
	//get_head_link(&link, &val);
	//printf("%d\n", val);
	printf("%d\n", size_link(&link));
}
