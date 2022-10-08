/*
 * TeamSpeak 3 demo plugin
 *
 * Copyright (c) TeamSpeak Systems GmbH
 */

#pragma once

#if defined(WIN32) || defined(__WIN32__) || defined(_WIN32)
#define PLUGINS_EXPORTDLL __declspec(dllexport)
#else
#define PLUGINS_EXPORTDLL __attribute__ ((visibility("default")))
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Required functions */
PLUGINS_EXPORTDLL const char* ts3plugin_name();
PLUGINS_EXPORTDLL const char* ts3plugin_version();
PLUGINS_EXPORTDLL int ts3plugin_apiVersion();
PLUGINS_EXPORTDLL const char* ts3plugin_author();
PLUGINS_EXPORTDLL const char* ts3plugin_description();
PLUGINS_EXPORTDLL void ts3plugin_setFunctionPointers(const struct TS3Functions funcs);
PLUGINS_EXPORTDLL int ts3plugin_init();
PLUGINS_EXPORTDLL void ts3plugin_shutdown();

/* Optional functions */
PLUGINS_EXPORTDLL int ts3plugin_offersConfigure();
PLUGINS_EXPORTDLL void ts3plugin_configure(void* handle, void* qParentWidget);
PLUGINS_EXPORTDLL void ts3plugin_registerPluginID(const char* id);
PLUGINS_EXPORTDLL void ts3plugin_freeMemory(void* data);
PLUGINS_EXPORTDLL int ts3plugin_requestAutoload();
PLUGINS_EXPORTDLL void ts3plugin_initMenus(struct PluginMenuItem*** menuItems, char** menuIcon);

/* Clientlib */
PLUGINS_EXPORTDLL int  ts3plugin_onTextMessageEvent(uint64 serverConnectionHandlerID, anyID targetMode, anyID toID, anyID fromID, const char* fromName, const char* fromUniqueIdentifier, const char* message, int ffIgnored);
PLUGINS_EXPORTDLL void ts3plugin_onUserLoggingMessageEvent(const char* logMessage, int logLevel, const char* logChannel, uint64 logID, const char* logTime, const char* completeLogString);

/* Clientlib rare */
PLUGINS_EXPORTDLL int  ts3plugin_onClientPokeEvent(uint64 serverConnectionHandlerID, anyID fromClientID, const char* pokerName, const char* pokerUniqueIdentity, const char* message, int ffIgnored);

/* Client UI callbacks */
PLUGINS_EXPORTDLL void ts3plugin_onMenuItemEvent(uint64 serverConnectionHandlerID, enum PluginMenuType type, int menuItemID, uint64 selectedItemID);
PLUGINS_EXPORTDLL void ts3plugin_onHotkeyEvent(const char* keyword);
PLUGINS_EXPORTDLL void ts3plugin_onHotkeyRecordedEvent(const char* keyword, const char* key);
PLUGINS_EXPORTDLL void ts3plugin_onClientDisplayNameChanged(uint64 serverConnectionHandlerID, anyID clientID, const char* displayName, const char* uniqueClientIdentifier);
PLUGINS_EXPORTDLL const char* ts3plugin_keyDeviceName(const char* keyIdentifier);
PLUGINS_EXPORTDLL const char* ts3plugin_displayKeyText(const char* keyIdentifier);
PLUGINS_EXPORTDLL const char* ts3plugin_keyPrefix();

#ifdef __cplusplus
}
#endif