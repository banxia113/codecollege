//
// Created by 秦艽 on 2024/3/26.
//

#ifndef STUDENT_STRUCT_VERIABLE_H
#define STUDENT_STRUCT_VERIABLE_H

typedef struct studentScore {
    float chinese;
    float math;
    float english;
    float sport;
} studentScore;

typedef struct Student {
    char *id;
    char *className;
    int age;
    char *uId;
    char *address;
    char *email;
    studentScore *score;
} Student;

#endif //STUDENT_STRUCT_VERIABLE_H
