#pragma once
#ifndef AKTIVACIJA_DOGADJAJA_H
#define AKTIVACIJA_DOGADJAJA_H

#define MAX_EVENT_NAME_LENGHT 50
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct event {
	char imeDogadjaja[MAX_EVENT_NAME_LENGHT];
	struct event* next;
} EVENT;
#endif