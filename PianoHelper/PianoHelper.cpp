// PianoHelper.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Chords.h"

#include <iostream>
using namespace std;

char notes[] = { 'A', 'a', 'B', 'C', 'c', 'D', 'd', 'E', 'F', 'f', 'G', 'g' };

int main()
{
	int * arr = maj7(3);
	int i;
	for (i = 0; i < 4; i++) {
		cout << notes[arr[i]] << endl;
	}

	return 0;
}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

