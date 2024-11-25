#include "Global.h"
#include <cstddef>

namespace FLORENCE
{
    bool Global::flag_core_ACTIVE = NULL;
    bool Global::flag_core_IDLE = NULL;
    bool Global::flag_write_IDLE[2] = { NULL, NULL };
    bool Global::flag_write_WAIT[2] = { NULL, NULL };
    bool Global::flag_write_WRITE[2] = { NULL, NULL };
    unsigned char* Global::ptr_num_Implemented_Cores = NULL;

    Global::Global()
    {
        this->flag_core_ACTIVE = new bool(true);
        this->flag_core_IDLE = new bool(false);

        this->flag_write_IDLE[0] = bool(false);
        this->flag_write_WAIT[0] = bool(false);
        this->flag_write_WRITE[0] = bool(true);
        
        this->flag_write_IDLE[1] = bool(false);
        this->flag_write_WAIT[1] = bool(true);
        this->flag_write_WRITE[1] = bool(false);

        this->ptr_num_Implemented_Cores = new unsigned char(4);//NUMBER OF CORES
    }

    Global::~Global()
    {
        delete this->ptr_num_Implemented_Cores;
    }

    bool Global::GetConst_Core_ACTIVE()
    {
        return this->flag_core_ACTIVE;
    }
    bool Global::GetConst_Core_IDLE()
    {
        return this->flag_core_IDLE;
    }
    unsigned char* Global::Get_NumCores()
    {
        return this->ptr_num_Implemented_Cores;
    }
    bool Global::GetConst_Write_IDLE(unsigned char index)
    {
        return this->flag_write_IDLE[index];
    }
    bool Global::GetConst_Write_WAIT(unsigned char index)
    {
        return this->flag_write_WAIT[index];
    }
    bool Global::GetConst_Write_WRITE(unsigned char index)
    {
        return this->flag_write_WRITE[index];
    }
}