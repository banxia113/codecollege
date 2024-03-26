#include <iostream>
#include"static_veriable.h"
#include"struct_veriable.h"
#include"util_functions.h"
#include"watcher.h"
#include"copy.h"
#include"operation_data.h"


Student *initState();
void append(Student* arry,Student data);
void pop(Student* arry,char* content,char way);
int find(Student* arrylist,char* content,char way,int elementsize);
void change();

int arraySize = INCREMENT_ARRAY_SIZE_COEFFICIENT;
int elementSize = 0;


int main() {

    return 0;
}

Student* initState(){
    return (Student*)malloc(sizeof(Student)*INCREMENT_ARRAY_SIZE_COEFFICIENT);
}

void append(Student* arry,Student data){//增
    if(watcher(arraySize,elementSize,'i')){
        Student* newlist=reverseIncrementArraySize(arraySize);
        copy(arry,newlist,elementSize);
        appendData(newlist,data,elementSize);
        arry=newlist;
        arraySize+=INCREMENT_ARRAY_SIZE_COEFFICIENT;
    }
    else{
        appendData(arry,data,elementSize);
    }
    elementSize++;
}

void pop(Student* arry,char* content,char way){//删
    int index=find(arry,content,way,elementSize);
    if(index!=-1){
        popData(arry,index,elementSize);
        elementSize--;
        if(watcher(arraySize,elementSize,'d')){
            Student* newlist=reverseDecrementArraySize(arraySize);
            copy(arry,newlist,elementSize);
            arry=newlist;
            arraySize-=DECREMENT_ARRAY_SIZE_COEFFICIENT;
        }
    }
    else{
        printf("没有所查询的对象请重新输入");
    }
}

int find(Student* arrylist,char* content,char way,int elementsize){//插
    switch (way) {
        case FIND_ID:{
            for(int i=0;i<elementsize;i++){
                if(strcmp(arrylist[i].id,content)==0)return i;
            }
            return -1;
        }
        case FIND_UID:{
            for(int i=0;i<elementsize;i++){
                if(strcmp(arrylist[i].uId,content)==0)return i;
            }
            return -1;
        }
        case FIND_EMAIL:{
            for(int i=0;i<elementsize;i++){
                if(strcmp(arrylist[i].email,content)==0)return i;
            }
            return -1;
        }
    }
}

void change(Student* arry,char* content,char way){
    int index=find(arry,content,way,elementSize);
    if(index!=-1){

    }
    else{
        printf("该学生不存在");
    }
}