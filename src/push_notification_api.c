#define CURL_STATICLIB
#include <string.h>
#include <Curl/curl.h>
#include "push_notification_api.h"


char* call_api(const char* api_key, const char* pokerName, const char* message) {

	CURL* curl;
	CURLcode res;

	curl = curl_easy_init();

	/* escape the strings for the API call */
	char url[MAX_MESSAGE_SIZE];
	char *esc_name = curl_easy_escape(curl, pokerName, 0);
	char *esc_message = curl_easy_escape(curl, message, 0);

	/* string builder */
	snprintf(
		url,
		sizeof(url),
		"%s%s%s%s%s%s",
		"http://xdroid.net/api/message?k=",
		api_key,
		"&t=",
		esc_name,
		"&c=",
		esc_message);
	curl_free(esc_name);
	curl_free(esc_message);


	char errbuf[CURL_ERROR_SIZE];
	curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
	curl_easy_setopt(curl, CURLOPT_URL, url);
	curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
	curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
	struct curl_slist* headers = NULL;
	curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
	const char* data = "";
	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
	curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, errbuf);
	res = curl_easy_perform(curl);

	if (res == CURLE_OK) {
		return "success";
	}
	else {
		return errbuf;
	}
	curl_easy_cleanup(curl);
}