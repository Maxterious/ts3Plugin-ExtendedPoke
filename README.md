# ts3Plugin-ExtendedPoke
This plugin forwards your received Teamspeak3 poke messages to your Android phone


# Installation

Download the extendedPoke DLL from the "release" folder  
Insert the DLL into the Teamspeak3 plugin folder  
(Default path: Windows Key + R -> %appdata% -> TS3Client -> plugins)

Download the "Simple Push Notification API" app from the Play Store:  
 https://play.google.com/store/apps/details?id=net.xdroid.pn&hl=en&gl=US

 Open this app, and you will see a field that holds "Your API KEY"

 Start your Teamspeak3 client and activate the extendedPoke plugin.  
 (If it is already active, deactivate and re-activate it)  

 You should see a "Plugins" options in the top menu bar.  
 Click it and navigate to extendedPoke -> set API key  

 You should see a log message in your chat window that says: "Type your API key into the chat"  
 Type the API key, which you got from the previously installed app, in the chat.  
 (Tip: go to a channel where you are alone and type your API key into the chat of this room. This way, nobody will see your API key)  

 After pressing enter, you should see a new log message: "Your API key is now set to: *your input*"  
 If this is the case, the plugin is all set :)

 If you receive any poke messages, you should get a notification on your phone!  

# How does it work?

This plugin uses the official plugin SDK provided from teamspeak. Via this sdk it is possible to get the poker and content of it. This gets converted into a URL and sent to a third party API.  
  (URL pattern: http://xdroid.net/api/message?k={API_key}&t={pokerName}c={message})  
Via the API_key it is connected to your mobile application, and you will get a push notification to your phone

 # Security
 Do not send sensitive data via this plugin. The API is third party software, so I can not confirm that your data is handled safely.

  # ToDo
- Add QT-UI
- More customization(e.g. only active after being X minutes AFK, log font colour, white/blacklist user)
- Write own API & App
