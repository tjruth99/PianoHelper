#pragma once

/*
	Logic For Chord Finder:

	There is an array of 12 elements, for each note in the 12-tone scale:
	[ A, A#, B, C, C#, D, D#, E, F, F#, G, G#]
	  0,  1, 2, 3,  4, 5,  6, 7, 8, 9, 10, 11

	Major Third:	notes[index+4] % 12
	Minor Third:	notes[index+3] % 12

	Chords based on triads (each triad is based on the previous note):
		Major	(root, majT, minT)							(C, E, G)
		Maj7	(root, majT, minT, majT)					(C, E, G, B)
		Maj9	(root, majT, minT, majT, minT)				(C, E, G, B, D)
		Maj11	(root, majT, minT, majT, minT, minT)		(C, E, G, B, D, F)
		Maj13	(root, majT, minT, majT, minT, minT, majT)	(C, E, G, B, D, F, A)

		Minor	(root, minT, majT)							(A, C, E)
		Min7	(root, minT, majT, minT)					(A, C, E, G)
		Min9	(root, minT, majT, minT, majT)				(A, C, E, G, B)
		Min11	(root, minT, majT, minT, majT, minT)		(A, C, E, G, B, D)
		Min11	(root, minT, majT, minT, majT, minT, minT)	(A, C, E, G, B, D, F)

	(Add Dominant Chords)
	(Add Diminished Chords)
	(Add Augmented Chords)
	(Add Suspended Chords)


*/

int * major(int root);
int * maj7(int root);
int * maj9(int root);
int * maj11(int root);
int * maj13(int root);

int * minor(int root);
int * min7(int root);
int * min9(int root);
int * min11(int root);
int * min13(int root);