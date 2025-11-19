all: simple-client classic-client

simple-client: simple-client.c
	gcc -O2 -g -Wno-deprecated-declarations -I/usr/local/include/liquid simple-client.c -o simple-client -ljack -lliquid

classic-client: classic-client.c
	gcc -O2 -g classic-client.c -o classic-client -ljack

run:
	LD_LIBRARY_PATH=/usr/local/lib pw-jack ./simple-client

runclassic:
	pw-jack ./classic-client

linkports:
	pw-link simple:output_left alsa_output.platform-soc_sound.stereo-fallback:playback_FL
	pw-link simple:output_right alsa_output.platform-soc_sound.stereo-fallback:playback_FR
	pw-link alsa_input.platform-soc_sound.stereo-fallback:capture_FL simple:input_left
	pw-link alsa_input.platform-soc_sound.stereo-fallback:capture_FR simple:input_right

clean:
	rm -f *~ simple-client classic-client

include ../scripts/pipewire.mk
