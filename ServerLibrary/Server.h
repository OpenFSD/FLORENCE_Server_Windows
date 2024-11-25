#pragma once
#include "Algorithms.h"
#include "Data.h"
#include "Execute.h"
#include "Global.h"

namespace FLORENCE
{
    class Server
    {
    public:
        Server();
        virtual ~Server();
        Algorithms* Get_Algorithms();
        Data* Get_Data();
        Execute* Get_Execute();
        Global* Get_Global();

    protected:

    private:
        static class Algorithms* ptr_Algorithms;
        static class Data* ptr_Data;
        static class Execute* ptr_Execute;
        static class Global* ptr_Global;
    };
}