#ifndef peerInControlHeader
#define peerInControlHeader
#include "peerInControl.h" 
#endif

using namespace dev::peeInControl;

namespace dev
{
namespace peeInControl
{
    std::string controller::generateId()
{
#ifdef _WIN32
    return dev::winPeerInControl::createID();
#else
    return dev::UnixPeerInControl::createID();
#endif
}
    bool controller::checkFirstLogin()
    {
        
        using namespace dev::peeInControl;
        controller control;
        auto id = control.generateId();
        std::string password;
        cout<<"请输入授权码"<<endl;
        cin>>password;
        if(checkPermission::checkUser(id,password))
        {
            std::cout<<"验证通过"<<endl;
            return true;
        }
        else
        {
            std::cout<<"验证不通过，请前往小黄柚官网获取授权码"<<endl;
            return false;
        }

        
        
    }
}
}
