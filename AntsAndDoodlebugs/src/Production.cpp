/*
 * Production.cpp
 *
 *  Created on: Feb 25, 2019
 *      Author: Suryansh Goyal
 */

#include "Production.h"
#include <stdlib.h>
#include <iostream>
#include "Grid.h"
#include "Organism.h"


bool argSetUp=true;
Grid* finalGrid;
/*
 * Constructor for Production
 */
Production::Production(int argc, char* argv[]) {
	// TODO Auto-generated constructor stub
	//int timestepsLeft = 1000;//initialize available timesteps
	if(argc<6){
		argSetUp=false;
	}
	else{

		char* ptr=0;
		long gridSize_l=strtol(argv[1],&ptr,10);
		gridSize=(int)gridSize_l;

		long numDoodlebugs_l=strtol(argv[2],&ptr,10);
		numDoodlebugs=(int)numDoodlebugs_l;

		long numAnts_l=strtol(argv[3],&ptr,10);
		numAnts=(int)numAnts_l;

		long timestepsLeft_l=strtol(argv[4],&ptr,10);
		timestepsLeft=(int)timestepsLeft_l;

		long seed_l=strtol(argv[5],&ptr,10);
		seed=(int)seed_l;
		if(argc==7){
			long pause_l=strtol(argv[6],&ptr,10);
			pause=(int)pause_l;
		}
	}

}
/*
 * Checks whether the production ran or not
 * @return bool, true if the production ran, false otherwise
 */
bool Production::runProduction()
{
	bool result = false;
	int orgNumDoodlebugs=numDoodlebugs;
	int orgNumAnts=numAnts;
	int orgTime_steps=timestepsLeft;
	int numDbirths=0;
	int numAbirths=0;
	//checking for the validity of arguments
	if(argSetUp==false){
		std::cout<<"Usage: PA5 gridSize #doodlebugs #ants #time_steps seed [pause]"<<std::endl;
	}
	if((numAnts+numDoodlebugs)>(gridSize*gridSize)){
		std::cout<<"Num of Doodlebugs and Ants should be lesser than the number of cells on the board."<<std::endl;

	}
	else{
		result=true;

		//Setting up the board
		Grid* myGrid_p=new Grid(gridSize);//initialize the grid

		int counter=0;
		while(counter!=numAnts){
			int randRow=myGrid_p->randInt(gridSize-1);
			int randCol=myGrid_p->randInt(gridSize-1);
			if(myGrid_p->getCellOccupant(randRow,randCol)==empty){
				myGrid_p->getBoard()[randRow][randCol].NewPtr(randRow, randCol, ant);
				myGrid_p->setCellOccupant(randRow, randCol, ant);
				counter++;
			}
		}// the ants are set up

		int counter1=0;
		while(counter1!=numDoodlebugs){
			int randRow=myGrid_p->randInt(gridSize-1);
			int randCol=myGrid_p->randInt(gridSize-1);
			if(myGrid_p->getCellOccupant(randRow,randCol)==empty){
				myGrid_p->getBoard()[randRow][randCol].NewPtr(randRow, randCol, doodlebug);
				myGrid_p->setCellOccupant(randRow, randCol, doodlebug);
				counter1++;
			}
		}// the doodlebugs are set up

		myGrid_p->printGrid();



		while(timestepsLeft-- > 0)
		{


			//dbs.step;
			for(int i=0;i<gridSize;i++){
				for(int j=0;j<gridSize;j++){
					if(myGrid_p->getCellOccupant(i, j)==doodlebug){
						int response=myGrid_p->getBoard()[i][j].getPtr()->move(myGrid_p);
						if(response==2){
							numAnts=numAnts-1;
						}
						if(response==3){
							numDoodlebugs=numDoodlebugs-1;
						}
						if(response==4){
							numDoodlebugs++;
							numDbirths++;
						}
						if(response==5){
							numAnts=numAnts-1;
							numDoodlebugs++;
							numDbirths++;
						}



					}
				}
			}

			//ants.step;
			for(int i=0;i<gridSize;i++){
				for(int j=0;j<gridSize;j++){
					if(myGrid_p->getCellOccupant(i, j)==ant){
						 int response=myGrid_p->getBoard()[i][j].getPtr()->move(myGrid_p);
						 if(response==2){
							 numAnts++;
							 numAbirths++;
						 }




					}
				}
			}
			if(pause>0){
				puts("new gen:");
				myGrid_p->printGrid();
				getc(stdin);
			}



			if(numDoodlebugs==0){
				std::cout<<"All doodlebugs died!"<<std::endl;
				break;
			}
			if(numAnts==0){
				std::cout<<"All ants died!"<<std::endl;
				break;
			}
			finalGrid=myGrid_p;
		}
	}
	if (result==true){
		std::cout<<"Summary of Simulation"<<std::endl;
		std::cout<<"Original Command Line:"<<std::endl;
		std::cout<<gridSize<<" "<<orgNumDoodlebugs<<" "<<orgNumAnts<<" "<<orgTime_steps<<" "<<seed<<" "<<pause<<std::endl;
		std::cout<<"Number of steps simulated:"<<orgTime_steps-timestepsLeft-1<<std::endl;
		std::cout<<"Total number of Doodlebugs:"<<orgNumDoodlebugs+numDbirths<<",number left:"<<numDoodlebugs<<std::endl;
		std::cout<<"Total number of Ants:"<<orgNumAnts+numAbirths<<",number left:"<<numAnts<<std::endl;
		std::cout<<"Final Grid:"<<std::endl;
		finalGrid->printGrid();
	}
	return result;
}

Production::~Production() {
	// TODO Auto-generated destructor stub
}

