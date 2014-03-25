#include "Performance.h"
Performance::Performance()
{
#ifdef DEBUG
    IsDebug = true;
#else
    IsDebug = false;
#endif
}

