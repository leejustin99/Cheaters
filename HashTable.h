//
// Created by Hubert ECE on 12/6/2018.
//

#ifndef PLAGIARISMCATCHER_HASHTABLE_H
#define PLAGIARISMCATCHER_HASHTABLE_H

#endif //PLAGIARISMCATCHER_HASHTABLE_H
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <cstring>
#define TABLE_SIZE 1024
using namespace std;
class HashTable {
public:
    HashTable();

    HashTable(const HashTable &source);

    ~HashTable();

    void insertItem(string &value, int key)
    {
        struct Node *node1;
        node1->value = value;
        node1->next = NULL;

        if(Table[key].value == ""){
            Table[key] = *node1;
        }
        else
        {
            Table[key].next = node1;
        }

    }

    bool CollisionFinder(int key, string &name , int numbertocheck)
    {

            for(int i=0;i<TABLE_SIZE;i++){
                if(Table[i].next != NULL){
                    if(Table[i].next->value != Table[i].value)
                    {
                        return true;
                    }
                }

            }
    }


private:
    struct Node {
        string value;
        Node *next;
    };

    struct Node Table[TABLE_SIZE];

};
