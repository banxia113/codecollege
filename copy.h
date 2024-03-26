//
// Created by 秦艽 on 2024/3/26.
//

#ifndef STUDENT_COPY_H
#define STUDENT_COPY_H

void copy(Student* oldarry,Student* newarry,int elementsize){
    for(int i=0;i<elementsize;i++){
        newarry[i]=oldarry[i];
    }
}

#endif //STUDENT_COPY_H
