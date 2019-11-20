#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* change_log(void)
{
	
	char ch = 'y';
	static char new_psd[32] = {0};
	char check_psd[32] = {0};
	printf("do you want to change your recent passwords?\n");
	printf("press y to change or n\n");
	scanf("%c", &ch);

	if(ch == 'y')
	{
		printf("please input your new passwords\n");
		scanf("%s", new_psd);
		printf("please input your new passwords again to comfirm\n");
		scanf("%s", check_psd);
		
		int tag = strcmp(new_psd, check_psd);
		if(tag == 0)
		{
			printf("change sucessfully\n");
			return new_psd;
		}
		else
		{
			printf("change defualt\n");
			sscanf("123456", "%s", new_psd); 
			return new_psd;
		}
	
	}

	else
	{
	
			sscanf("123456", "%s", new_psd); 
			return new_psd;
	}


}

void log_atm(void)
{
	
	char* rpsd = change_log();	
	char psd[32] = {0};

	printf("please input your passwords\n");
	for(int i = 2; i >= 0; i--)
	{

		scanf("%s", psd);
		if(!strcmp(rpsd, psd))
		{
			printf("your passwords are right\n");
			break;
		}
		else
		{
			if(i != 0)	
			printf("you have %d try\n", i);
		}
	
	}


}

int main()
{

	log_atm();
	return 0;
}
