#include <iostream>
#include"static_veriable.h"
#include"struct_veriable.h"
#include"util_functions.h"
#include"watcher.h"
#include"copy.h"
#include"operation_data.h"
using namespace std;


Student *initState();
Class* initClassState();
void append(Student* arry,Student data);
void pop(Student* arry,char* content,char way);
int find(Student* arrylist,char* content,char way,int elementsize);
void change(Student* arry,char* content,char way);
Class* classappend(Class* head,char * classname,char* id);
void classpop(Class* head,char* classname,char* id);
void classcombine(Class* head,char* classname1,char* classname2);
void printclass(Class* head,char* classname);
void printdata(Student* arrylist,int index);


Student* studentlist;
Class* allclasshead=NULL;
int arraySize = INCREMENT_ARRAY_SIZE_COEFFICIENT;
int elementSize = 0;


void system(){
    cout<<"欢迎使用学生管理系统"<<endl;
    cout<<"****输入0退出****"<<endl;
    cout<<"****输入1加入****"<<endl;
    cout<<"****输入2删除****"<<endl;
    cout<<"****输入3查询****"<<endl;
    cout<<"****输入4改动****"<<endl;
    cout<<"****输入5合并****"<<endl;
    cout<<"****输入6查看班级成员****"<<endl;
    while(1){
        int option=-1;
        cout<<"请输入您的操作：";
        cin>>option;
        cin.ignore();// 清除输入缓冲区中的剩余字符否则将会对第一次getline造成影响会直接跳过第一次的getline
        if(option==0)return;
        else {
            switch(option){
                case 1:{
                    Student* student=(Student*)malloc(sizeof(Student));
                    student->score=NULL;
                    char* id=(char*)malloc(sizeof(char)*100);
                    char* classname=(char*)malloc(sizeof(char)*100);
                    char* age=(char*)malloc(sizeof(char)*100);
                    char* uid=(char*)malloc(sizeof(char)*100);
                    char* address=(char*)malloc(sizeof(char)*100);
                    char* email=(char*)malloc(sizeof(char)*100);

                    while(1){
                        cout<<"请输入学生学号(必填):  ";
                        cin.getline(id,100);
                        if(id[0]!='\0'){
                            student->id=id;
                            break;
                        }
                        else{
                            cout<<"该选项不能为空"<<endl;
                        }
                    }

                    while(1){
                        cout<<"请输入学生班级(必填):  ";
                        cin.getline(classname,100);
                        if(classname[0]!='\0'){
                            student->className=classname;
                            break;
                        }
                        else{
                            cout<<"该选项不能为空"<<endl;
                        }
                    }

                    cout<<"请输入学生年龄(选填):  ";
                    if(cin.getline(age,100)){
                        student->age=age;
                    }
                    else{
                        student->age="(null)";
                    }

                    while(1){
                        cout<<"请输入学生身份证号(必填):  ";
                        if(cin.getline(uid,100)){
                            student->uId=uid;
                            break;
                        }
                        else{
                            cout<<"该选项不能为空"<<endl;
                        }
                    }

                    cout<<"请输入学生地址(选填):  ";
                    if(cin.getline(address,100)){
                        student->address=address;
                    }
                    else{
                        student->address="(null)";
                    }

                    while(1){
                        cout<<"请输入学生邮箱(必填):  ";
                        cin.getline(email,100);
                        if(email[0]!='\0'){
                            student->email=email;
                            break;
                        }
                        else{
                            cout<<"该选项不能为空"<<endl;
                        }
                    }

                    cout<<"是否插入成绩"<<endl;
                    cout<<"**选1插入**"<<endl;
                    cout<<"**选0不插**"<<endl;
                    int opt=0;
                    cin>>opt;
                    if(opt){
                        student->score=(studentScore*)malloc(sizeof(studentScore));
                        while(1){
                            cout<<"请输入语文成绩:  ";
                            cin>>student->score->chinese;
                            if(student->score->chinese<=SCORE_MAIN_SUBJECT_MAX && student->score->chinese>=SCORE_MAIN_SUBJECT_MIN)break;
                            else{
                                cout<<"输入错误请重新输入"<<endl;
                            }
                        }
                        while(1){
                            cout<<"请输入数学成绩:  ";
                            cin>>student->score->math;
                            if(student->score->math<=SCORE_MAIN_SUBJECT_MAX && student->score->math>=SCORE_MAIN_SUBJECT_MIN)break;
                            else{
                                cout<<"输入错误请重新输入"<<endl;
                            }
                        }
                        while(1){
                            cout<<"请输入英语成绩:  ";
                            cin>>student->score->english;
                            if(student->score->english<=SCORE_MAIN_SUBJECT_MAX && student->score->english>=SCORE_MAIN_SUBJECT_MIN)break;
                            else{
                                cout<<"输入错误请重新输入"<<endl;
                            }
                        }
                        while(1){
                            cout<<"请输入体育成绩:  ";
                            cin>>student->score->sport;
                            if(student->score->sport<=SPORT_SUBJECT_MAX && student->score->chinese>=SPORT_SUBJECT_MIN)break;
                            else{
                                cout<<"输入错误请重新输入"<<endl;
                            }
                        }
                    }

                    append(studentlist,*student);
                    allclasshead=classappend(allclasshead,classname,id);
                    break;
                }
                case 2:{
                    if(elementSize==0){
                        cout<<"没有学生记录无需删除"<<endl;
                        break;
                    }
                    cout<<"请输入删除方式"<<endl;
                    cout<<"输入1搜索学号"<<endl;
                    cout<<"输入2搜索身份证"<<endl;
                    cout<<"输入3搜索邮箱"<<endl;
                    int opt=0;
                    cin>>opt;
                    switch (opt) {
                        case 1:{
                            char* content=(char*)malloc(sizeof(char)*100);
                            cin>>content;
                            pop(studentlist,content,FIND_ID);
                            break;
                        }
                        case 2:{
                            char* content=(char*)malloc(sizeof(char)*100);
                            cin>>content;
                            pop(studentlist,content,FIND_UID);
                            break;
                        }
                        case 3:{
                            char* content=(char*)malloc(sizeof(char)*100);
                            cin>>content;
                            pop(studentlist,content,FIND_EMAIL);
                            break;
                        }
                    }
                    break;
                }
                case 3:{
                    if(elementSize==0){
                        cout<<"没有学生记录"<<endl;
                        break;
                    }
                    cout<<"请输入查询方式"<<endl;
                    cout<<"输入1搜索学号"<<endl;
                    cout<<"输入2搜索身份证"<<endl;
                    cout<<"输入3搜索邮箱"<<endl;
                    int opt=0;
                    cin>>opt;
                    switch (opt) {
                        case 1:{
                            char* content=(char*)malloc(sizeof(char)*100);
                            cin>>content;
                            int index=find(studentlist,content,FIND_ID,elementSize);
                            printdata(studentlist,index);
                            break;
                        }
                        case 2:{
                            char* content=(char*)malloc(sizeof(char)*100);
                            cin>>content;
                            int index=find(studentlist,content,FIND_UID,elementSize);
                            printdata(studentlist,index);
                            break;
                        }
                        case 3:{
                            char* content=(char*)malloc(sizeof(char)*100);
                            cin>>content;
                            int index=find(studentlist,content,FIND_EMAIL,elementSize);
                            printdata(studentlist,index);
                            break;
                        }
                    }
                    break;
                }
                case 4:{
                    if(elementSize==0){
                        cout<<"没有学生记录"<<endl;
                        break;
                    }
                    cout<<"请输入查询方式"<<endl;
                    cout<<"输入1搜索学号"<<endl;
                    cout<<"输入2搜索身份证"<<endl;
                    cout<<"输入3搜索邮箱"<<endl;
                    int opt=0;
                    cin>>opt;
                    switch (opt) {
                        case 1:{
                            cout<<"请输入更改对象的学号";
                            char* content=(char*)malloc(sizeof(char)*100);
                            cin>>content;
                            change(studentlist,content,FIND_ID);
                            break;
                        }
                        case 2:{
                            cout<<"请输入更改对象的身份证";
                            char* content=(char*)malloc(sizeof(char)*100);
                            cin>>content;
                            change(studentlist,content,FIND_UID);
                            break;
                        }
                        case 3:{
                            cout<<"请输入更改对象的邮箱";
                            char* content=(char*)malloc(sizeof(char)*100);
                            cin>>content;
                            change(studentlist,content,FIND_EMAIL);
                            break;
                        }
                    }
                    break;
                }
                case 5:{
                    cout<<"请输入和并的两个班级：";
                    char* classname1=(char*)malloc(sizeof(char)*100);
                    char* classname2=(char*)malloc(sizeof(char)*100);
                    cin>>classname1>>classname2;
                    classcombine(allclasshead,classname1,classname2);
                    break;
                }
                case 6:{
                    cout<<"请输入查看的班级：";
                    char* classname=(char*)malloc(sizeof(char)*100);
                    cin>>classname;
                    printclass(allclasshead,classname);
                    break;
                }
            }
        }
    }
}


int main() {
    studentlist=initState();
    system();
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
        classpop(allclasshead,arry[index].className,arry[index].id);
        return;
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
    cout<<"更改学号输入1";
    cout<<"更改班级输入2";
    cout<<"更改年龄输入3";
    cout<<"更改身份证输入4";
    cout<<"更改地址输入5";
    cout<<"更改邮箱输入6";
    cout<<"更改成绩输入7";
    cout<<"输入0表示退出";
    if(index!=-1){
        while(1){
            cout<<"请输入更改位置";
            int dest;
            cin>>dest;
            cout<<"请输入更改后的内容";
            char* context=(char*)malloc(sizeof(char)*100);
            cin>>context;
            if(dest==0)return ;
            switch (dest) {
                case 1:{
                    changemainData(studentlist,index,context,1);
                    break;
                }
                case 2:{
                    classpop(allclasshead,arry[index].className,arry[index].id);
                    changemainData(studentlist,index,context,2);
                    classappend(allclasshead,arry[index].className,arry[index].id);
                    break;
                }
                case 3:{
                    changemainData(studentlist,index,context,3);
                    break;
                }
                case 4:{
                    changemainData(studentlist,index,context,4);
                    break;
                }
                case 5:{
                    changemainData(studentlist,index,context,5);
                    break;
                }
                case 6:{
                    changemainData(studentlist,index,context,6);
                    break;
                }
                case 7:{
                    cout<<"输入1改变语文"<<endl;
                    cout<<"输入1改变数学"<<endl;
                    cout<<"输入1改变英语"<<endl;
                    cout<<"输入1改变体育"<<endl;
                    while(1){
                        cout<<"请输入改变的科目";
                        int option=0;
                        cin>>option;
                        switch (option) {
                            case 1:{
                                cout<<"请输入分数";
                                int score=0;
                                cin>>score;
                                while(1){
                                    if(score>=SCORE_MAIN_SUBJECT_MIN&&score<=SCORE_MAIN_SUBJECT_MAX)break;
                                    else{
                                        cout<<"无效输入"<<endl;
                                    }
                                }
                                changescoreData(studentlist,index,score,1);
                                break;
                            }
                            case 2:{
                                cout<<"请输入分数";
                                int score=0;
                                cin>>score;
                                while(1){
                                    if(score>=SCORE_MAIN_SUBJECT_MIN&&score<=SCORE_MAIN_SUBJECT_MAX)break;
                                    else{
                                        cout<<"无效输入"<<endl;
                                    }
                                }
                                changescoreData(studentlist,index,score,2);
                                break;
                            }
                            case 3:{
                                cout<<"请输入分数";
                                int score=0;
                                cin>>score;
                                while(1){
                                    if(score>=SCORE_MAIN_SUBJECT_MIN&&score<=SCORE_MAIN_SUBJECT_MAX)break;
                                    else{
                                        cout<<"无效输入"<<endl;
                                    }
                                }
                                changescoreData(studentlist,index,score,3);
                                break;
                            }
                            case 4:{
                                cout<<"请输入分数";
                                int score=0;
                                cin>>score;
                                while(1){
                                    if(score>=SPORT_SUBJECT_MIN&&score<=SPORT_SUBJECT_MAX)break;
                                    else{
                                        cout<<"无效输入"<<endl;
                                    }
                                }
                                changescoreData(studentlist,index,score,4);
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    else{
        printf("该学生不存在");
    }
}

void changeclass(Student* arry,char* content,char way){
    int index=find(arry,content,way,elementSize);
    strcpy(arry[index].className,content);
    return ;
}

Class* classappend(Class* head,char* classname,char* id){
    Class* pre=NULL;
    Class* cur=head;
    while(cur!=NULL){
        if(strcmp(classname,cur->name)==0){
            StudentId* Id=(StudentId*)malloc(sizeof(StudentId));
            Id->id=(char*)malloc(sizeof(char)*100);
            strcpy(Id->id,id);
            Id->next=NULL;
            cur->tail->next=Id;
            cur->tail=Id;
            return head;
        }
        pre=cur;
        cur=cur->next;
    }
    if(head==NULL){
        head=(Class*)malloc(sizeof(Class));
        strcpy(head->name,classname);
        StudentId* Id=(StudentId*)malloc(sizeof(StudentId));
        Id->id=(char*)malloc(sizeof(char)*100);
        strcpy(Id->id,id);
        Id->next=NULL;
        head->head=Id;
        head->tail=Id;
        head->next=NULL;
        return head;
    }
    else{
        cur=(Class*)malloc(sizeof(Class));
        strcpy(cur->name,classname);
        StudentId* Id=(StudentId*)malloc(sizeof(StudentId));
        Id->id=(char*)malloc(sizeof(char)*100);
        strcpy(Id->id,id);
        Id->next=NULL;
        cur->head=Id;
        cur->tail=Id;
        cur->next=NULL;
        pre->next=cur;
        return head;
    }

}

void classpop(Class* head,char* classname,char* id){
    Class* cur=head;
    while(cur!=NULL){
        if(strcmp(head->name,classname)){
            StudentId* Idpre=NULL;
            StudentId* Idcur=cur->head;
            while(Idcur!=NULL){
                if(strcmp(id,Idcur->id)){
                    Idpre->next=Idcur->next;
                    return;
                }
                Idpre=Idcur;
                Idcur=Idcur->next;
            }
        }
        cur=cur->next;
    }
}

void classcombine(Class* head,char* classname1,char* classname2){
    Class* first=NULL;
    Class* second=NULL;
    Class* cur=head;
    while(cur!=NULL && (first==NULL || second==NULL)){
        if(strcmp(cur->name,classname1)==0){
            first=cur;
        }
        if(strcmp(cur->name,classname2)==0){
            second=cur;
        }
        cur=cur->next;
    }
    if(first==NULL || second==NULL)return ;
    first->tail->next=second->head;
    StudentId *curid=second->head;
    while(curid!=NULL){
        changeclass(studentlist,curid->id,FIND_ID);
        curid=curid->next;
    }
}

void printclass(Class* head,char* classname){
    Class* cur=head;
    while(head!=NULL){
        if(strcmp(head->name,classname)==0){
            break;
        }
    }
    cout<<"是否打印成绩"<<endl;
    cout<<"输入1打印"<<endl;
    cout<<"输入0不打印"<<endl;
    cout<<"请输入你的选择：";
    int option=0;
    cin>>option;
    StudentId * curid=cur->head;
    while(curid!=NULL){
        int index=find(studentlist,curid->id,FIND_ID,elementSize);
        if(option==1){
            printf("%s\t%s\t%s\t%s\t%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\n",studentlist[index].id,studentlist[index].className,studentlist[index].age,studentlist[index].uId,studentlist[index].address,studentlist[index].email,studentlist[index].score->chinese,studentlist[index].score->math,studentlist[index].score->english,studentlist[index].score->sport);
        }
        else printf("%s\t%s\t%s\t%s\t%s\t%s\n",studentlist[index].id,studentlist[index].className,studentlist[index].age,studentlist[index].uId,studentlist[index].address,studentlist[index].email);

        curid=curid->next;
    }
}

void printdata(Student* arrylist,int index){
    cout<<"是否打印成绩"<<endl;
    cout<<"输入1打印"<<endl;
    cout<<"输入0不打印"<<endl;
    cout<<"请输入你的选择：";
    int option=0;
    cin>>option;
    if(option==1){
        printf("%s\t%s\t%s\t%s\t%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\n",studentlist[index].id,studentlist[index].className,studentlist[index].age,studentlist[index].uId,studentlist[index].address,studentlist[index].email,studentlist[index].score->chinese,studentlist[index].score->math,studentlist[index].score->english,studentlist[index].score->sport);
    }
    else printf("%s\t%s\t%s\t%s\t%s\t%s\n",studentlist[index].id,studentlist[index].className,studentlist[index].age,studentlist[index].uId,studentlist[index].address,studentlist[index].email);
    return ;
}

