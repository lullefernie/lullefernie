#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct _teacher Teacher;
typedef struct _student Student;
typedef struct _course_instance Course_instance;


typedef struct _teacher{

    char name[50];
    char email;
    long int phone_number;
    int office_number;
    Course_instance* given;


}Teacher;

typedef struct _student{

    char name[50];
    char email[50];
    long int phone_number;
    int class_year;
    int id;
    Course_instance* taken;

}Student;

typedef struct _course_instance{

    char name[50];
    int code;
    int points;
    int year;
    int period;
    Teacher* assigned;
    Student* enrolled;

}Course_instance;



void addStudent(Student* stu, Course_instance* cou){


    if(stu->taken == NULL){

        stu->taken = cou;
    }
    else{

       


    }



    if(cou->enrolled==NULL){

        cou->enrolled = stu;

    }
    


    

}



int main()
{
   
    Student* student1 = (Student*)malloc(sizeof(Student));
    strcpy(student1->name, "Hasse");
    strcpy(student1->email, "Hasse@email");
    student1->phone_number = 123;
    student1->class_year = 1;
    student1->id = 1;
    student1->taken = NULL;

    Student* student2 = (Student*)malloc(sizeof(Student));
    strcpy(student2->name, "Backe");
    strcpy(student2->email, "Backe@email");
    student2->phone_number = 234;
    student2->class_year = 2;
    student2->id = 2;
    student2->taken = NULL;

    Course_instance* course_instance1 = (Course_instance*)malloc(sizeof(Course_instance));
    strcpy(course_instance1->name, "programming");
    course_instance1->code = 1;
    course_instance1->points = 7;
    course_instance1->year = 3;
    course_instance1->period = 5;
    course_instance1->enrolled = NULL;
    course_instance1->assigned = NULL;

    Course_instance* course_instance2 = (Course_instance*)malloc(sizeof(Course_instance));
    strcpy(course_instance2->name, "maths");
    course_instance2->code = 2;
    course_instance2->points = 7;
    course_instance2->year = 5;
    course_instance2->period = 1;
    course_instance2->enrolled = NULL;
    course_instance2->assigned = NULL;

 
    addStudent(student1, course_instance1);
 
    printf("%d", student1->taken->period);
  
}