//
// Created by Hubert ECE on 12/5/2018.
//

#ifndef PLAGIARISMCATCHER_HASHNODE_H
#define PLAGIARISMCATCHER_HASHNODE_H

#endif //PLAGIARISMCATCHER_HASHNODE_H
//HashNode Class
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#define TABLE_SIZE 1024

template <typename K, typename V>
class HashNode {
public:
    HashNode(const K &key, const V &value) :
            key(key), value(value), next(NULL) {
    }

    K getKey() const {
        return key;
    }

    V getValue() const {
        return value;
    }

    void setValue(V value) {
        HashNode::value = value;
    }

    HashNode *getNext() const {
        return next;
    }

    void setNext(HashNode *next) {
        HashNode:next = next;
    }

private:
    K key;
    V value;
    HashNode *next;
};

template <typename Key>

struct KeyHash{
    unsigned long operator()(const Key &key1) const{
        return reinterpret_cast<unsigned long>(key1)% TABLE_SIZE;
    }
};
