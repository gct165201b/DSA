/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArrayList.h
 * Author: Dell
 *
 * Created on October 27, 2018, 5:17 PM
 */

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>
using std::cout;
using std::endl;

class ArrayList {
public:
    ArrayList();
    ArrayList(const ArrayList& orig);
    virtual ~ArrayList();
    
    
    // INSERTION OPERATIONS
    
    // 1: Insert At Start.
    
    void insertAtStart(int value);
    
    // 2: Insert At End
    
    void insertAtEnd(int value);
    
    // 3: Insert At Any Index.
    
    void insertAt(int index, int value);
    
    
    
    // DELETION
    
    // 1: Delete From Start
    
    void deleteFromStart();
    
    // 2: Delete From End
    
    void deleteFromEnd();
    
    // 3: Delete From a particular index
    
    void deleteAt(int index);
    
    // SORTING
    
    
    void sortList();
    
    
    
    // PRINT
    
    void print() {
        for(int i = 0 ; i < this->len ; i++) {
            cout << this->arr[i];
            if(i != this->len-1) {
                cout << " , ";
            }
        }
    }
    
    
    // OTHERS
    
    
    void shiftRightFrom(int);
    
    
    void shiftLeftFrom(int);
    
    void incSizeBy(int);
    
    int *getSmallestInList(int);
    
    int getSmallest(int);
    
    void swap(int *, int *);
    
private:
    int *arr;
    int index;
    int totalLength;
    int len;
    
};

#endif /* ARRAYLIST_H */

