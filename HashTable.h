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
#define TABLE_SIZE 10000
using namespace std;
int HashFunction(vector<string> &chunk);
class HashTable {
public:
    HashTable(){}

    HashTable(const HashTable &source){}


    ~HashTable(){}

    void insertItem(const string &value, int key)
    {
        struct Node *node1 = new struct Node;
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

    int CollisionFinder(int key, int numbertocheck)
    {
        int count = 0;
        Node *head = new struct Node;
        *head = Table[key];

        while(head->next!= NULL){

            if(head->next->value != head->value)
            {

                count++;
            }
            head = head->next;
        }
        //if(count > numbertocheck)
            return count;
        //else
            //return 0;
    }

    string Find(int key){
        return Table[key].value;
    }


private:
    struct Node {
        string value;
        Node *next;
    };

    struct Node Table[TABLE_SIZE];

};

int HashFunction(vector<string> &chunk)
{
    int keyvalue = 0;
    int sub =0;
    int power = 0;

    for(int i=0; i<chunk.size()-1; i++){
        sub = atoi(chunk[chunk.size()-i-1].c_str());
        power = (int)pow((double)37,(double)i);
        if ((sub >= 97) && (sub <= 122)) {
            sub = sub - 32;
        }else if ((sub >= 48) && (sub <= 57))
        {
            sub = sub + 17;
        }else if(sub == 32)
        {

        }
        keyvalue += sub*power;
    }
    if(keyvalue < 0)
        keyvalue *= -1;
    return keyvalue%TABLE_SIZE;
}
