#pragma once
#ifndef LOAD_CONFIG_H_INCLUDED
#define LOAD_CONFIG_H_INCLUDED
#define CONFIG_KEY_LEN 30

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



extern const char* const CONFIG_TXT;
extern const char* const SAVED_TXT;

extern char CONFIG_ADRESA[CONFIG_KEY_LEN];
extern char CONFIG_DATA_FOLDER[CONFIG_KEY_LEN];
extern char CONFIG_DEV_FOLDER[CONFIG_KEY_LEN];

extern int CONFIG_N;

extern int SAVED_ID;


void loadConfig();
void updateSaved();
char* concat(const char*, const char*);

#endif // LOAD_CONFIG_H_INCLUDED
