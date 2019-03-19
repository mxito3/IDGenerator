#pragma once
#ifdef _WIN32
#include "peerControl_Win.h"
#else
#include "peerInControl_Unix.h"
#endif
namespace dev
{
namespace peeInControl
{
    class controller
    {
    private:
        /* data */
    public:
        std::string generateId();
        bool checkFirstLogin();
    };
}  // namespace peeInControl
}  // namespace dev
