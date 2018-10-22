/*
	Logic for Scale Generator:

	There is an array of 12 elements, for each note in the 12-tone scale:
	[ A, A#, B, C, C#, D, D#, E, F, F#, G, G#]
	  0,  1, 2, 3,  4, 5,  6, 7, 8, 9, 10, 11

	Whole Tone:		(notes[index] + 2) % 12
	Half Tone:		(notes[index] + 1) % 12

	8-Tone Scales:
		Ionian:		root, WT, WT, HT, WT, WT, WT, HT	(C D E F G A B C)
		Dorian:		root, WT, HT, WT, WT, WT, HT, WT	(D E F G A B C D)
		Phyrgian:	root, HT, WT, WT, WT, HT, WT, WT	(E F G A B C D E)
		Lydian:		root, WT, WT, WT, HT, WT, WT, HT	(F G A B C D E F)
		Mixolydian:	root, WT, WT, HT, WT, WT, HT, WT	(G A B C D E F G)
		Aeolian:	root, WT, HT, WT, WT, HT, WT, WT	(A B C D E F G A)
		Locrian:	root, HT, WT, WT, HT, WT, WT, WT	(B C D E F G A B)

	(Add Pentatonic Scales)
	(Add Diminished Scales)
	(Add Phrygian Dominant Scales)
	(Add Bebop Sclaes)
	(Add Melodic Minor Scale)
*/
#include "Scales.h"

int* ionian(int root) {
	int * scale = new int[8];

	scale[0] = root;
	scale[1] = (root + 2) % 12;
	scale[2] = (scale[1] + 2) % 12;
	scale[3] = (scale[2] + 1) % 12;
	scale[4] = (scale[3] + 2) % 12;
	scale[5] = (scale[4] + 2) % 12;
	scale[6] = (scale[5] + 2) % 12;
	scale[7] = (scale[6] + 1) % 12;

	return scale;
}

int* dorian(int root) {
	int * scale = new int[8];

	scale[0] = root;
	scale[1] = (root + 2) % 12;
	scale[2] = (scale[1] + 1) % 12;
	scale[3] = (scale[2] + 2) % 12;
	scale[4] = (scale[3] + 2) % 12;
	scale[5] = (scale[4] + 2) % 12;
	scale[6] = (scale[5] + 1) % 12;
	scale[7] = (scale[6] + 2) % 12;

	return scale;
}

int* phyrgian(int root) {
	int * scale = new int[8];

	scale[0] = root;
	scale[1] = (root + 1) % 12;
	scale[2] = (scale[1] + 2) % 12;
	scale[3] = (scale[2] + 2) % 12;
	scale[4] = (scale[3] + 2) % 12;
	scale[5] = (scale[4] + 1) % 12;
	scale[6] = (scale[5] + 2) % 12;
	scale[7] = (scale[6] + 2) % 12;

	return scale;
}

int* lydian(int root) {
	int * scale = new int[8];

	scale[0] = root;
	scale[1] = (root + 2) % 12;
	scale[2] = (scale[1] + 2) % 12;
	scale[3] = (scale[2] + 2) % 12;
	scale[4] = (scale[3] + 1) % 12;
	scale[5] = (scale[4] + 2) % 12;
	scale[6] = (scale[5] + 2) % 12;
	scale[7] = (scale[6] + 1) % 12;

	return scale;
}

int* mixolydian(int root) {
	int * scale = new int[8];

	scale[0] = root;
	scale[1] = (root + 2) % 12;
	scale[2] = (scale[1] + 2) % 12;
	scale[3] = (scale[2] + 1) % 12;
	scale[4] = (scale[3] + 2) % 12;
	scale[5] = (scale[4] + 2) % 12;
	scale[6] = (scale[5] + 1) % 12;
	scale[7] = (scale[6] + 2) % 12;

	return scale;
}

int* aeolian(int root) {
	int * scale = new int[8];

	scale[0] = root;
	scale[1] = (root + 2) % 12;
	scale[2] = (scale[1] + 1) % 12;
	scale[3] = (scale[2] + 2) % 12;
	scale[4] = (scale[3] + 2) % 12;
	scale[5] = (scale[4] + 1) % 12;
	scale[6] = (scale[5] + 2) % 12;
	scale[7] = (scale[6] + 2) % 12;

	return scale;
}

int* locrian(int root) {
	int * scale = new int[8];

	scale[0] = root;
	scale[1] = (root + 1) % 12;
	scale[2] = (scale[1] + 2) % 12;
	scale[3] = (scale[2] + 2) % 12;
	scale[4] = (scale[3] + 1) % 12;
	scale[5] = (scale[4] + 2) % 12;
	scale[6] = (scale[5] + 2) % 12;
	scale[7] = (scale[6] + 2) % 12;

	return scale;
}