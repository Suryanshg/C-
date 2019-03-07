/*
 * Tests2.cpp
 *
 *  Created on: Feb 25, 2019
 *      Author: Suryansh Goyal
 */

#include "Tests2.h"
#include "Grid.h"
#include "Ant.h"
#include "Doodlebug.h"
#include <iostream>
#include "Cell.h"

/*
 * Tests2 Constructor
 */
Tests2::Tests2() {
	// TODO Auto-generated constructor stub
	//initialize the grid
}

/*
 * Performs all Tests
 * @return true if all pass, false otherwise
 */
bool Tests2::doTests()
{
	bool results;
	//establish a grid
	bool ok1 = gridTest();
	//populate it with ants
	bool ok2 = makeAntsTest();
	//see whether they move
	bool ok3 = antsMoveTest();
	//see whether they breed
	bool ok4 = antsBreedTest();
	//see whether they die?
	bool ok5 = antsDieTest();//maybe if they wander off?
	//populate with doodlebugs
	bool ok6 = makeDoodlesTest();
	//see whether they move
	bool ok7 = doodleMoveTest();
	//see whether they breed
	bool ok8 = doodleBreedTest();
	//see whether they eat ants
	bool ok9 = doodleEatTest();
	//see whether they die
	bool ok10 = doodleDietest();
	//see whether they move
	//bool ok31= antsMoveTest1();
	//bool ok71= doodleMoveTest1();
	results = ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8 && ok9 && ok10;
	return results;
}

/*
 * Test grid
 * return true if it passes, false otherwise
 */
bool Tests2::gridTest()
{
	bool result = true;
	bool ok1 = true;
	bool ok2 = true;
	std::cout << "Running the grid test" << std::endl;
	Grid myGrid = Grid(8);
	if(myGrid.getCellOccupant(2, 3)!=empty)
	{
		std::cout << "Cell not initially empty" << std::endl;
		ok1 = false;
	}
	//std::cout << "second grid test" << std::endl;
	myGrid.setCellOccupant(2, 3, ant);
	if(myGrid.getCellOccupant(2, 3)!=ant)
	{
		std::cout << "Cell not set to ant" << std::endl;
		ok2 = false;
	}
	//std::cout << "third grid test" << std::endl;
	myGrid.~Grid();
	result = ok1 && ok2;
	return result;
}

/*
 * Test Ant Constructor
 * return true if it passes, false otherwise
 */
bool Tests2::makeAntsTest()
{
	bool result = true;
	bool ok1 = true;
	bool ok2 = true;
	std::cout << "Running the make ants test" << std::endl;

	Grid* myGrid_p = new Grid(9);
	if(myGrid_p->getCellOccupant(1, 2)!=empty)
	{
		std::cout << "Cell 1,2 not initially empty" << std::endl;
	}
	myGrid_p->setCellOccupant(1, 2, ant);
	if(myGrid_p->getCellOccupant(1, 2)!=ant)
	{
		std::cout << "Cell not set to ant" << std::endl;
		ok1 = false;
	}
	Ant* a1 = new Ant(3,4);
	//myGrid_p->setCellOccupant(3, 4, ant);
	//std::cout <<myGrid_p->getCellOccupant(2,1)<<std::endl;
	if(myGrid_p->getCellOccupant(3, 4)!=empty)
	{
		std::cout << "Cell 3,4 not initially empty" << std::endl;
	}
	myGrid_p->setCellOccupant(3, 4, doodlebug);
	if(myGrid_p->getCellOccupant(3, 4)!=doodlebug)
	{
		std::cout << "Cell not set to doodlebug" << std::endl;
		ok2 = false;
	}
	myGrid_p->setCellOccupant(3, 4, empty);
	delete a1;
	delete myGrid_p;
	result = ok1 && ok2;
	return result;
}

/*
 * Test Move of Ant
 * return true if it passes, false otherwise
 */
bool Tests2::antsMoveTest()
{
	bool result = false;
	int ok1=0;


	std::cout << "Running the move ants test" << std::endl;
	Grid* myGrid_p=new Grid(3);

	myGrid_p->setCellOccupant(1, 1, ant);
	myGrid_p->getBoard()[1][1].NewPtr(1, 1, ant);
	myGrid_p->setCellOccupant(0, 1, ant);
	myGrid_p->getBoard()[0][1].NewPtr(0, 1, ant);
	myGrid_p->setCellOccupant(2, 1, ant);
	myGrid_p->getBoard()[2][1].NewPtr(2, 1, ant);
	myGrid_p->setCellOccupant(1, 0, ant);
	myGrid_p->getBoard()[1][0].NewPtr(1, 0, ant);
	//myGrid_p->setCellOccupant(1, 2, ant);

	ok1=myGrid_p->getBoard()[1][1].getPtr()->move(myGrid_p);
	//std::cout << myGrid_p->getCellOccupant(1, 1) << std::endl;


	result=ok1; //&& ok2;

	delete myGrid_p;
	return result;
}




/*
 * Test Breed of Ant
 * return true if it passes, false otherwise
 */
bool Tests2::antsBreedTest()
{
	bool result = true;
	std::cout << "Running the breed ants test" << std::endl;
	Grid* myGrid_p=new Grid(3);
	myGrid_p->setCellOccupant(0, 0, ant);
	myGrid_p->getBoard()[0][0].NewPtr(0, 0, ant);

	myGrid_p->setCellOccupant(1, 0, ant);
	myGrid_p->getBoard()[1][0].NewPtr(1, 0, ant);

	myGrid_p->setCellOccupant(1, 1, ant);
	myGrid_p->getBoard()[1][1].NewPtr(1, 1, ant);


	myGrid_p->getBoard()[0][0].getPtr()->move(myGrid_p);

	myGrid_p->getBoard()[0][1].getPtr()->move(myGrid_p);


	myGrid_p->setCellOccupant(0, 1, ant);
	myGrid_p->getBoard()[0][1].NewPtr(0, 1, ant);

	myGrid_p->getBoard()[0][2].getPtr()->move(myGrid_p);


	delete myGrid_p;

	return result;
}

/*
 * Test if the ant dies or not
 * return true if it passes, false otherwise
 */
bool Tests2::antsDieTest()
{
	bool result = true;
	std::cout << "Running the ants die test" << std::endl;
	Grid* myGrid_p=new Grid(3);
	myGrid_p->setCellOccupant(0, 0, ant);
	myGrid_p->getBoard()[0][0].NewPtr(0, 0, ant);
	myGrid_p->setCellOccupant(0, 1, doodlebug);
	myGrid_p->getBoard()[0][1].NewPtr(0, 1, doodlebug);
	myGrid_p->printGrid();
	myGrid_p->getBoard()[0][1].getPtr()->move(myGrid_p);
	myGrid_p->printGrid();
	delete myGrid_p;
	return result;
}

/*
 * Test constuctor of DoodleBug
 * return true if it passes, false otherwise
 */
bool Tests2::makeDoodlesTest()
{
	bool result = true;
	std::cout << "Running the make doodlebugs test" << std::endl;
	return result;
}

/*
 * Test if the doodle Moves
 * return true if it passes, false otherwise
 */
bool Tests2::doodleMoveTest()
{
	bool result = false;
	int ok1=0;
	std::cout << "Running the move doodlebugs test" << std::endl;

	Grid* myGrid_p=new Grid(3);

	myGrid_p->setCellOccupant(1, 1, doodlebug);
	myGrid_p->getBoard()[1][1].NewPtr(1, 1, doodlebug);
	myGrid_p->setCellOccupant(0, 1, doodlebug);
	myGrid_p->getBoard()[0][1].NewPtr(0, 1, doodlebug);
	myGrid_p->setCellOccupant(2, 1, doodlebug);
	myGrid_p->getBoard()[2][1].NewPtr(2, 1, doodlebug);
	myGrid_p->setCellOccupant(1, 0, doodlebug);
	myGrid_p->getBoard()[1][0].NewPtr(1, 0, doodlebug);
//	myGrid_p->setCellOccupant(1, 2, doodlebug);
//	myGrid_p->getBoard()[1][2].NewPtr(1, 2, doodlebug);
//	std::cout<<"Works"<<std::endl;
	ok1=myGrid_p->getBoard()[1][1].getPtr()->move(myGrid_p);

//	std::cout << d1->getCol() << std::endl;


	result=ok1; //&& ok2;
	delete myGrid_p;
	return result;
}



/*
 * Test Breed DoodleBug
 * return true if it passes, false otherwise
 */
bool Tests2::doodleBreedTest()
{
	bool result = true;
	std::cout << "Running the breed doodlebug test" << std::endl;
	Grid* myGrid_p=new Grid(4);

	myGrid_p->setCellOccupant(0, 0, doodlebug);
	myGrid_p->getBoard()[0][0].NewPtr(0, 0, doodlebug);

	myGrid_p->setCellOccupant(0, 1, ant);
	myGrid_p->getBoard()[0][1].NewPtr(0, 1, ant);

	myGrid_p->setCellOccupant(0, 2, ant);
	myGrid_p->getBoard()[0][2].NewPtr(0, 2, ant);

	myGrid_p->setCellOccupant(0, 3, ant);
	myGrid_p->getBoard()[0][3].NewPtr(0, 3, ant);

	myGrid_p->setCellOccupant(1,3,ant);
	myGrid_p->getBoard()[1][3].NewPtr(1, 3, ant);

	myGrid_p->setCellOccupant(2, 3, ant);
	myGrid_p->getBoard()[2][3].NewPtr(2, 3, ant);

	myGrid_p->setCellOccupant(3, 3, ant);
	myGrid_p->getBoard()[3][3].NewPtr(3, 3, ant);

	myGrid_p->setCellOccupant(3, 2, ant);
	myGrid_p->getBoard()[3][2].NewPtr(3, 2, ant);

	myGrid_p->setCellOccupant(3, 1, ant);
	myGrid_p->getBoard()[3][1].NewPtr(3, 1, ant);

	myGrid_p->setCellOccupant(1, 0, doodlebug);
	myGrid_p->getBoard()[1][0].NewPtr(1, 0, doodlebug);

	myGrid_p->setCellOccupant(1, 1, doodlebug);
	myGrid_p->getBoard()[1][1].NewPtr(1, 1, doodlebug);

	myGrid_p->setCellOccupant(1, 2, doodlebug);
	myGrid_p->getBoard()[1][2].NewPtr(1, 2, doodlebug);

	myGrid_p->setCellOccupant(2, 0, doodlebug);
	myGrid_p->getBoard()[2][0].NewPtr(2, 0, doodlebug);

	myGrid_p->setCellOccupant(2,1, doodlebug);
	myGrid_p->getBoard()[2][1].NewPtr(2, 1, doodlebug);

	myGrid_p->setCellOccupant(2, 2, doodlebug);
	myGrid_p->getBoard()[2][2].NewPtr(2, 2, doodlebug);

	myGrid_p->printGrid();

	myGrid_p->getBoard()[0][0].getPtr()->move(myGrid_p);
	myGrid_p->printGrid();
	myGrid_p->getBoard()[0][1].getPtr()->move(myGrid_p);
	myGrid_p->printGrid();
	myGrid_p->getBoard()[0][2].getPtr()->move(myGrid_p);
	myGrid_p->printGrid();
	myGrid_p->getBoard()[0][3].getPtr()->move(myGrid_p);
	myGrid_p->printGrid();
	myGrid_p->getBoard()[1][3].getPtr()->move(myGrid_p);
	myGrid_p->printGrid();
	myGrid_p->getBoard()[2][3].getPtr()->move(myGrid_p);
	myGrid_p->printGrid();
	myGrid_p->getBoard()[3][3].getPtr()->move(myGrid_p);
	myGrid_p->printGrid();
	myGrid_p->getBoard()[3][2].getPtr()->move(myGrid_p);


	myGrid_p->printGrid();





	delete myGrid_p;
	return result;
}

/*
 * Test if the doodle bug ate
 * return true if it passes, false otherwise
 */
bool Tests2::doodleEatTest()
{
	bool result = true;
	std::cout << "Running the eat ant test" << std::endl;
	return result;
}

/*
 * Test if the DoodleBug dies
 * return true if it passes, false otherwise
 */
bool Tests2::doodleDietest()
{
	bool result = true;
		std::cout << "Running the die doodlebug test" << std::endl;
		Grid* myGrid_p=new Grid(3);
		myGrid_p->setCellOccupant(0, 0, doodlebug);
		myGrid_p->getBoard()[0][0].NewPtr(0, 0, doodlebug);

		myGrid_p->setCellOccupant(1, 0, doodlebug);
		myGrid_p->getBoard()[1][0].NewPtr(1, 0, doodlebug);

		myGrid_p->setCellOccupant(1, 1, doodlebug);
		myGrid_p->getBoard()[1][1].NewPtr(1, 1, doodlebug);

		myGrid_p->setCellOccupant(0, 2, doodlebug);
		myGrid_p->getBoard()[0][2].NewPtr(0, 2, doodlebug);

		myGrid_p->printGrid();
		myGrid_p->getBoard()[0][0].getPtr()->move(myGrid_p);
		myGrid_p->printGrid();

		myGrid_p->getBoard()[0][1].getPtr()->move(myGrid_p);
		myGrid_p->printGrid();

		myGrid_p->getBoard()[0][0].getPtr()->move(myGrid_p);
		myGrid_p->printGrid();


		delete myGrid_p;
		return result;
}

/*
 * Destructor fot Tests2
 */
Tests2::~Tests2() {
	// TODO Auto-generated destructor stub
}

