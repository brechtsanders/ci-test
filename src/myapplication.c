#include "mylibrary.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
  printf("Version: %s\n", mylibrary_get_version_string());
  return 0;
}
