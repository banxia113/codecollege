//
// Created by 秦艽 on 2024/3/26.
//

#ifndef STUDENT_WATCHER_H
#define STUDENT_WATCHER_H

bool watcher(int arrysize,int elementsize,char action){
    switch (action) {
        case ACTION_INCREMENT:{
            if(arrysize>=elementsize+1)return false;
            else return true;
        }
        case ACTION_DECREMENT:{
            if(arrysize-elementsize>=DECREMENT_ARRAY_SIZE_COEFFICIENT)return true;
            else return false;
        }
    }
}

#endif //STUDENT_WATCHER_H
