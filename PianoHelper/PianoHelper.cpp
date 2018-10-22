#include "pch.h"
#include "Chords.h"
#include "Scales.h"

#include <iostream>
using namespace std;

char notes[] = { 'A', 'a', 'B', 'C', 'c', 'D', 'd', 'E', 'F', 'f', 'G', 'g' };

int main()
{
	int * arr = aeolian(0);
	int i;
	for (i = 0; i < 8; i++) {
		switch (arr[i]) {
		case 1:
			cout << "A#" << endl;
			continue;
		case 4:
			cout << "C#" << endl;
			continue;
		case 6:
			cout << "D#" << endl;
			continue;
		case 9:
			cout << "F#" << endl;
			continue;
		case 11: 
			cout << "G" << endl;
			continue;
		}
		cout << notes[arr[i]] << endl;
	}

	return 0;
}
