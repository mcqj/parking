#pragma once
#define _GNU_SOURCE
#include <stdlib.h>

struct naryTree {
  struct naryTree* firstChild;
  struct naryTree* nextSibling;
};
