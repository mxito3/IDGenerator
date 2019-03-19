#pragma once
#include "cstring"
#include "fstream"
#include "iostream"
#include "openssl/md5.h"
#include "sstream"
#include "stdio.h"
#include <vector>
#include <curl/curl.h>
using namespace std;
class checkPermission
{
    public:
        string generateMD5(const char*password);
        bool check(string md5String);
        bool search(std::vector<std::string> source, std::string needFind);
        static bool checkUser(string userId, string password);
        checkPermission(){};
};