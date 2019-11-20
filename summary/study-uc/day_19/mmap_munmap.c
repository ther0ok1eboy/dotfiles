//将一块物理内存映射到进程的虚拟地址空间
//ldd a.out 查看可执行程序与拿些dll绑定

#include <stdio.h>
#include <sys/mman.h>
#include <string.h>

int main(void)
{
	//这些参数都可以通过man 2 mmap 查看
	int prot = PROT_READ|PROT_WRITE;
	int flags = MAP_PRIVATE|MAP_ANONYMOUS;
	void *p_map = mmap(NULL, 128, prot, flags, -1, 0);
	if(MAP_FAILED == p_map)
	{
		perror("error tips:");
		return -1;
	}

	printf("mmap call sucessful...\n");

	strcpy(p_map, "map to address sucessful...\n");
	printf("%s", (char *)p_map);

	//解除映射
	munmap(p_map, 128);
	return 0;
}
