#include "pch.h"
#include <cstddef>

namespace FLORENCE
{
    Algorithms* Server::ptr_Algorithms = NULL;
    Data* Server::ptr_Data = NULL;
    Execute* Server::ptr_Execute = NULL;
    Global* Server::ptr_Global = NULL;

    Server::Server()
    {
        this->ptr_Global = new FLORENCE::Global();
        while (this->ptr_Global == NULL) { /* wait untill created */ }

        this->ptr_Algorithms = new FLORENCE::Algorithms();
        while (this->ptr_Algorithms == NULL) { /* wait untill created */ }

        this->ptr_Data = new FLORENCE::Data(this->ptr_Global->Get_NumCores());
        while (this->ptr_Data == NULL) { /* wait untill created */ }
        this->ptr_Data->Initialise_Control();

        this->ptr_Execute = new FLORENCE::Execute(this->ptr_Global, ptr_Global->Get_NumCores());
        while (this->ptr_Execute == NULL) { /* wait untill created */ }
        this->ptr_Execute->Initialise_Control(this->Get_Global()->Get_NumCores(), this->ptr_Global);
    }

    Server::~Server()
    {
        delete this->ptr_Global;
        delete this->ptr_Algorithms;
        delete this->ptr_Data;
        delete this->ptr_Execute;
    }

    Algorithms* Server::Get_Algorithms()
    {
        return this->ptr_Algorithms;
    }

    Data* Server::Get_Data()
    {
        return this->ptr_Data;
    }

    Execute* Server::Get_Execute()
    {
        return this->ptr_Execute;
    }

    Global* Server::Get_Global()
    {
        return this->ptr_Global;
    }
}