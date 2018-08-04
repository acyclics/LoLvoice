# LoLvoice
An application that "types" into League of Legend's in-game chat what you spoke into your microphone. Basically voice chat for LoL.

Currently available on Windows and is coded primarily in C/C++.

Language: English

LoLvoice make use of open-source libraries and is itself open-source.

# Disclaimer
LoLvoice isn’t endorsed by Riot Games and doesn’t reflect the views or opinions of Riot Games or anyone officially involved in producing or managing League of Legends. League of Legends and Riot Games are trademarks or registered trademarks of Riot Games, Inc. League of Legends © Riot Games, Inc.

As with all LoL-related projects, use at your own risk. As a reassurance, I have sent a ticket to Riot Games asking for a confirmation of the validity of this project. Here is their response:

![alt text](https://raw.githubusercontent.com/impeccableaslan/LoLvoice/master/riotresponse.PNG)

LoLvoice, basically voice chat, doesn't automate the game (it doesn't play the game for you) and instead provides accessibility -- an option to communicate to players with in-game chat through your voice. Needless to say, LoLvoice is not a macro program either since you can't use it to "chain abilities" etc. Therefore, please be reassured that LoLvoice does not violate any policies and you are free to use it in your games to come.

# Pre-requisites
The following softwares must be installed in order for LoLvoice to work:
1. [Microsoft Visual C++ 2015 Redistributable (x86)](https://www.microsoft.com/en-us/download/details.aspx?id=52685)
2. [Microsoft Build Tools 2015](https://www.microsoft.com/en-hk/download/details.aspx?id=48159)

Simply download the softwares in the above links and follow the provided instructions.

# Installation of LoLvoice with installer
1. Download "setup.exe" here: [download](https://github.com/impeccableaslan/LoLvoice/releases)
2. Following the instructions provided by the installer
3. Once installed, read the guide to use LoLvoice here: [guide](https://github.com/impeccableaslan/LoLvoice/blob/master/guide.md)
4. Note that LoLvoice requires admin permission to operate

# Installation of LoLvoice from source
This method of installation should only be attempted by people who know what they are doing and have the tools to do so. Since LoLvoice is coded in Microsoft's visual studio 2015, the VS' Solution is provided to install with. But, there are a few dependencies required to build LoLvoice:
1. [sphinxbase](https://github.com/cmusphinx/sphinxbase)
2. [pocketsphinx](https://github.com/cmusphinx/pocketsphinx)
3. [curl](https://github.com/curl/curl)

Other non-library dependencies used are [IBM's Watson Speech-to-Text API](https://www.ibm.com/watson/services/speech-to-text/) and a few artworks from [Riot Games](https://www.riotgames.com/en) for League of Legends. Any licenses or credits for these dependencies can be found at [Licenses-Credits](https://github.com/impeccableaslan/LoLvoice/tree/master/Licenses-Credits).

Once you built those three dependencies, you will have to run your "Developer command prompt for VS" as administrator and create the paths to those dependencies in your system environmental variables:
1. Enter the following commands into the developer command prompt one by one (take care to change the paths)
```
setx -m SPHINX_BASE PATH-TO-SPHINXBASE
setx -m POCK_SPHINX PATH-TO-POCKETSPHINX
setx -m CURL_PATH PATH-TO-CURL
```
2. Then, build the solution with "Debug" configuration.

# How to use
Regarding the usage of LoLvoice, have a look at the guide here: [guide](https://github.com/impeccableaslan/LoLvoice/blob/master/guide.md)

In addition, I would recommend you to run League of Legends in full-screen mode.

# Language
The provided installer and source files are configured to transcript from English speech to English text. However, the source code can be configured to be used for other languages. Feel free to configure it yourself and if you did, please do contribute on Github. This apply to any improvements to the source code you can make. Contributions are encouraged and welcomed.

# Known bug(s)
1. With the latest update to LoLvoice, I can no longer reproduce this bug but when I was testing the old LoLvoice, in a few rare cases  I was not be able to cast any champion abilities after LoLvoice "types", the cause of which seems to be LoL's in-game chat remaining opened invisibly even when manually closed. This means any abilities you cast will be interpreted by LoL as typing into the invisible chat. I don't know whether this bug still exists but if this happens, simply press your "escape" button (so as to close the invisible LoL's in-game chat) and everything will be fine.
