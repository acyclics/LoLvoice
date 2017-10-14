#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <pocketsphinx.h>
#include <sphinxbase/ad.h>
#include <sphinxbase/err.h>
#include <modules.h>

using namespace std;

// For recording speaker microphone input into RAW audio file -- to adapt speaker to Sphinx

string recognize_from_microphone();

ps_decoder_t *ps;                  // create pocketsphinx decoder structure
cmd_ln_t *config;                  // create configuration structure
ad_rec_t *ad;                      // create audio recording structure - for use with ALSA functions

int16 adbuf[4096];                 // buffer array to hold audio data
uint8 utt_started, in_speech;      // flags for tracking active speech - has speech started? - is speech currently happening?
int32 k;                           // holds the number of frames in the audio buffer
char const *hyp;                   // pointer to "hypothesis" (best guess at the decoded result)
#define MODELDIR "F:/Sphinx/PocketSphinx/pocketsphinx/model"

int main(int argc, char *argv[]) {

	config = cmd_ln_init(NULL, ps_args(), TRUE,                   // Load the configuration structure - ps_args() passes the default values
		"-hmm", MODELDIR "/en-us/en-us",              // path to the standard english language model
		"-lm", MODELDIR "/en-us/en-us.lm.bin",                                         // custom language model (file must be present)
		"-dict", MODELDIR "/en-us/cmudict-en-us.dict",	  // custom dictionary (file must be present)  
		"-logfn", "/dev/null",                                      // suppress log info from being sent to screen
		NULL);

	ps = ps_init(config);                                                        // initialize the pocketsphinx decoder
	ad = ad_open_dev("sysdefault", (int)cmd_ln_float32_r(config, "-samprate")); // open default microphone at default samplerate

	while (1) {
		string decoded_speech = recognize_from_microphone();          // call the function to capture and decode speech           
		cout << "Decoded Speech: " << decoded_speech << "\n" << endl;   // send decoded speech to screen
	}

	ad_close(ad);                                                    // close the microphone
}

string recognize_from_microphone() {

	ad_start_rec(ad);                                // start recording
	ps_start_utt(ps);                                // mark the start of the utterance
	utt_started = FALSE;                             // clear the utt_started flag

	while (1) {
		k = ad_read(ad, adbuf, 4096);                // capture the number of frames in the audio buffer
		ps_process_raw(ps, adbuf, k, FALSE, FALSE);  // send the audio buffer to the pocketsphinx decoder

		in_speech = ps_get_in_speech(ps);            // test to see if speech is being detected

		if (in_speech && !utt_started) {             // if speech has started and utt_started flag is false                            
			utt_started = TRUE;                      // then set the flag
		}

		if (!in_speech && utt_started) {             // if speech has ended and the utt_started flag is true 
			ps_end_utt(ps);                          // then mark the end of the utterance
			ad_stop_rec(ad);                         // stop recording
			hyp = ps_get_hyp(ps, NULL);             // query pocketsphinx for "hypothesis" of decoded statement
			return hyp;                              // the function returns the hypothesis
			break;                                   // exit the while loop and return to main
		}
	}

}