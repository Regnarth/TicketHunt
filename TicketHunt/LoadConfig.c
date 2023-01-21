#include "LoadConfig.h"

#define LOAD_CONFIG_FORMAT_IN " \"%[^\"]\"%*[^\"]\"%[^\"]\""
#define SAVED_TEMP_TXT "Config\\.temp.txt"


const char* const CONFIG_TXT = "Config\\config.txt";
const char* const SAVED_TXT = "Config\\saved.txt";

char CONFIG_ADRESA[CONFIG_KEY_LEN] = "";
char CONFIG_DATA_FOLDER[CONFIG_KEY_LEN] = "";
char CONFIG_DEV_FOLDER[CONFIG_KEY_LEN] = "";

int CONFIG_N = -1;

int SAVED_ID = -1;

void loadConfig()
{
	FILE* configFile, * savedFile;
	if ((configFile = fopen(CONFIG_TXT, "r")) == NULL)
	{
		printf("Nije moguce ocitati konfiguracioni fajl.\n");
		exit(1);
	}
	if ((savedFile = fopen(SAVED_TXT, "r")) == NULL)
	{
		printf("Nije moguce ocitati konfiguracioni fajl.\n");
		exit(1);
	}

	char key[30], value[50];
	while (fscanf(configFile, LOAD_CONFIG_FORMAT_IN, key, value) != EOF)
	{

		if (strcmp(key, "CONFIG_ADRESA") == 0)
		{
			strcpy(CONFIG_ADRESA, value);
			continue;
		}
		if (strcmp(key, "CONFIG_DATA_FOLDER") == 0)
		{
			strcpy(CONFIG_DATA_FOLDER, value);
			continue;
		}
		if (strcmp(key, "CONFIG_DEV_FOLDER") == 0)
		{
			strcpy(CONFIG_DEV_FOLDER, value);
			continue;
		}
		if (strcmp(key, "CONFIG_N") == 0)
		{
			sscanf(value, "%d", &CONFIG_N);
			continue;
		}
	}


	while (fscanf(savedFile, LOAD_CONFIG_FORMAT_IN, key, value) != EOF)
	{
		if (strcmp(key, "SAVED_ID") == 0)
		{
			sscanf(value, "%d", &SAVED_ID);
			continue;
		}
	}

	fclose(configFile);
	fclose(savedFile);
}

void updateSaved()
{
	FILE* oldSaved, * newSaved;
	if ((oldSaved = fopen(SAVED_TXT, "r")) == NULL)
	{
		printf("Nije moguce ocitati konfiguracioni fajl.\n");
		exit(1);
	}

	if ((newSaved = fopen(SAVED_TEMP_TXT, "w")) == NULL)
	{
		printf("Nije moguce ocitati konfiguracioni fajl.\n");
		exit(1);
	}

	char key[30], value[20];
	while (fscanf(oldSaved, LOAD_CONFIG_FORMAT_IN, key, value) != EOF)
	{
		if (strcmp(key, "SAVED_ID") == 0)
		{
			fprintf(newSaved, "\"SAVED_ID\" : \"%d\"\n", SAVED_ID);
			continue;
		}
	}

	fclose(oldSaved);
	fclose(newSaved);

	if (remove(SAVED_TXT) == -1)
	{
		printf("Nije moguce ocitati konfiguracioni fajl.\n");
		exit(1);
	}

	rename(SAVED_TEMP_TXT, SAVED_TXT);
}


char* concat(const char* str1, const char* str2) {
	size_t len1 = strlen(str1);
	size_t len2 = strlen(str2);
	char* result = malloc(len1 + len2 + 1); // +1 for the null-terminator
	memcpy(result, str1, len1);
	memcpy(result + len1, str2, len2 + 1); // +1 to copy the null-terminator
	return result;
}

