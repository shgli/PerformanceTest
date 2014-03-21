#include "Performance.h"
Performance::Performance()
{
#ifdef _DEBUG
    IsDebug = true;
#else
    IsDebug = false;
#endif
}

