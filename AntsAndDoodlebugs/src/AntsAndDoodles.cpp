//============================================================================
// Name        : AntsAndDoodles.cpp
// Author      : Suryansh Goyal
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>
#include "Tests2.h"
#include "Production.h"
class Tests;
class Production;


int main(int argc, char* argv[])
{//gridSize #doodlebugs #ants #time_steps seed pause

	std::cout << "!!!Hello the classmates, it's time for fun with C++!!!" << std::endl;
    Tests2 ts = Tests2();//see page 291
    if(ts.doTests())
	{
    	std::cout << "All tests done!" << std::endl;
		Production ps = Production(argc, argv);
		if (ps.seed == 0) {
			time_t t = time(0); // get the current time
			srand(t); // use it as the seed
		} else {
			srand(ps.seed); // Otherwise, use the seed from the command line
		}

		//srand(time(ps.seed));

		bool ok = ps.runProduction();
		if(ok)
		{
			puts("Production worked.");
		}
		else
		{
			puts("Production did not work.");
		}
		ps.~Production(); //done with production
	}
    else{
    	puts("Tests Failed!");
    }
    ts.~Tests2(); //done with tests


	return 0;
}
