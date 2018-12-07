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
#include "HashTable.h"
using namespace std;
void print(std::vector<string> const &input);
/*function... might want it in some class?*/
int getdir (string dir, vector<string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}

int main(int argc, char *argv[])
{
    string dir = string("sm_doc_set");
    vector<string> files = vector<string>();
    getdir(dir,files);

    for (unsigned int i = 0;i < files.size();i++) {
        cout << i << files[i] << endl;
    }

    vector<string> chunks;
    chunks.clear();
    int key = 0;
    HashTable *hm = new HashTable;
    int count = 0;
   for(int k = 2; k<files.size(); k++) {

       string fl = dir + "/" + files[k].c_str();
       ifstream file;
       file.open(fl.c_str());
       chunks.clear();

       if(file.is_open() && file.good()) {
           while (!file.eof()) {
                cout << "Run: " << count << endl;
               string s;
               while (chunks.size() < atoi(argv[2])) {
                   file >> s;
                   chunks.push_back(s);
               }
               key = HashFunction(chunks);
               hm->insertItem(files[k].c_str(), key);
               print(chunks);
               chunks.erase(chunks.begin());
               count++;
           }
           file.close();
       }

   }

       int CPA[files.size()][files.size()];
       for (int i = 0; i < files.size(); i++) {

           for (int j = i + 1; j < files.size(); j++) {
               CPA[i][j] = hm->CollisionFinder(j, atoi(argv[3]));

           }

       }


       for (int i = 0; i < files.size(); i++) {
           for (int j = i + 1; j < files.size(); j++) {
               //if (CPA[i][j] != 0) {
                   cout << CPA[i][j] << ":" << hm->Find(i) <<"  " << hm->Find(j) << endl;
               //}
           }
       }
    return 0;
}

void print(vector<string> const &input)
{
    for(int  i =0; i<input.size(); i++)
    {
        cout << input[i] << endl;
    }
}




