//
// Created by 秦艽 on 2024/3/26.
//

#ifndef STUDENT_UTIL_FUNCTIONS_H
#define STUDENT_UTIL_FUNCTIONS_H

Student *reverseIncrementArraySize(int elementsize){
    return (Student*)malloc(sizeof(Student)*(elementsize+INCREMENT_ARRAY_SIZE_COEFFICIENT));
}

Student *reverseDecrementArraySize(int arrysize){
    return (Student*)malloc(sizeof(Student)*(arrysize-DECREMENT_ARRAY_SIZE_COEFFICIENT));
}

#endif //STUDENT_UTIL_FUNCTIONS_H
