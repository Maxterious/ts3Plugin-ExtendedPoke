#pragma once

//set path for the config file
void setPluginFolderPath(char* pluginPath);

//function that writes given key value pair to the config file
char* writeToConfig(char* key, char* value, char* buffer, size_t bufSize);

//function that reads given value from the config file

char* readFromConfig(char* key, char* buffer, size_t bufSize);


char* checkForError(char* err_msg, char* filePath, char* buffer, size_t bufSize);

char* checkForErrorClosePtr(char* err_msg, char* filePath, char* buffer, size_t bufSize, FILE* ptrToClose);

//helper function to replace strings
void replaceAll(char* str, const char* oldWord, const char* newWord);