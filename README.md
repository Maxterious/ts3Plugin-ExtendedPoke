# ts3Plugin-ExtendedPoke
This plugin forwards your received teamspeak3 poke messages to your android phone


# Installation

Download the extendedPoke DLL from the "release" folder  
Insert the DLL into the Teamspeak3 plugin folder  
(Default path: Windows Key + R -> %appdata% -> TS3Client -> plugins)

Download the "Simple Push Notification API" app from the Play Store:  
 https://play.google.com/store/apps/details?id=net.xdroid.pn&hl=en&gl=US

 Open this app and you will see a field which holds "Your API KEY"

 Start your teamspeak3 client and activate the extendedPoke plugin.  
 (If it is already active, deactivate and reanable it)  

 Now you should see a  "Pluigns" options in the top menu bar.  
 Click it and navigate to extendedPoke -> set API key  

 Now you should see a log message in your chat window which says "Type your API key into the chat"  
 Now type the API key, which you get from the previously installed app, in the chat.  
 (Tip: go to a channel where you are alone and type your API key into the chat of this room. This way nobody will see your API key)  

 After pressing enter, you should see a new log message which says: "Your API key is now set to: *your input*"  
 If this is the case, the plugin is all set :)

 If you recieve any poke message, you should get a notification on your phone!  

 # Security
 Do not send sensitive data via this plugin. The API is third party software, so I can not confirm that your data is handled safely.
