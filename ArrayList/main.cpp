/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Dell
 *
 * Created on October 27, 2018, 5:16 PM
 */

#include <cstdlib>
#include <iostream>
#include "ArrayList.h"
using namespace std;
/*
 * 
 */
int main(int argc, char** argv) {

    ArrayList *list = new ArrayList();
    
    list->insertAtEnd(5);
    list->insertAt(3, 44);
    list->insertAtStart(77);
    list->insertAtStart(6);
    list->insertAtEnd(6);
    list->insertAt(2, 100);
    list->insertAt(1, 99);
    
    
    
    // DELETION TEST
    
    list->deleteFromStart();
    list->deleteFromEnd();
    list->deleteAt(4);
    list->deleteAt(1);
    
    
    
    // Re Inserting Some Values Just to populate the array.
    
    list->insertAtEnd(66);
    list->insertAt(2, 32);
    list->insertAt(7, 11);
    
    // SORT TESTING
    
    list->sortList();
    
    
    list->print();
    
    return 0;
}

