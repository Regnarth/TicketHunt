#pragma once
#define MAX 20
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void suspendujNalog();
int provjeraSuspenzije(FILE*, char*);
int memorisiNalog(FILE*, char*);