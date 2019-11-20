#include <stdio.h>
#include <file_head.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

int main(int args, char *argv[])
{
	struct stat buf;
	int s = stat(argv[1], &buf);
	if(s == -1)
	{
		perror("error tips :");
		return -1;
	}

	//获取文件的类型
	switch(buf.st_mode & S_IFMT)
	{
		case S_IFDIR:
			printf("d");
		case S_IFREG:
			printf("-");
		default:
			break;
	
	}

	//获得并权限
	//printf("mode :%o\n", buf.st_mode);//八进制输出
	/*用户权限*/
	((buf.st_mode& S_IRWXU)& S_IRUSR)?printf("r"):printf("-");
	((buf.st_mode& S_IRWXU)& S_IWUSR)?printf("w"):printf("-");
	((buf.st_mode& S_IRWXU)& S_IXUSR)?printf("x"):printf("-");
	/*组权限*/
	((buf.st_mode& S_IRWXG)& S_IRGRP)?printf("r"):printf("-");
	((buf.st_mode& S_IRWXG)& S_IWGRP)?printf("w"):printf("-");
	((buf.st_mode& S_IRWXG)& S_IXGRP)?printf("x"):printf("-");
	/*其他人权限*/
	((buf.st_mode& S_IRWXO)& S_IROTH)?printf("r"):printf("-");
	((buf.st_mode& S_IRWXO)& S_IWOTH)?printf("w"):printf("-");
	((buf.st_mode& S_IRWXO)& S_IXOTH)?printf("x"):printf("-");
	
	
	//gcc -E stat.c  vi stat.i 看数据成员的数据类型
	//printf("inode number :%lu\n", buf.st_ino);
	printf(" %lu", buf.st_nlink);
	
	//获取uid
	//printf("user id :%u\n", buf.st_uid);
	
#if 0	//获取用户名
	struct getpasswd *pw = (struct getpasswd*)getpwuid(buf.st_uid);
	if(NULL == pw)
	{
		perror("error tips:");
		return -1;
	}
	printf("user name :%s\n", pw->pw_name); //???*/
#endif
	printf(" %s", (getpwuid(buf.st_uid))->pw_name);
	
	//获取组名
	printf(" %s", (getgrgid(buf.st_gid))->gr_name);
	
	//获取文件大小
	printf(" %ld", buf.st_size);
	
	//获取最后修改文件的时间
	//printf("last modify :%ld\n", buf.st_mtime);	
	char *time = ctime(&(buf.st_mtime));
	printf(" %s", time);

	return 0;
}
