#ifndef HAIR_H
#define HAIR_H
#include"definition.h"


void add_person(Staff staff[MAX_PEOPLE],Customer customer[MAX_PEOPLE],int *staff_num,int *customer_num);
void read_person(Staff staff[MAX_PEOPLE],Customer customer[MAX_PEOPLE],int *staff_num,int *customer_num);
void show_person(Staff staff[MAX_PEOPLE],Customer customer[MAX_PEOPLE],int staff_num,int customer_num);
void statistic_person(Staff staff[MAX_PEOPLE],Customer customer[MAX_PEOPLE],int staff_num,int customer_num);
void find_person(Staff staff[MAX_PEOPLE],Customer customer[MAX_PEOPLE],int staff_num,int customer_num);
void hair_person(Staff staff[MAX_PEOPLE],Customer customer[MAX_PEOPLE],int staff_num,int customer_num);
void remove_person(Staff staff[MAX_PEOPLE],Customer customer[MAX_PEOPLE],int* staff_num,int *customer_num);

#endif
