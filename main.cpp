
#ifndef peerInControlHeader
#define peerInControlHeader
#include "peerInControl.h" 
#endif
#include "cstring"
#include "fstream"
#include "iostream"
using namespace std;
int main()
{
    //生成id
    using namespace dev::peeInControl;
    controller control;
    auto id = control.generateId();
    std::cout<<"您的专属id是"<<id<<std::endl;
}
