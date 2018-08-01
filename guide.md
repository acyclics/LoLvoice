# General
LoLvoice can convert what you speak into your microphone to League of Legend's in-game chat. Essentially, you speak into your microphone and LoLvoice "types" what you spoke into LoL's in-game chat, basically voice chat! But, its usage is restricted to in-game and it is not recommended to use LoLvoice in other places.

# Usage
The first time you use LoLvoice, it will prompt you to enter the path of LoLvoice folder. You can simply leave it at the default path and press "Set Path".

Then, you should see a screen that allows you to choose modes. LoLvoice have three modes: Sphinx, IBM_STT, and Overdrive. I shall proceed to describe each one in detail.

### Sphinx
Sphinx mode uses the pocketsphinx decoder to transcript your speech to text. Its accuracy varies from person to person so it is recommended for you to give it a try before using any other modes. Unlike the other two modes, Sphinx mode works right out of the box. To configure the settings, click the gear icon. There, you can change the keybind -- press the keybind and the program will record your speech from your microphone, and on release of the keybind "type" into League of Legend's in-game chat what you spoke (the exact wording may vary from a little to a lot). So, just plug in a microphone press "Start", get in-game, and enjoy the voice chat function.

Sphinx mode also has an adaptor, meaning it can adapt to your voice. It can be accessed by clicking the gear icon. Simply follow the instructions provided by the adaptor. The effect of the adaptor again varies from person to person.

The best part about Sphinx mode is that it contain League of Legends' related words. For example, it can recognize and transcript champion names, item names, etc.

### IBM-STT
IBM-STT mode uses IBM's Watson Speech-to-Text cloud API to transcript speech to text. It has very high accuracy regardless of who's using it as they have a lot of data. To use this mode, you will first have to create an account here: [IBM](https://www.ibm.com/account/reg/us-en/signup?formid=urx-19776&target=https%3A//idaas.iam.ibm.com/idaas/oidc/endpoint/default/authorize%3Fclient_id%3DZTdhOWU4MmQtOTA1MC00%26scope%3Dopenid%26state%3D115ef229-6ef0-4c2a-9053-d85ebe8e683f%26nonce%3Dd352c24d-c9df-4ef3-bed2-83cf1d3b6d1f%26response_type%3Dcode%26redirect_uri%3Dhttps%253A//iam-id-2.au-syd.bluemix.net/oidc/callback/IBMid). The account is free to create and use. However, it has a limit to the number of characters it can transcript per month. But, unless you talk a lot lot, it should be enough for communication in-game.

After you created the account, click the gear icon in LoLvoice and you should see input fields for username and password. Both of these are provided by IBM after you have created your account so input these and press "confirm". Allow time for LoLvoice to register your username and password, then you can press "start" and begin voice chatting.

Note that on first use, an error will pop-up stating it failed to connect to IBM. This is because you haven't enter the username and password yet, hence the error. You can ignore it and go on ahead with entering the username and password.

Unlike Sphinx mode, IBM-STT mode does not contain lol-related words.

### Overdrive
Overdrive mode is a combination of Sphinx mode and IBM-STT. This is provided so that you can combine the merits of both modes. Because of Sphinx's varying accuracy, it is better suited for short phrases and since it has unlimited usage, you might prefer using Sphinx mode for speaking a few words. Furthermore, Sphinx mode can transcript lol-related words. On the other hand, IBM-STT mode has very high accuracy and is better suited for long phrases; however, it has limited usage per month (which honestly, should be enough) nor can it transcript lol-related words. By combining the two modes, the user can get the best of both worlds, so to speak, and use the two different modes by using two different keybinds. For example, they can press "x" to use sphinx mode's transcriptor or press "g" to use IBM-STT's transcriptor.

If you want to use Overdrive, you must press the gear icon and change the keybinds, lest you use the same keybind for both transcriptor, resulting in two transcriptions.

### Verdict
Personally, I would recommend IBM-STT mode. The setup is not that difficult and its accuracy is simply much higher than sphinx (big coorperation = big accuracy). The inability to transcript lol-related words should not be a big issue since the amount of words that exists only in League of Legends is limited. For example, "Blade of the ruined King" is composed of multiple words that many people know exists. Also, you wouldn't have to fear running out of transcriptions for that month either as its limit is very high. Your usage is also refreshed each month since the limit is on a per-month basis.

Regarding Overdrive mode, I think its usage is complicated which strips away the convenience a "voice chat" program should bring. Then again, if Sphinx mode works fine for you for short phrases and you want to use IBM-STT mode for long phrases, I think Overdrive mode might be the right mode in your case.
