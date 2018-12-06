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

    string fl=dir+ "/"+files[3].c_str();
    ifstream file;
    file.open(fl.c_str());

    cout<<"a" << endl;

    vector<string> chunks;
    chunks.clear();
    while(!file.eof())
    {
        string s;
        while(chunks.size() < atoi(argv[2]))
        {
            file>>s;
            chunks.push_back(s);
        }
        print(chunks);
        chunks.erase(chunks.begin());
        cout<<endl;
        cout<<endl;
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
