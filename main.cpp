#include<stdio.h>
#include <string.h>
#include"hair.h"
#include"definition.h"

//员工存储顺序为：编号，姓名，年龄，性别，电话，能处理的美发项目
//顾客储存顺序为：vip卡号，姓名，年龄，性别，电话，卡中余额，已消费总额
Staff staff[MAX_PEOPLE];
Customer customer[MAX_PEOPLE];
int staff_num=0,customer_num=0;
char in_num[100];
int main(){
	printf("欢迎来到比奇堡别动队美发店！\n---------------------------------------------\n");
	printf("警告：请输入相关整数进行选择！\n---------------------------------------------\n");
	while(1){
		staff_num=0,customer_num=0;
		read_person(staff,customer,&staff_num,&customer_num);//读取储存文件信息
		printf("请选择功能\n1、添加成员信息\n2、显示成员相关信息\n3、显示相关统计\n4、查询相关成员信息\n5、进行美发功能\n6、删除人员\n7、退出系统\n");
		scanf("%s",in_num);
		if(strcmp(in_num,"1")==0)
			add_person(staff,customer,&staff_num,&customer_num);
		
		else if(strcmp(in_num,"2")==0)
			show_person(staff,customer,staff_num,customer_num);

		else if(strcmp(in_num,"3")==0)
			statistic_person(staff,customer,staff_num,customer_num);

		else if(strcmp(in_num,"4")==0)
			find_person(staff,customer,staff_num,customer_num);

		else if(strcmp(in_num,"5")==0)
			hair_person(staff,customer,staff_num,customer_num);
		
		else if(strcmp(in_num,"6")==0)
			remove_person(staff,customer,&staff_num,&customer_num);

		else if(strcmp(in_num,"7")==0)
			break;
		
		else
			printf("----------------------------------------\n警告：输入无效！请重新输入！\n----------------------------------------\n");
		
		
	}
	
	return 0;
}
