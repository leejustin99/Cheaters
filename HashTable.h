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
#include <cmath>
#define TABLE_SIZE 200000
using namespace std;
int HashFunction(vector<string> &chunk);
class HashTable {
public:
    HashTable(){
        Node *newnode = new struct Node;
        newnode->value = 0;
        newnode->next = NULL;
        for(int i=0; i<TABLE_SIZE; i++)
        {
            Table[i] = newnode;
        }
    }

    HashTable(const HashTable &source){}


    ~HashTable(){}

    void insertItem(const int &value, int key)
    {
        struct Node *node1 = new struct Node;
        node1->value = value;
        node1->next = NULL;
        Node *head = Table[key];
        Node *prev = head;
        if(head->value == 0){
            Table[key] = node1;
        }
        else
        {
           while(head != NULL)
           {
               prev = head;
               head = head->next;
           }
           prev->next = node1;
        }
    }

    int CollisionFinder(int file1, int file2)
    {
        int count = 0;
        int sim = 0;
        Node *head;

    for(int i=0 ;i < TABLE_SIZE; i++) {
        head = Table[i];
        while (head != NULL) {
            if (head->value == file1) {
                count++;
            }
            if(head->value == file2){
                count++;
            }
            if (count == 2) {
                sim++;
                count = 0;
            }
            head = head->next;
        }
        count = 0;
    }
        return sim;
    }

    int Find(int key){
        return Table[key]->value;
    }


private:
    struct Node {
        int value;
        Node *next;
    };

    struct Node *Table[TABLE_SIZE];

};


int HashFunction(vector<string> &chunk)
{
    int keyvalue = 0;
    int sub =0;
    int power = 0;

    for(int i=0; i<chunk.size()-1; i++){
        sub = atoi(chunk[chunk.size()-i-1].c_str());
        power = (int)pow((double)7,(double)i);
        if ((sub >= 97) && (sub <= 122)) {
            sub = sub - 32;
        }else if ((sub >= 48) && (sub <= 57))
        {
            sub = sub + 17;
        }
        keyvalue += sub*power;
    }
    if(keyvalue < 0)
    {
        while(keyvalue < 0)
        {
            keyvalue += 32;

        }
    }

    return keyvalue%TABLE_SIZE;
}
