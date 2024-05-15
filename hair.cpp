#include<stdio.h>
#include <string.h>
#include"definition.h"

const char* getsex(enum Sex sex){
	switch (sex) {
	case boy:
		return "boy";
	case girl:
		return "girl";
	default:
		return "what can i say";
	}
}

const char* getproject(enum hair_project project){
	switch (project) {
	case haircut:
		return "haircut";
	case perm:
		return "perm";
	case hairdressing:
		return"hairdressing";
	default:
		return "what can i say";
	}
}


void add_person(Staff staff[MAX_PEOPLE],Customer customer[MAX_PEOPLE],int *staff_num,int *customer_num){
	int in_num;
	Staff in_staff;
	Customer in_customer;
	printf("请选择\n1、添加员工\n2、添加顾客\n");
	while(1){
		scanf("%d",&in_num);
		if(in_num==1){
			printf("请输入员工编号：");
			while(1){
				int i;
				scanf("%d",&in_staff.work_num);
				for(i=0;i<*staff_num;i++){
					if(in_staff.work_num==staff[i].work_num){
						printf("----------------------------------------\n已存在该编号！请重新输入!\n----------------------------------------\n");
						break;
					}
				}
				if(i==*staff_num){
					printf("编号录入成功！\n");
					break;
				}
			}
			
			printf("请输入员工姓名(例：张三)：");
			scanf("%s",&in_staff.name);
			printf("姓名录入成功！\n");
			
			printf("请输入员工年龄(例：28)：");
			scanf("%d",&in_staff.age);
			printf("年龄录入成功！\n");
			
			printf("请输入员工性别(1代表男，2代表女，例：1)：");
			while(1){
				scanf("%d",&in_staff.sex);
				if(in_staff.sex!=1&&in_staff.sex!=2)
				printf("----------------------------------------\n超出范围！请重新输入!\n----------------------------------------\n");
				else
					break;
			}
			printf("性别录入成功！\n");
			
			printf("请输入员工电话（例：10086）：");
			scanf("%d",&in_staff.phonenum);
			printf("电话录入成功！\n");
			
			printf("请输入该员工能从事的工作(仅一项，1代表剪发，2代表烫发，3代表洗发，例：2):");
			while(1){
				scanf("%d",&in_staff.project);
				if(in_staff.project!=1&&in_staff.project!=2&&in_staff.project!=3)
					printf("----------------------------------------\n超出范围！请重新输入!\n----------------------------------------\n");
				else
					break;
			}
			printf("相关从事录入成功！即将返回主菜单！\n");
			printf("----------------------------------------------\n");
			
			FILE *file1 = fopen("staff.txt", "a");
			fprintf(file1, "%d\n", in_staff.work_num);
			fprintf(file1, "%s\n", in_staff.name);
			fprintf(file1, "%d\n", in_staff.age);
			fprintf(file1, "%d\n", in_staff.sex);
			fprintf(file1, "%d\n", in_staff.phonenum);
			fprintf(file1, "%d\n", in_staff.project);
			*staff_num=*staff_num+1;
			fclose(file1);
			
			break;
		}
		else if(in_num==2){
			printf("请输入顾客会员号：");
			while(1){
				int i;
				scanf("%d",&in_customer.vip_num);
				for(i=0;i<*customer_num;i++){
					if(in_customer.vip_num==customer[i].vip_num){
						printf("----------------------------------------\n已存在该会员！请重新输入!\n----------------------------------------\n");
						break;
					}
				}
				if(i==*customer_num){
					printf("会员编号录入成功！\n");
					break;
				}
			}
			
			printf("请输入会员姓名(例：张三)：");
			scanf("%s",&in_customer.name);
			printf("姓名录入成功！\n");
			
			printf("请输入会员年龄(例：28)：");
			scanf("%d",&in_customer.age);
			printf("年龄录入成功！\n");
			
			printf("请输入会员性别(1代表男，2代表女)(例：1)：");
			while(1){
				scanf("%d",&in_customer.sex);
				if(in_customer.sex!=1&&in_customer.sex!=2)
					printf("----------------------------------------\n超出范围！请重新输入!\n----------------------------------------\n");
				else
					break;
			}
			printf("性别录入成功！\n");
			
			printf("请输入会员电话（例：10086）：");
			scanf("%d",&in_customer.phonenum);
			printf("电话录入成功！\n");
			
			printf("请输入会员充值金额(例：268)：");
			scanf("%d",&in_customer.left_money);
			printf("充值成功！即将返回主菜单！\n");
			printf("----------------------------------------------\n");
			
			in_customer.use_money=0;
			
			FILE *file2 = fopen("customer.txt", "a");
			fprintf(file2, "%d\n", in_customer.vip_num);
			fprintf(file2, "%s\n", in_customer.name);
			fprintf(file2, "%d\n", in_customer.age);
			fprintf(file2, "%d\n", in_customer.sex);
			fprintf(file2, "%d\n", in_customer.phonenum);
			fprintf(file2, "%d\n", in_customer.left_money);
			fprintf(file2, "%d\n", in_customer.use_money);
			*customer_num=*customer_num+1;
			fclose(file2);
			
			break;
		}
		else{
			printf("----------------------------------------\n警告：输入无效！请重新输入！\n----------------------------------------\n");
		}
	}
}

void read_person(Staff staff[MAX_PEOPLE],Customer customer[MAX_PEOPLE],int *staff_num,int *customer_num){
	char buffer[100];
	int i=1,j=0;
	FILE *file1 = fopen("staff.txt", "r");
	while (fgets(buffer, sizeof(buffer), file1) != NULL) {
		// 移除末尾的换行符
		size_t len = strlen(buffer);
		if (len > 0 && buffer[len-1] == '\n') {
			buffer[len-1] = '\0';
		}

		if(i%6==1)
			sscanf(buffer, "%d", &staff[j].work_num);
		else if(i%6==2)
			strcpy(staff[j].name, buffer);
		else if(i%6==3)
			sscanf(buffer, "%d", &staff[j].age);
		else if(i%6==4)
			sscanf(buffer, "%d", &staff[j].sex);
		else if(i%6==5)
			sscanf(buffer, "%d", &staff[j].phonenum);
		else if(i%6==0){
			sscanf(buffer, "%d", &staff[j].project);
			*staff_num=*staff_num+1;
		}
		j=i/6;
		i++;
	}
	fclose(file1);
	
	i=1,j=0;
	FILE *file2 = fopen("customer.txt", "r");
	while (fgets(buffer, sizeof(buffer), file2) != NULL) {
		// 移除末尾的换行符
		size_t len = strlen(buffer);
		if (len > 0 && buffer[len-1] == '\n') {
			buffer[len-1] = '\0';
		}
		if(i%7==1)
			sscanf(buffer, "%d", &customer[j].vip_num);
		else if(i%7==2)
			strcpy(customer[j].name, buffer);
		else if(i%7==3)
			sscanf(buffer, "%d", &customer[j].age);
		else if(i%7==4)
			sscanf(buffer, "%d", &customer[j].sex);
		else if(i%7==5)
			sscanf(buffer, "%d", &customer[j].phonenum);
		else if(i%7==6)
			sscanf(buffer, "%d", &customer[j].left_money);
		else if(i%7==0){
			sscanf(buffer, "%d", &customer[j].use_money);
			*customer_num=*customer_num+1;
		}
		j=i/7;
		i++;
	}
	fclose(file2);
}

void show_person(Staff staff[MAX_PEOPLE],Customer customer[MAX_PEOPLE],int staff_num,int customer_num){
	printf("--------------------------------------------\n以下数据均为随机排列，如有需要请移步相关统计\n--------------------------------------------\n");
	printf("以下为员工相关数据\n");
	printf("员工编号       姓名           年龄           性别           电话号         从事项目 \n");
	int i;
	for(i=0;i<staff_num;i++){
		printf("%-15d",staff[i].work_num);
		printf("%-15s",staff[i].name);
		printf("%-15d",staff[i].age);
		printf("%-15s",getsex(staff[i].sex));
		printf("%-15d",staff[i].phonenum);
		printf("%-15s\n",getproject(staff[i].project));
	}
	printf("--------------------------------------------\n以下为顾客相关数据\n");
	printf("会员号          姓名           年龄           性别           电话号         卡中余额       总消费金额\n");
	for(i=0;i<customer_num;i++){
		printf("%-15d",customer[i].vip_num);
		printf("%-15s",customer[i].name);
		printf("%-15d",customer[i].age);
		printf("%-15s",getsex(customer[i].sex));
		printf("%-15d",customer[i].phonenum);
		printf("%-15d",customer[i].left_money);
		printf("%-15d\n",customer[i].use_money);
	}
	printf("--------------------------------------------\n");
}

void statistic_person(Staff staff[MAX_PEOPLE],Customer customer[MAX_PEOPLE],int staff_num,int customer_num){
	int chose;
	Staff temp_staff[staff_num],temp_staff1;
	Customer temp_customer[customer_num],temp_customer1;
	
	//复制到temp中防止改变原序列
	for(int i=0;i<staff_num;i++){
		temp_staff[i]=staff[i];
	}
	for(int i=0;i<customer_num;i++){
		temp_customer[i]=customer[i];
	}
	
	printf("--------------------------------------\n欢迎来到统计功能！\n请选择：\n1、查看相关排序展示\n2、查看统计\n");
	while(1){
		scanf("%d",&chose);
		if(chose!=1&&chose!=2){
			printf("----------------------------------------\n警告:超出选择范围！请重新输入!\n----------------------------------------\n");
		}
		else
			break;
	}
	if(chose==1){
		printf("请选择\n1、查看员工排序\n2、查看顾客排序\n");
		while(1){
			scanf("%d",&chose);
			if(chose!=1&&chose!=2){
				printf("----------------------------------------\n警告:超出选择范围！请重新输入!\n----------------------------------------\n");
			}
			else
				break;
		}
		if(chose==1){
			printf("请选择\n1、按年龄大小排序\n2、按编号大小排序\n");
			while(1){
				scanf("%d",&chose);
				if(chose!=1&&chose!=2){
					printf("----------------------------------------\n警告:超出选择范围！请重新输入!\n----------------------------------------\n");
				}
				else
					break;
			}
			if(chose==1){
				int i,j,temp;
				for(i=0;i<staff_num-1;i++){
					for(j=0;j<staff_num-i-1;j++){
						if(temp_staff[j].age>temp_staff[j+1].age){
							temp_staff1=temp_staff[j];
							temp_staff[j]=temp_staff[j+1];
							temp_staff[j+1]=temp_staff1;
						}	
					}
				}
				printf("----------------------------------------\n");
				printf("员工编号       姓名           年龄           性别           电话号         从事项目 \n");
				for(i=0;i<staff_num;i++){
					printf("%-15d",temp_staff[i].work_num);
					printf("%-15s",temp_staff[i].name);
					printf("%-15d",temp_staff[i].age);
					printf("%-15s",getsex(temp_staff[i].sex));
					printf("%-15d",temp_staff[i].phonenum);
					printf("%-15s\n",getproject(temp_staff[i].project));
				}
				printf("--------------------------------------------\n");
				
			}
			else if(chose==2){
				int i,j,temp;
				for(i=0;i<staff_num-1;i++){
					for(j=0;j<staff_num-i-1;j++){
						if(temp_staff[j].work_num>temp_staff[j+1].work_num){
							temp_staff1=temp_staff[j];
							temp_staff[j]=temp_staff[j+1];
							temp_staff[j+1]=temp_staff1;
						}	
					}
				}
				printf("----------------------------------------\n");
				printf("员工编号       姓名           年龄           性别           电话号         从事项目 \n");
				for(i=0;i<staff_num;i++){
					printf("%-15d",temp_staff[i].work_num);
					printf("%-15s",temp_staff[i].name);
					printf("%-15d",temp_staff[i].age);
					printf("%-15s",getsex(temp_staff[i].sex));
					printf("%-15d",temp_staff[i].phonenum);
					printf("%-15s\n",getproject(temp_staff[i].project));
				}
				printf("--------------------------------------------\n");
			}
		}
		else if(chose==2){
			printf("请选择\n1、按年龄大小排序\n2、按编卡中余额排序\n3、按消费总额排序\n");
			while(1){
				scanf("%d",&chose);
				if(chose!=1&&chose!=2&&chose!=3){
					printf("----------------------------------------\n警告:超出选择范围！请重新输入!\n----------------------------------------\n");
				}
				else
					break;
			}
			if(chose==1){
				int i,j,temp;
				for(i=0;i<customer_num-1;i++){
					for(j=0;j<customer_num-i-1;j++){
						if(temp_customer[j].age>temp_customer[j+1].age){
							temp_customer1=temp_customer[j];
							temp_customer[j]=temp_customer[j+1];
							temp_customer[j+1]=temp_customer1;
						}	
					}
				}
				printf("--------------------------------------------\n");
				printf("会员号          姓名           年龄           性别           电话号         卡中余额       总消费金额\n");
				for(i=0;i<customer_num;i++){
					printf("%-15d",temp_customer[i].vip_num);
					printf("%-15s",temp_customer[i].name);
					printf("%-15d",temp_customer[i].age);
					printf("%-15s",getsex(temp_customer[i].sex));
					printf("%-15d",temp_customer[i].phonenum);
					printf("%-15d",temp_customer[i].left_money);
					printf("%-15d\n",temp_customer[i].use_money);
				}
				printf("--------------------------------------------\n");
			}
			if(chose==2){
				int i,j,temp;
				for(i=0;i<customer_num-1;i++){
					for(j=0;j<customer_num-i-1;j++){
						if(temp_customer[j].left_money>temp_customer[j+1].left_money){
							temp_customer1=temp_customer[j];
							temp_customer[j]=temp_customer[j+1];
							temp_customer[j+1]=temp_customer1;
						}	
					}
				}
				printf("--------------------------------------------\n");
				printf("会员号          姓名           年龄           性别           电话号         卡中余额       总消费金额\n");
				for(i=0;i<customer_num;i++){
					printf("%-15d",temp_customer[i].vip_num);
					printf("%-15s",temp_customer[i].name);
					printf("%-15d",temp_customer[i].age);
					printf("%-15s",getsex(temp_customer[i].sex));
					printf("%-15d",temp_customer[i].phonenum);
					printf("%-15d",temp_customer[i].left_money);
					printf("%-15d\n",temp_customer[i].use_money);
				}
				printf("--------------------------------------------\n");
			}
			if(chose==3){
				int i,j,temp;
				for(i=0;i<customer_num-1;i++){
					for(j=0;j<customer_num-i-1;j++){
						if(temp_customer[j].use_money>temp_customer[j+1].use_money){
							temp_customer1=temp_customer[j];
							temp_customer[j]=temp_customer[j+1];
							temp_customer[j+1]=temp_customer1;
						}	
					}
				}
				printf("--------------------------------------------\n");
				printf("会员号          姓名           年龄           性别           电话号         卡中余额       总消费金额\n");
				for(i=0;i<customer_num;i++){
					printf("%-15d",temp_customer[i].vip_num);
					printf("%-15s",temp_customer[i].name);
					printf("%-15d",temp_customer[i].age);
					printf("%-15s",getsex(temp_customer[i].sex));
					printf("%-15d",temp_customer[i].phonenum);
					printf("%-15d",temp_customer[i].left_money);
					printf("%-15d\n",temp_customer[i].use_money);
				}
				printf("--------------------------------------------\n");
			}
		}
		
	}
	else if(chose==2){
		printf("----------------------------------------\n以下为性别统计\n");
		int boystaff_num=0,boycustomer_num=0,i,all_usemoney=0,all_leftmoney=0;
		for(i=0;i<staff_num;i++){
			if(staff[i].sex==1)
				boystaff_num++;
		}
		printf("男员工：%d人      女员工：%d人\n",boystaff_num,(staff_num-boystaff_num));
		for(i=0;i<customer_num;i++){
			if(customer[i].sex==1)
				boycustomer_num++;
		}
		printf("男顾客：%d人      女顾客：%d人\n",boycustomer_num,(customer_num-boycustomer_num));
		
		printf("----------------------------------------\n以下为顾客消费统计\n");
		for(i=0;i<customer_num;i++){
			all_leftmoney+=customer[i].left_money;
			all_usemoney+=customer[i].use_money;
		}
		printf("所有顾客总消费：%d元        所有顾客卡中总余额：%d元\n",all_usemoney,all_leftmoney);
		printf("----------------------------------------\n");
	}
}

void find_person(Staff staff[MAX_PEOPLE],Customer customer[MAX_PEOPLE],int staff_num,int customer_num){
	int chose;
	printf("请选择你要查询的对象\n1、员工\n2、顾客\n");
	while(1){
		scanf("%d",&chose);
		if(chose!=1&&chose!=2){
			printf("----------------------------------------\n警告:超出选择范围！请重新输入!\n----------------------------------------\n");
		}
		else
			break;
	}
	if(chose==1){
		int staffworknum,i;
		printf("请输入员工编号：");
		scanf("%d",&staffworknum);
		for( i=0;i<staff_num;i++){
			if(staff[i].work_num==staffworknum){
				printf("存在该员工\n----------------------------------------\n");
				printf("员工编号       姓名           年龄           性别           电话号         从事项目 \n");
				printf("%-15d",staff[i].work_num);
				printf("%-15s",staff[i].name);
				printf("%-15d",staff[i].age);
				printf("%-15s",getsex(staff[i].sex));
				printf("%-15d",staff[i].phonenum);
				printf("%-15s\n",getproject(staff[i].project));
				printf("----------------------------------------\n");
				break;
			}
		}
		if(i==staff_num){
			printf("不存在该员工！\n");
			printf("----------------------------------------\n");
		}
	}
	if(chose==2){
		int customervipnum,i;
		printf("请输入顾客卡号：");
		scanf("%d",&customervipnum);
		for(i=0;i<customer_num;i++){
			if(customer[i].vip_num==customervipnum){
				printf("存在该顾客！\n----------------------------------------\n");
				printf("会员号          姓名           年龄           性别           电话号         卡中余额       总消费金额\n ");
				printf("%-15d",customer[i].vip_num);
				printf("%-15s",customer[i].name);
				printf("%-15d",customer[i].age);
				printf("%-15s",getsex(customer[i].sex));
				printf("%-15d",customer[i].phonenum);
				printf("%-15d",customer[i].left_money);
				printf("%-15d\n",customer[i].use_money);
				printf("----------------------------------------\n");
				break;	
			}
		}
		if(i==customer_num){
			printf("不存在该顾客！\n");
			printf("----------------------------------------\n");
		}
	}
	
}

void hair_person(Staff staff[MAX_PEOPLE],Customer customer[MAX_PEOPLE],int staff_num,int customer_num){
	int customervipnum,staffworknum,i,chose;
	if(customer_num==0){
		printf("目前还没有顾客！无法进行美发！\n----------------------------------------\n");
		return;
	}
	if(staff_num==0){
		printf("目前还没有员工！无法进行美发！\n----------------------------------------\n");
		return;
	}
	printf("----------------------------------------\n");
	printf("会员号          姓名           年龄           性别           电话号         卡中余额       总消费金额\n");
	for(i=0;i<customer_num;i++){
		printf("%-15d",customer[i].vip_num);
		printf("%-15s",customer[i].name);
		printf("%-15d",customer[i].age);
		printf("%-15s",getsex(customer[i].sex));
		printf("%-15d",customer[i].phonenum);
		printf("%-15d",customer[i].left_money);
		printf("%-15d\n",customer[i].use_money);
	}
	printf("----------------------------------------\n");
	while(1){
		printf("请选择要美发的顾客（输入顾客会员号）：");
		scanf("%d",&customervipnum);
		for(i=0;i<customer_num;i++){
			if(customer[i].vip_num==customervipnum){
				printf("存在该顾客！\n");
				break;
			}
		}
		if(customer[i].vip_num==customervipnum)
			break;
		if(i==customer_num){
			printf("不存在该顾客！请重新输入！\n");
		}
	}
	printf("请选择要进行的美发项目\n1、剪发(99元)\n2、烫发（999元）\n3、洗发（9元）\n");
	while(1){
		scanf("%d",&chose);
		if(chose!=1&&chose!=2&&chose!=3){
			printf("----------------------------------------\n警告:超出选择范围！请重新输入!\n----------------------------------------\n");
		}
		else
			break;
	}
	if(chose==1){
		if(customer[i].left_money<99)
			printf("该顾客卡中余额不足！无法剪发！\n----------------------------------------\n");
		else{
			printf("以下为可从事该项目的员工:\n");
			printf("员工编号       姓名           年龄           性别           电话号         从事项目 \n");
			int j,cando_num=0;
			for(j=0;j<staff_num;j++){
				if(staff[j].project==1){
					printf("%-15d",staff[j].work_num);
					printf("%-15s",staff[j].name);
					printf("%-15d",staff[j].age);
					printf("%-15s",getsex(staff[j].sex));
					printf("%-15d",staff[j].phonenum);
					printf("%-15s\n",getproject(staff[j].project));
					cando_num++;
				}
			}
			if(cando_num==0){
				printf("没有能从事该项目的员工！即将返回！\n");
				return;
			}
			printf("----------------------------------------\n");
			while(1){
				printf("请选择执行员工（输入员工编号）：");
				scanf("%d",&staffworknum);
				for(j=0;j<cando_num;j++){
					if(staff[j].work_num==staffworknum){
						printf("存在该员工！\n");
						break;
					}
				}
				if(staff[j].work_num==staffworknum)
					break;
				if(j==cando_num){
					printf("不存在该员工！请重新输入！\n");
				}
			}
			customer[i].left_money-=99;
			customer[i].use_money+=99;
			printf("剪发完成！\n");
			printf("----------------------------------------\n");
			printf("会员号          姓名           年龄           性别           电话号         卡中余额       总消费金额\n");
			printf("%-15d",customer[i].vip_num);
			printf("%-15s",customer[i].name);
			printf("%-15d",customer[i].age);
			printf("%-15s",getsex(customer[i].sex));
			printf("%-15d",customer[i].phonenum);
			printf("%-15d",customer[i].left_money);
			printf("%-15d\n",customer[i].use_money);
			printf("----------------------------------------\n");
			FILE *file2 = fopen("customer.txt", "w");//直接写入覆盖
			for(j=0;j<customer_num;j++){
				fprintf(file2, "%d\n", customer[j].vip_num);
				fprintf(file2, "%s\n", customer[j].name);
				fprintf(file2, "%d\n", customer[j].age);
				fprintf(file2, "%d\n", customer[j].sex);
				fprintf(file2, "%d\n", customer[j].phonenum);
				fprintf(file2, "%d\n", customer[j].left_money);
				fprintf(file2, "%d\n", customer[j].use_money);
			}
			fclose(file2);
		}
	}
	else if(chose==2){
		if(customer[i].left_money<999)
			printf("该顾客卡中余额不足！无法烫发！\n----------------------------------------\n");
		else{
			printf("以下为可从事该项目的员工:\n");
			printf("员工编号       姓名           年龄           性别           电话号         从事项目 \n");
			int j,cando_num=0;
			for(j=0;j<staff_num;j++){
				if(staff[j].project==2){
					printf("%-15d",staff[j].work_num);
					printf("%-15s",staff[j].name);
					printf("%-15d",staff[j].age);
					printf("%-15s",getsex(staff[j].sex));
					printf("%-15d",staff[j].phonenum);
					printf("%-15s\n",getproject(staff[j].project));
					cando_num++;
				}
			}
			if(cando_num==0){
				printf("没有能从事该项目的员工！即将返回！\n");
				return;
			}
			printf("----------------------------------------\n");
			while(1){
				printf("请选择执行员工（输入员工编号）：");
				scanf("%d",&staffworknum);
				for(j=0;j<cando_num;j++){
					if(staff[j].work_num==staffworknum){
						printf("存在该员工！\n");
						break;
					}
				}
				if(staff[j].work_num==staffworknum)
					break;
				if(j==cando_num){
					printf("不存在该员工！请重新输入！\n");
				}
			}
			customer[i].left_money-=999;
			customer[i].use_money+=999;
			printf("烫发完成！\n");
			printf("----------------------------------------\n");
			printf("会员号          姓名           年龄           性别           电话号         卡中余额       总消费金额\n");
			printf("%-15d",customer[i].vip_num);
			printf("%-15s",customer[i].name);
			printf("%-15d",customer[i].age);
			printf("%-15s",getsex(customer[i].sex));
			printf("%-15d",customer[i].phonenum);
			printf("%-15d",customer[i].left_money);
			printf("%-15d\n",customer[i].use_money);
			printf("----------------------------------------\n");
			FILE *file2 = fopen("customer.txt", "w");//直接写入覆盖
			for(j=0;j<customer_num;j++){
				fprintf(file2, "%d\n", customer[j].vip_num);
				fprintf(file2, "%s\n", customer[j].name);
				fprintf(file2, "%d\n", customer[j].age);
				fprintf(file2, "%d\n", customer[j].sex);
				fprintf(file2, "%d\n", customer[j].phonenum);
				fprintf(file2, "%d\n", customer[j].left_money);
				fprintf(file2, "%d\n", customer[j].use_money);
			}
			fclose(file2);
		}
	}
	else if(chose==3){
		if(customer[i].left_money<9)
			printf("该顾客卡中余额不足！无法洗发！\n----------------------------------------\n");
		else{
			printf("以下为可从事该项目的员工:\n");
			printf("员工编号       姓名           年龄           性别           电话号         从事项目 \n");
			int j,cando_num=0;
			for(j=0;j<staff_num;j++){
				if(staff[j].project==3){
					printf("%-15d",staff[j].work_num);
					printf("%-15s",staff[j].name);
					printf("%-15d",staff[j].age);
					printf("%-15s",getsex(staff[j].sex));
					printf("%-15d",staff[j].phonenum);
					printf("%-15s\n",getproject(staff[j].project));
					cando_num++;
				}
			}
			if(cando_num==0){
				printf("没有能从事该项目的员工！即将返回！\n");
				return;
			}
			printf("----------------------------------------\n");
			while(1){
				printf("请选择执行员工（输入员工编号）：");
				scanf("%d",&staffworknum);
				for(j=0;j<cando_num;j++){
					if(staff[j].work_num==staffworknum){
						printf("存在该员工！\n");
						break;
					}
				}
				if(staff[j].work_num==staffworknum)
					break;
				if(j==cando_num){
					printf("不存在该员工！请重新输入！\n");
				}
			}
			customer[i].left_money-=9;
			customer[i].use_money+=9;
			printf("烫发完成！\n");
			printf("----------------------------------------\n");
			printf("会员号          姓名           年龄           性别           电话号         卡中余额       总消费金额\n");
			printf("%-15d",customer[i].vip_num);
			printf("%-15s",customer[i].name);
			printf("%-15d",customer[i].age);
			printf("%-15s",getsex(customer[i].sex));
			printf("%-15d",customer[i].phonenum);
			printf("%-15d",customer[i].left_money);
			printf("%-15d\n",customer[i].use_money);
			printf("----------------------------------------\n");
			FILE *file2 = fopen("customer.txt", "w");//直接写入覆盖
			for(j=0;j<customer_num;j++){
				fprintf(file2, "%d\n", customer[j].vip_num);
				fprintf(file2, "%s\n", customer[j].name);
				fprintf(file2, "%d\n", customer[j].age);
				fprintf(file2, "%d\n", customer[j].sex);
				fprintf(file2, "%d\n", customer[j].phonenum);
				fprintf(file2, "%d\n", customer[j].left_money);
				fprintf(file2, "%d\n", customer[j].use_money);
			}
			fclose(file2);
		}
		
	}
}

void remove_person(Staff staff[MAX_PEOPLE],Customer customer[MAX_PEOPLE],int *staff_num,int *customer_num){
	char chose[100];
	int customervipnum,staffworknum,i,j;
	Staff temp_staff[MAX_PEOPLE];
	Customer temp_customer[MAX_PEOPLE];
	printf("请选择你要删除的对象\n1、员工\n2、顾客\n");
	while(1){
		scanf("%s",chose);
		if(strcmp(chose,"1")!=0&&strcmp(chose,"2")!=0){
			printf("----------------------------------------\n警告:超出选择范围！请重新输入!\n----------------------------------------\n");
		}
		else
			break;
	}
	if(strcmp(chose,"1")==0){
		if(*staff_num==0){
			printf("目前还没有员工！无法进行删除操作！\n----------------------------------------\n");
			return;
		}
		printf("--------------------------------------------\n");
		printf("员工编号       姓名           年龄           性别           电话号         从事项目 \n");
		for(i=0;i<*staff_num;i++){
			printf("%-15d",staff[i].work_num);
			printf("%-15s",staff[i].name);
			printf("%-15d",staff[i].age);
			printf("%-15s",getsex(staff[i].sex));
			printf("%-15d",staff[i].phonenum);
			printf("%-15s\n",getproject(staff[i].project));
		}
		printf("--------------------------------------------\n");
		while(1){
			printf("请选择要删除的员工（输入员工编号）：");
			scanf("%d",&staffworknum);
			for(i=0;i<*staff_num;i++){
				if(staff[i].work_num==staffworknum){
					printf("存在该员工！\n");
					break;
				}
			}
			if(staff[i].work_num==staffworknum)
				break;
			if(i==*staff_num){
				printf("不存在该员工！请重新输入！\n");
			}
		}
		for(j=0;j<i;j++)
			temp_staff[j]=staff[j];
		for(j+=6;j<*staff_num;j++)
			temp_staff[j-6]=staff[j];
		*staff_num=*staff_num-1;
		FILE *file1 = fopen("staff.txt", "w");//直接写入覆盖
		for(j=0;j<*staff_num;j++){
		fprintf(file1, "%d\n", temp_staff[j].work_num);
		fprintf(file1, "%s\n", temp_staff[j].name);
		fprintf(file1, "%d\n", temp_staff[j].age);
		fprintf(file1, "%d\n", temp_staff[j].sex);
		fprintf(file1, "%d\n", temp_staff[j].phonenum);
		fprintf(file1, "%d\n", temp_staff[j].project);
		}
		fclose(file1);
		printf("删除成功！\n");
		printf("----------------------------------------\n");
	}
	else if(strcmp(chose,"2")==0){
		if(*customer_num==0){
			printf("目前还没有顾客！无法进行删除操作！\n----------------------------------------\n");
			return;
		}
		printf("----------------------------------------\n");
		printf("会员号          姓名           年龄           性别           电话号         卡中余额       总消费金额\n");
		for(i=0;i<*customer_num;i++){
			printf("%-15d",customer[i].vip_num);
			printf("%-15s",customer[i].name);
			printf("%-15d",customer[i].age);
			printf("%-15s",getsex(customer[i].sex));
			printf("%-15d",customer[i].phonenum);
			printf("%-15d",customer[i].left_money);
			printf("%-15d\n",customer[i].use_money);
		}
		printf("----------------------------------------\n");
		while(1){
			printf("请选择要删除的顾客（输入会员号）：");
			scanf("%d",&customervipnum);
			for(i=0;i<*customer_num;i++){
				if(customer[i].vip_num==customervipnum){
					printf("存在该顾客！\n");
					break;
				}
			}
			if(customer[i].vip_num==customervipnum)
				break;
			if(i==*customer_num){
				printf("不存在该顾客！请重新输入！\n");
			}
		}
		for(j=0;j<i;j++)
			temp_customer[j]=customer[j];
		for(j+=7;j<*customer_num;j++)
			temp_customer[j-7]=customer[j];
		*customer_num=*customer_num-1;
		FILE *file2 = fopen("customer.txt", "w");//直接写入覆盖
		for(j=0;j<*customer_num;j++){
			fprintf(file2, "%d\n", temp_customer[j].vip_num);
			fprintf(file2, "%s\n", temp_customer[j].name);
			fprintf(file2, "%d\n", temp_customer[j].age);
			fprintf(file2, "%d\n", temp_customer[j].sex);
			fprintf(file2, "%d\n", temp_customer[j].phonenum);
			fprintf(file2, "%d\n", temp_customer[j].left_money);
			fprintf(file2, "%d\n", temp_customer[j].use_money);
		}
		fclose(file2);
		printf("删除成功！\n");
		printf("----------------------------------------\n");
	}
}
