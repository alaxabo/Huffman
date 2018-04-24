#include <stdio.h>
#include "definition.h"

typedef struct group {
  const float *difference;
  int number;
  int size;
} Group;

Group * fromDiffToGroup(float diff);
float getDataByIndex(int index, Group g);
