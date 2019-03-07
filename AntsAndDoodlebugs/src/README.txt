Ants and Doodlebugs-PA4--Polymorphism
***********************************************
It is a 2-D prey-predator simulation consisting of two types of organisms: Ants(prey) and Doodlebugs(predator).
They are placed on a grid of n-by-n number of square cells. 
***********************************************
Classes:

1.Organism: class representing an organism
  Includes:Grid.h
  Methods:
	1.Organism(),Organism(bool b)----Constructors
	2.bool isPrey()--returns true of the organism is a prey
	3.virtual int move(Grid* grid)--for moving an organism
	4.virtual bool breed(Grid* grid)-- for breeding an organism
	5.void setAmAnt(bool b)-- sets whether the organism or not
	6.virtual~Organism()--destructor
2.Ant: class representing an Ant, inherits from Organism
  Includes:Organism.h,Grid.h
  Member variables:
	1.row: current row
	2.col: current column
	3.breedCounter: integer representing if the ant can breed(if int==3)
  Methods:
	1.Ant(),Ant(int r=0,int col=0)----Constructors
	2.int getRow()--returns row of the ant
	3.int move(Grid* grid)--for moving an ant
	4.bool breed(Grid* grid)-- for breeding an ant
	5.int getCol()--returns col of the ant 
	6.~Ant()--destructor
	7.void moveHelper(Grid* grid,int dir)--moves the ant in the specified direction on the grid
	8.void breedHelper(Grid* grid,int dir)--breeds the ant in the specified direction on the grid
3.Doodlebug: class representing a Doodlebug, inherits from Organism
  Includes:Organism.h,Grid.h
  Member variables:
	1.row: current row
	2.col: current column
	3.breedCounter: integer representing if the doodlebug can breed(if int==8)
	4.deathCount: integer representing if the doodlebug can die(if int==3)
  Methods:
	1.Doodlebug(),Doodlebug(int r=0,int col=0)----Constructors
	2.int getRow()--returns row of the doodlebug
	3.int move(Grid* grid)--for moving a doodlebug
	4.bool breed(Grid* grid)-- for breeding a doodlebug
	5.int getCol()--returns col of the doodlebug 
	6.~Doodlebug()--destructor
	7.void moveHelper(Grid* grid,int dir)--moves the doodlebug in the specified direction on the grid
	8.void breedHelper(Grid* grid,int dir)--breeds the doodlebug in the specified direction on the grid
	9.int getBreedCounter()--returns the breedCounter
	10.int getDeathCount()--returns the deathCount
	11.int eat(Grid* grid,bool* arrAnts)--for eating ants
4.Cell: class representing the cells on the grid
  Member variables:
	1.occupationStatus guest
	2.Organism* ptr= pointer to a kind of organism
  Methods:	
	1.Cell()-Constructor
	2.bool setOccupant(occupationStatus g)--setter for occupationStatus
	3.void NewPtr(int r,int c,occupationStatus g)--setter for a new pointer
	4.Organism* getPtr()--getter for ptr
	5.void setPtr(Organism* newPtr)--setter for existing pointer
	6.occupationStatus getOccupant()--getter for the occupationStatus
	7.virtual ~Cell()--destructor
5.Grid: class representing the grid
  Member variables:
	1.Cell** board: the array of pointers to cells
	2.int size=0: the size of the array/grid
  Methods:	
	1.Grid()-Constructor
	2.Grid(int nSquaresOnASide)-Constructor
	3.Cell** getBoard()--getter for board
	4.bool setCellOccupant(int r, int c, occupationStatus g)--setter for an individual cell occupant
	5.occupationStatus getCellOccupant(int r, int c)--getter for an individual cell occupant
	6.bool* findNeighbours(int r, int c,occupationStatus g)--finds the neighbours of specified type
	7.int randInt(int n)-- generates a random int
	8.void printGrid()-- prints the grid
	9.virtual ~Grid()--destructor
**************************************************************************
To run it, the following format should be used:
./PA5 gridSize #doodlebugs #ants #time_steps seed pause
	
	
 
