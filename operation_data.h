//
// Created by 秦艽 on 2024/3/26.
//

#ifndef STUDENT_OPERATION_DATA_H
#define STUDENT_OPERATION_DATA_H
#include "string.h"

void appendData(Student* arrylist,Student data,int elementsize){
    arrylist[elementsize]=data;
}

void popData(Student* arrylist,int index,int elementsize){
    for(int i=index;i<elementsize-1;i++){
        arrylist[i]=arrylist[i+1];
    }
}

#endif //STUDENT_OPERATION_DATA_H
