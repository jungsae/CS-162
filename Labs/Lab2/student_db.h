#ifndef STUDENT_DB_H
#define STUDENT_DB_H

#include <fstream>
#include <string> 

struct student
{
   int id_number;
   std::string name;
   std::string major;
};

student* create_student_db(int); 
void get_student_db_info(student*, int, std::fstream&); 
void swap(int*, int*);
void bubbleSort(int* , int );
void sort_by_id(student*, int);
void sort_by_lastName(student*, int);
void delete_student_db_info(student *);

#endif