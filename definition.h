#ifndef DEFINITION_H
#define DEFINITION_H
#define MAX_PEOPLE  (300)//最大储存人数
enum Sex{
	boy=1,girl
};
enum hair_project{
	haircut=1,perm,hairdressing
};
struct Staff{
	int work_num;
	char name[100];
	int age;
	enum Sex sex;
	int phonenum;
	enum hair_project project;
};
struct Customer{
	int vip_num;
	char name[100];
	int age;
	enum Sex sex;
	int phonenum;
	int left_money;
	int use_money;
};

#endif
