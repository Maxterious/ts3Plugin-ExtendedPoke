#pragma once

/* Teamspeak pokes only allow up to 100 characters (not sure about API restrictions) */
#define MAX_MESSAGE_SIZE 10000

/* Send message function, detailed in push_notification_api.c */
char* call_api(char* api_key, char* pokerName, char* message);

/* convert a string into a URL encoded string */
char* get_encoded_string(char* string_to_encode);