#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _teacher Teacher;
typedef struct _student Student;
typedef struct _course_instance Course_instance;


typedef struct _teacher{

    char name[50];
    char email[50];
    long int phone_number;
    int office_number;
    int courses;
    Course_instance* given;


}Teacher;

typedef struct _student{

    char name[50];
    char email[50];
    long int phone_number;
    int class_year;
    int id;
    int courses;
    Course_instance* taken;

}Student;

typedef struct _course_instance{

    char name[50];
    int code;
    int points;
    int year;
    int period;
    int students;
    int teachers;
    Teacher* assigned;
    Student* enrolled;

}Course_instance;

void printParticapants(Course_instance* cou){

    for(int i = 0; i<cou->students; i++){

        printf("Student: %s\n", cou->enrolled[i].name);
    }
    for(int i = 0; i<cou->teachers; i++){
     
        printf("Teacher: %s\n", cou->assigned[i].name);
    }
}

void printCourse(Course_instance* cou){

    printf("Name: %s\nCode: %d\nPoints: %d\n\n",cou->name,cou->code,cou->points);
}
void printStudent(Student* stu){

    printf("Name: %s\nEmail: %s\nPhone Number: %d\nClass: %d\nStudent Id:%d\n\n",stu->name,stu->email,stu->phone_number,stu->class_year,stu->id);
}

void printTeacher(Teacher* tea){

    printf("Name: %s\nEmail: %s\nPhone Number: %d\nOffice Number: %d\n\n",tea->name,tea->email,tea->phone_number,tea->office_number);
}

void addStudent(Course_instance* cou, Student* stu ){

    if(cou->students == 0){

        cou->enrolled = (Student*)malloc(sizeof(Student));
    }

    else{

        cou->enrolled = (Student*)realloc(cou->enrolled, (cou->students + 1)* sizeof(Student));

    }

    cou->enrolled[cou->students].class_year = stu->class_year;
    cou->enrolled[cou->students].id = stu->id;
    cou->enrolled[cou->students].phone_number = stu->id;
    strcpy(cou->enrolled[cou->students].name, stu->name);
    strcpy(cou->enrolled[cou->students].email, stu->email);
    cou->students++;

    if(stu->courses == 0){

        stu->taken = (Course_instance*)malloc(sizeof(Course_instance));

    }
    else{

        stu->taken = (Course_instance*)realloc(stu->taken, (stu->courses+1)*sizeof(Course_instance));

    }

    stu->taken[stu->courses].code = cou->code;
    stu->taken[stu->courses].period = cou->period;
    stu->taken[stu->courses].points = cou->points;
    stu->taken[stu->courses].year = cou->year;
    strcpy(stu->taken[stu->courses].name, cou->name);
    stu->courses++;

}

void addTeacher(Course_instance* cou, Teacher* tea ){

    if(cou->teachers == 0){

        cou->assigned = (Teacher*)malloc(sizeof(Teacher));
    }

    else{

        cou->assigned = (Teacher*)realloc(cou->assigned, (cou->teachers + 1)* sizeof(Teacher));

    }

    cou->assigned[cou->teachers].office_number = tea->office_number;
    cou->assigned[cou->teachers].phone_number = tea->phone_number;
    strcpy(cou->assigned[cou->teachers].email,tea->email);
    strcpy(cou->assigned[cou->teachers].name,tea->name);
    cou->teachers++;

    if(tea->courses == 0){

        tea->given = (Course_instance*)malloc(sizeof(Course_instance));

    }
    else{

        tea->given = (Course_instance*)realloc(tea->given, (tea->courses+1)*sizeof(Course_instance));

    }

    tea->given[tea->courses].code = cou->code;
    tea->given[tea->courses].period = cou->period;
    tea->given[tea->courses].points = cou->points;
    tea->given[tea->courses].year = cou->year;
    strcpy(tea->given[tea->courses].name, cou->name);
    tea->courses++;

}

int main()
{

    Course_instance* course = (Course_instance*)malloc(2* sizeof(Course_instance));
    Student* student = (Student*)malloc(2*sizeof(Student));
    Teacher* teacher = (Teacher*)malloc(2*sizeof(Teacher));

    int i;
    for(i =0; i<2; ++i){

        course[i].students = course[i].teachers = student[i].courses= teacher[i].courses = 0;
        course[i].enrolled = NULL;
        course[i].assigned = NULL;
        student[i].taken = NULL;
        teacher[i].given = NULL;
       
    }
    course[0].code = 1;
    course[0].points = 7;
    course[0].year = 3;
    course[0].period = 5;
    strcpy(course[0].name, "programming");

    course[1].code = 2;
    course[1].points = 7;
    course[1].year = 5;
    course[1].period = 1;
    strcpy(course[1].name, "maths");


    student[0].phone_number = 123;
    student[0].id = 1;
    student[0].class_year = 1;
    strcpy(student[0].email,"Hasse@email");
    strcpy(student[0].name,"Hasse");

    student[1].phone_number = 234;
    student[1].id = 2;
    student[1].class_year = 3;
    strcpy(student[1].email,"Backe@email");
    strcpy(student[1].name,"Backe");


    teacher[0].office_number = 1;
    teacher[0].phone_number = 345;
    strcpy(teacher[0].email,"Joppe@email");
    strcpy(teacher[0].name,"Joppe");

    teacher[1].office_number = 2;
    teacher[1].phone_number = 456;
    strcpy(teacher[1].email,"Jan@email");
    strcpy(teacher[1].name,"Jan");

    addTeacher(&course[0], &teacher[0]);
 
   
    
    addStudent(&course[0], &student[0]);
    addStudent(&course[0], &student[1]);
 

   

    printCourse(&course[0]);
    printCourse(&course[1]);
    printStudent(&student[0]);
    printTeacher(&teacher[0]);
   

    printParticapants(&course[0]);


  
}