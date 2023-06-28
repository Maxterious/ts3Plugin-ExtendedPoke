#include <stdio.h>
#include "config.h"
#include <errno.h>
#include <string.h>

FILE* fptr;
FILE* fTemp;
const char configPath[200];
const char configName[] = "extendedPokeConfig.txt";
const char tmpConfigPath[200];
const char tmpConfigName[] = "tmpConfigFile.tmp";
char* search = "=";
char tempBuffer[1000];

char* writeToConfig(char* key, char* value, char* buffer, size_t bufSize) {
	char newKeyValuePair[] = "";

	if ((fptr = fopen(configPath, "a")) == NULL) {
		snprintf(buffer, bufSize, "%s%s%s%s", "Failed creating file: ", configPath, "\n", strerror(errno));
		return buffer;
	}

	//search if token is already existing
	if (readFromConfig(key, value, buffer, bufSize) == NULL) { //readFromConfig causes the error (maybe closes fptr so next function cant use it)
		//key not existing, add to config file
		strcat(newKeyValuePair, key);
		strcat(newKeyValuePair, "=");
		strcat(newKeyValuePair, value);
		strcat(newKeyValuePair, "\n");



		if (fprintf(fptr, "%s", newKeyValuePair) < 0) {
			snprintf(buffer, bufSize, "%s%s%s%s", "Failed writing file: ", configPath, "\n", strerror(errno));
			fclose(fptr);
			return buffer;
		}
		fclose(fptr);
	}
	else {
		if ((fTemp = fopen(tmpConfigPath, "w")) == NULL) {
			snprintf(buffer, bufSize, "%s%s%s%s", "Failed creating file: ", tmpConfigPath, "\n", strerror(errno));
			return buffer;
		}

		// Replace all occurrence of word from current line
		replaceAll(buffer, readFromConfig(key, value, buffer, bufSize), value);  //check if buffer is right here
		// After replacing write it to temp file
		fputs(tempBuffer, fTemp); //check if tempBuffer is right here, it doesnt really get
		fclose(fTemp);
	}

	/* Delete original source file */
	if (remove(configPath) != 0) {
		snprintf(buffer, bufSize, "%s%s%s%s", "Failed removing file: ", configPath, "\n", strerror(errno));
		return buffer;
	}

	/* Rename temp file as original file */
	if (rename(tmpConfigName, configName)) {
		snprintf(buffer, bufSize, "%s%s%s%s", "Failed renaming file: ", configPath, "\n", strerror(errno));
		return buffer;
	}

	return "success writing config file";
}

char* readFromConfig(char* key, char* buffer, size_t bufSize) {
	if ((fptr = fopen(configPath, "r")) == NULL) {
		snprintf(buffer, bufSize, "%s%s%s%s", "Failed opening file: ", configPath, "\n", strerror(errno));
		return buffer;
	}

	//search for key and return its value
	char line[128];
	while (fgets(line, sizeof(line), fptr) != NULL) { //maybe add error message 
		if (strtok(line, search) == key) {
			buffer = strtok(NULL, search);
			fclose(fptr);
			return buffer;
		}
	}
	fclose(fptr);
	//return NULL if key is not existing in cofig file
	return NULL;
}

void setPluginFolderPath(char* pluginPath) {
	//set config path
	strcpy(configPath, pluginPath);
	strcat(configPath, configName);

	//set tmpConfig path
	strcpy(tmpConfigPath, pluginPath);
	strcat(tmpConfigPath, tmpConfigName);
}

/**
 * Replace all occurrences of a given a word in string.
 */
void replaceAll(char* str, const char* oldWord, const char* newWord)
{
	char* pos, temp[1000];
	int index = 0;
	int owlen;

	owlen = strlen(oldWord);

	// Fix: If oldWord and newWord are same it goes to infinite loop
	if (!strcmp(oldWord, newWord)) {
		return;
	}


	/*
	 * Repeat till all occurrences are replaced.
	 */
	while ((pos = strstr(str, oldWord)) != NULL)
	{
		// Backup current line
		strcpy(temp, str);

		// Index of current found word
		index = pos - str;

		// Terminate str after word found index
		str[index] = '\0';

		// Concatenate str with new word 
		strcat(str, newWord);

		// Concatenate str with remaining words after 
		// oldword found index.
		strcat(str, temp + index + owlen);
	}
}

//char* writeConfig(const char* new_api_key, char* buffer, size_t bufSize) {
//	if ((fptr = fopen(configPath, "wt")) == NULL) {
//		snprintf(buffer, bufSize, "%s%s%s%s", "Failed creating file: ", configPath, "\n", strerror(errno));
//		return buffer;
//	}
//	if (fprintf(fptr, "%s", new_api_key) < 0) {
//		snprintf(buffer, bufSize, "%s%s%s%s", "Failed writing file: ", configPath, "\n", strerror(errno));
//		return buffer;
//	}
//	fclose(fptr);
//	return "success writing config file";
//}
//
//char* readConfig(char* buffer, size_t bufSize) {
//	if ((fptr = fopen(configPath, "rt")) == NULL) {
//		snprintf(buffer, bufSize, "%s%s%s%s", "Failed to open file: ", configPath, "\n", strerror(errno));
//		return buffer;
//	}
//	if ((fgets(buffer, bufSize, fptr)) == NULL) {
//		snprintf(buffer, bufSize, "%s%s%s%s", "Failed to read file: ", configPath, "\n", strerror(errno));
//		fclose(fptr);
//		return buffer;
//	}
//	fclose(fptr);
//	return buffer;
//}