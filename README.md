# LoLvoice
An application that "types" into League of Legend's in-game chat what you speak into your microphone.
Currently available on Windows and is coded primarily in c/c++.
LoLvoice make use of open-source libraries and is itself open-source.


# Disclaimer
LoLvoice isn’t endorsed by Riot Games and doesn’t reflect the views or opinions of Riot Games or anyone officially involved in producing or managing League of Legends. League of Legends and Riot Games are trademarks or registered trademarks of Riot Games, Inc. League of Legends © Riot Games, Inc.

# Pre-requisites
The following softwares must be installed in order for LoLvoice to work:
1. [Microsoft Visual C++ 2015 Redistributable (x86)](https://www.microsoft.com/en-us/download/details.aspx?id=52685)
2. [Microsoft Build Tools 2015](https://www.microsoft.com/en-hk/download/details.aspx?id=48159)

Simply download the softwares in the above links and follow the provided instructions.

# Installation of LoLvoice with installer
1. Download "setup.exe" here: [download](https://github.com/impeccableaslan/LoLvoice/releases)
2. Following the instructions provided by the installer
3. Once installed, read the guide to use LoLvoice here:
4. Note that LoLvoice requires admin permission to operate

# Installation from source
Since LoLvoice is coded in Microsoft's visual studio 2015, the VS' Solution is provided to install with. But, there are a few dependencies required to build LoLvoice:
1. [sphinxbase](https://github.com/cmusphinx/sphinxbase)
2. [pocketsphinx](https://github.com/cmusphinx/pocketsphinx)
3. [curl](https://github.com/curl/curl)
Other non-library dependencies used are [IBM's Watson Speech-to-Text API](https://www.ibm.com/watson/services/speech-to-text/) and a few artworks from [Riot Games](https://www.riotgames.com/en) for League of Legends. Any licenses or credits for these dependencies can be found at [Licenses-Credits](https://github.com/impeccableaslan/LoLvoice/tree/master/Licenses-Credits).
