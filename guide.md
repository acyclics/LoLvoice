# General
LoLvoice can convert what you speak into your microphone to League of Legend's in-game chat. Essentially, you speak into your microphone and LoLvoice "types" what you spoke into LoL's in-game chat, basically voice chat! But, its usage is restricted to in-game and it is not recommended to use LoLvoice in other places. It is also recommended for you to run League of Legends in full-screen mode.


# Usage
LoLvoice requires administrator permission.

The first time you use LoLvoice, it will prompt you to enter the path of LoLvoice folder. You can simply leave it at the default path and press "Set Path".

Then, you should see a screen that allows you to choose modes. LoLvoice have three modes: Sphinx, IBM_STT, and Overdrive. I shall proceed to describe each one in detail. Note that all three modes are used the same way:

1. You press and hold a changeable keybind
2. You speak into your microphone
3. You release the keybind
4. LoLvoice "types" into LoL's in-game chat

### Sphinx
Sphinx mode uses the pocketsphinx decoder to transcript your speech to text. Its accuracy varies from person to person so it is recommended for you to give it a try before using any other modes. Unlike the other two modes, Sphinx mode works right out of the box. To configure the settings, click the gear icon. There, you can change the keybind -- press the keybind and the program will record your speech from your microphone, and on release of the keybind "type" into League of Legend's in-game chat what you spoke (the exact wording may vary from a little to a lot). So, just plug in a microphone press "Start", get in-game, and enjoy the voice chat function.

There are two different ways you can use Sphinx mode. The first is called "Block" and the second "Spread". You can choose between these two different methods at "Output mode" after you clicked the gear icon (simply press "switch"). Block method, as shown in this video: [youtube](https://www.youtube.com/watch?v=gwk06iH6TSk), "types" your speech in one sentence. On the other hand, Spread method, as shown in this video: [youtube](https://www.youtube.com/watch?v=iH-U0WcawBk), "types" your speech in multiple chunks.

Sphinx mode also has an adaptor, meaning it can adapt to your voice. It can be accessed by clicking the gear icon. Simply follow the instructions provided by the adaptor. The effect of the adaptor again varies from person to person.

The best part about Sphinx mode is that it contain League of Legends' related words. For example, it can recognize and transcript champion names, item names, etc.

### IBM-STT
IBM-STT mode uses IBM's Watson Speech-to-Text cloud API to transcript speech to text. It has very high accuracy regardless of who's using it as they have a lot of data. To use this mode, you will first have to create an account here: [IBM](https://console.bluemix.net/registration/?target=%2Fcatalog%2Fservices%2Fspeech-to-text%3FhideTours%3Dtrue%26-_-Watson%2BCore_Watson%2BCore%2B-%2BPlatform-_-WW_WW-_-wdc-ref%26-_-Watson%2BCore_Watson%2BCore%2B-%2BPlatform-_-WW_WW-_-wdc-ref%26cm_mmca1%3D000000OF%26cm_mmca2%3D10000409&cm_mc_uid=99138951242315297549410&cm_mc_sid_50200000=42778731533448248875&cm_mc_sid_52640000=30373961533448248877). The account is free to create and use. However, it has a duration limit to the length it can transcript per month. But, unless you talk a lot lot, it should be enough for communication in-game. IBM-STT also has a limit to the size of the audio sent to their servers for transcription, meaning the amount of words you can transcript per transcription is limited. So, try to cut what you want to say into a few sentences.

If the account creation process or the instructions below are hard to follow, here is a guide to creating an IBM account and using it in LoLvoice: [ibm account creation and implementation guide](https://github.com/impeccableaslan/LoLvoice/blob/master/createIBMaccountguide/README.md).

After you created the account, click the gear icon in LoLvoice and you should see input fields for username and password. Both of these are provided by IBM after you have created your account. Note that what we are looking for here is not the username and password of your ibm account but the credentials to use their API. If you don't know what these credentials are, read this: [ibm account creation and implementation guide](https://github.com/impeccableaslan/LoLvoice/blob/master/createIBMaccountguide/README.md). After you got the credentials, input it into LoLvoice input fields for username and password, then press "confirm". Allow time for LoLvoice to register your username and password, then you can press "start" and begin voice chatting.

Note that on first use, an error will pop-up stating it failed to connect to IBM. This is because you haven't enter the username and password yet, hence the error. You can ignore it and go on ahead with entering the username and password.

Similar to Sphinx mode, there are two different ways you can use IBM-STT mode. The first is called "Block" and the second "Spread". You can choose between these two different methods at "Output mode" after you clicked the gear icon (simply press "switch"). Block method, as shown in this video: [youtube](https://www.youtube.com/watch?v=gwk06iH6TSk), "types" your speech in one sentence. On the other hand, Spread method, as shown in this video: [youtube](https://www.youtube.com/watch?v=iH-U0WcawBk), "types" your speech in multiple chunks.

Unlike Sphinx mode, IBM-STT mode does not contain lol-related words. Also, due to IBM's system, repeating the same words over and over (ex. "testing testing testing") will only result in the transcription of one iteration (ex. "testing").

### Overdrive
Overdrive mode is a combination of Sphinx mode and IBM-STT. This is provided so that you can combine the merits of both modes. Because of Sphinx's varying accuracy, it is better suited for short phrases and since it has unlimited usage, you might prefer using Sphinx mode for speaking a few words. Furthermore, Sphinx mode can transcript lol-related words. On the other hand, IBM-STT mode has very high accuracy and is better suited for long phrases; however, it has limited usage per month (which honestly, should be enough) nor can it transcript lol-related words. By combining the two modes, the user can get the best of both worlds, so to speak, and use the two different modes by using two different keybinds. For example, they can press "x" to use sphinx mode's transcriptor or press "g" to use IBM-STT's transcriptor.

If you want to use Overdrive, you must press the gear icon and change the keybinds, lest you use the same keybind for both transcriptor, resulting in two transcriptions.

# Verdict
Personally, I would recommend IBM-STT mode. The setup is not that difficult and its accuracy is simply much higher than sphinx (big coorperation = big accuracy). The inability to transcript lol-related words should not be a big issue since the amount of words that exists only in League of Legends is limited. For example, "Blade of the ruined King" is composed of multiple words that many people know exists. Also, you wouldn't have to fear running out of transcriptions for that month either as its limit is very high. Your usage is also refreshed each month since the limit is on a per-month basis.

Regarding Overdrive mode, I think its usage is complicated which strips away the convenience a "voice chat" program should bring. Then again, if Sphinx mode works fine for you for short phrases and you want to use IBM-STT mode for long phrases, I think Overdrive mode might be the right mode in your case.

# Things to note
- Since LoLvoice basically simulate keystrokes, refrain from doing anything that would close LoL's in-game chat such as left-clicking (you can still right-click to move your character) or pressing the "escape" button. For users that might have switched their controls from the default, understand that you can still move your character when "typing" with LoLvoice.

- I found running LoL in full-screen mode betters the experience of using LoLvoice.

- If you had used LoLvoice, you would've noticed that sentences are divided into multiple phrases. This is done on purpose, both to prevent the user from mistakenly type into chat while casting abilities and to reduce CPU usage.

# Known bug(s)
1. With the latest update to LoLvoice, I can no longer reproduce this bug but when I was testing the old LoLvoice, in a few rare cases I was not be able to cast any champion abilities after LoLvoice "types", the cause of which seems to be LoL's in-game chat remaining opened invisibly even when manually closed. This means any abilities you cast will be interpreted by LoL as typing into the invisible chat. I don't know whether this bug still exists but if this happens, simply press your "escape" button (so as to close the invisible LoL's in-game chat) and everything will be fine.
