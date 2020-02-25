#include "mylibrary.h"

DLL_EXPORT_MYLIBRARY void mylibrary_get_version (int* pmajor, int* pminor, int* pmicro)
{
  if (pmajor)
    *pmajor = MYLIBRARY_VERSION_MAJOR;
  if (pminor)
    *pminor = MYLIBRARY_VERSION_MINOR;
  if (pmicro)
    *pmicro = MYLIBRARY_VERSION_MICRO;
}

DLL_EXPORT_MYLIBRARY const char* mylibrary_get_version_string ()
{
  return MYLIBRARY_VERSION_STRING;
}
