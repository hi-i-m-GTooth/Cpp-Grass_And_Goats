/* Copyright (c) 1998 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     ALifeTest.cc
   PURPOSE
     
   NOTES
     
   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Nov 29, 1998: Created.
***************************************************************************/

/* $Log: ALifeTest.cc,v $
 * Revision 1.1  1998/11/30 01:58:55  li
 * Initial revision
 * */

extern "C" {
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>
}

using namespace std;
#include <iostream>
#include "AnsiPrint.h"
#include "World.h"


/**
 * PrintUsage
 */

void
PrintUsage(const char *progName) {

    assert(progName);
    cout << "Usage: " << progName << " [passes [display [seed]]]" << endl;

}

int
main(int argc, char **argv) {

    int seed=(unsigned)time(NULL);
    int numPasses=1;
    int displayInterval=1;

	if (argc>4) {
		PrintUsage(argv[0]);
		return -1;
	} else if (argc==4) {
		seed = atoi(argv[3]);
	}
	if (argc>2) {
		displayInterval=atoi(argv[2]);
	}
	if (argc>1) {
		if(atoi(argv[1])>0)
			numPasses = atoi(argv[1]);
	}

	World fate(numPasses,seed);

	fate.mainLoop(displayInterval);

	return 0;
    
}
