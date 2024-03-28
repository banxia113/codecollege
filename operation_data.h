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

void changemainData(Student* arrylist,int index,char* context,int dest){
    switch (dest) {
        case 1:{
            strcpy(arrylist[index].id,context);
            break;
        }
        case 2:{
            strcpy(arrylist[index].className,context);
            break;
        }
        case 3:{
            strcpy(arrylist[index].age,context);
            break;
        }
        case 4:{
            strcpy(arrylist[index].uId,context);
            break;
        }
        case 5:{
            strcpy(arrylist[index].address,context);
            break;
        }
        case 6:{
            strcpy(arrylist[index].email,context);
            break;
        }
    }
}

void changescoreData(Student* arrylist,int index,float score,int dest){
    switch (dest) {
        case 1:{
            arrylist[index].score->chinese=score;
            break;
        }
        case 2:{
            arrylist[index].score->math=score;
            break;
        }
        case 3:{
            arrylist[index].score->english=score;
            break;
        }
        case 4:{
            arrylist[index].score->sport=score;
            break;
        }
    }
}



#endif //STUDENT_OPERATION_DATA_H
