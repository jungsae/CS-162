#include <fstream>
#include <string>
#include "student_db.h"

student* create_student_db(int n)
{
    student* students_db = new student [n];
    return students_db;
};

void get_student_db_info(student *student_db, int n, std::fstream &fin)
{
    for (int i = 0; i < n; i++)
    {
        fin >> student_db[i].id_number;
        fin >> student_db[i].name;
    }
    
} 

void delete_student_db_info(student *studnet_db)
{   
    delete [] studnet_db;
    studnet_db = NULL;
}

void sort_by_id(student *student_db, int n)
{
    for (int i = 0; i < n; i++)
    {
        
    }
    
}

void sort_by_lastName(student *student_db, int n)
{
    //Not yet
}

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
 
void bubbleSort(int arr[], int n) 
{ 
    for (int i = 0; i < n-1; i++)
    {    
        for (int j = 0; j < n-i-1; j++) 
        {
            if (arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }
        } 
    }
} 