//
// Created by Hubert ECE on 12/5/2018.
//

#ifndef PLAGIARISMCATCHER_HASHMAP_H
#define PLAGIARISMCATCHER_HASHMAP_H

#endif //PLAGIARISMCATCHER_HASHMAP_H
#include "HashNode.h"
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>

template <typename Key, typename Value, typename kh = KeyHash<Key>>
        class HashMap {
        public:
            HashMap() {
                HashTable = new HashNode <Key, Value> *[TABLE_SIZE]();
            }

            ~HashMap() {
                for (int i = 0; i < TABLE_SIZE; i++) {
                    HashNode <Key, Value> *entry = HashTable[i]; //dealloc memory
                    while (entry != NULL) {
                        HashNode <Key, Value> *prev = entry;
                        entry = entry->getNext();
                        delete prev;
                    }
                    HashTable[i] = NULL;
                }

                delete[]HashTable;
            }

            bool getValue(const Key &key1, Value &value1) {
                unsigned long hashValue = HashFunction(key1);
                HashNode <Key, Value> *entry = HashTable[hashValue];

                while (entry != NULL) {
                    if (entry->getKey() == key1) {
                        value1 = entry->getValue();
                        return true;
                    }
                    entry = entry->getNext();
                }

                return false;
            }

            void insert(const Key &key1, const Value &value1) {
                unsigned long hashValue = HashFunction(key1);
                HashNode <Key, Value> *prev = NULL;
                HashNode <Key, Value> *entry = HashTable[hashValue];

                while (entry != NULL && entry->getKey() != key1) {
                    prev = entry;
                    entry = entry->getNext();
                }

                if (entry == NULL) {
                    entry = new HashNode<Key, Value>(key1, value1);
                    if (prev == NULL) {
                        HashTable[hashValue] = entry;
                    } else {
                        prev->setNext(entry);
                    }
                } else {
                    entry->setValue(value1);
                }
            }

            void remove(const Key &key1) {
                unsigned long hashValue = HashFunction(key1);
                HashNode <Key, Value> *prev = NULL;
                HashNode <Key, Value> *entry = HashTable[hashValue];

                while (entry != NULL && entry->getKey() != key1) {
                    prev = entry;
                    entry = entry->getNext();
                }

                if (entry == NULL) {
                    return;
                } else {
                    if (prev == NULL) {
                        HashTable[hashValue] = entry->getNext():
                    } else {
                        prev->setNext(entry->getNext());
                    }

                    delete entry;

                }

            }

        private:

            HashNode<Key, Value> **HashTable;

            kh HashFunction;
        };














