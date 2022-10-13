#include <stdio.h>
#include "config.h"
#include <errno.h>
#include "ts3_functions.h"
#include <string.h>

static struct TS3Functions ts3Functions;

FILE* fptr;
const char filename[] = "extendedPokeConfig.txt";


char* writeConfig(const char* new_api_key, char* buffer, size_t bufSize) {
	if ((fptr = fopen(filename, "wt")) == NULL) {
		snprintf(buffer, bufSize, "%s%s%s%s", "Failed creating file: ", filename, "\n", strerror(errno));
		return buffer;
	}
	if (fprintf(fptr, "%s", new_api_key) < 0) {
		snprintf(buffer, bufSize, "%s%s%s%s", "Failed writing file: ", filename, "\n", strerror(errno));
		return buffer;
	}
	fclose(fptr);
	return "success writing config file";
}

char* readConfig(char* buffer, size_t bufSize) {
	if ((fptr = fopen(filename, "rt")) == NULL) {
		snprintf(buffer, bufSize, "%s%s%s%s", "Failed to open file: ", filename, "\n", strerror(errno));
		return buffer;
	}
	if ((fgets(buffer, bufSize, fptr)) == NULL) {
		snprintf(buffer, bufSize, "%s%s%s%s", "Failed to read file: ", filename, "\n", strerror(errno));
		fclose(fptr);
		return buffer;
	}
	fclose(fptr);
	return buffer;
}

char* createErrorMessage(char* errorMessage) {

}