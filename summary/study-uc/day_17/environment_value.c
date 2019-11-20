//环境变量是与进程紧密绑定在一起的
//以bash进程的环境变量为列子

//env 看
//USER=tarena
//name=value
//=两边不能有空格
//
//$USER gain value

//自定义变量变成环境变量
//export name(name是自定义变量)
//env|grep name    find name

//bash下两个特殊的环境变量
// PS1    指定bash的提示符(root@MyUbuntu:/home/jason/uc_study/day_17# 是提示符)
//PS1='\W\$'  提示符就只会出现一个(day_17# )
//bash 启动会执行bash脚本程序 ~/.bashrc (~是当前用户的主目录)
//
// PATH
//
int main(void)
{
	//TODO
	int a = 333, b = 333, c = 0;
	c = a + b;
	return 0;
}


