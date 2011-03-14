#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

int getNumCellsAlive(const std::vector< std::vector<bool> >& current,int i, int j)
{
	if (current.size() == 0 || current[0].size() == 0) {
		return 0;
	}
	
	int numCellsAlive = 0; 
	int x[] = { i - 1, i - 1, i - 1, i, i, i + 1, i + 1, i + 1 };
	int y[] = { j - 1, j, j + 1, j - 1, j + 1, j - 1, j, j + 1 };
	
	int maxRows = current.size();
	int maxCols = current[0].size();
	
	for (int l = 0; l < 8; l++) {
		if (!((x[l] < 0 || x[l] >= maxRows)) && 
			!((y[l] < 0 || y[l] >= maxCols))) {
			if (current[x[l]][y[l]] == true) {
				numCellsAlive++;
			}
		}
	}
	
	return numCellsAlive;
}

void computeNextGeneration(std::vector< std::vector<bool> >& current)
{
    // This function does the following:
    // 1. Computes the next generation from the previous one.
    // 2. Copies the next generation over, replacing the existing one.
	std::vector< std::vector<bool> > arena(current);
	
	for (int i = 0; i < current.size(); i++) {
		for (int j = 0; j < current.size(); j++) {
			int numAlive = getNumCellsAlive(current, i, j); 
			
			if (current[i][j] == true) {
				if (numAlive > 3 || numAlive < 2) {
					arena[i][j] = false;
				}
			} else {
				if (numAlive == 3) {
					arena[i][j] = true;
				}
			}
		}
	}
	
	current = arena;
}

void initializeArena(std::vector< std::vector<bool> >& arena, int rows, int cols, int numCells)
{
	// Initialize the arena with random true/false values.
	// numCells determines how many cells are turned on. 
	for (int i = 0; i < rows; ++i) {
		std::vector<bool> values;
		for (int j = 0; j < cols; ++j) {
			values.push_back(false);
		}
		arena.push_back(values);
	}
	
	int numSelected = 0;
	
	while (numSelected < numCells) {
		int selectedRow = rand() % rows; // TODO Replace with a random number function
		int selectedColumn = rand() % cols; 
		
		if (arena[selectedRow][selectedColumn] == false) {
			arena[selectedRow][selectedColumn] = true;
			numSelected++;
		}
	}
}

void writeGenerationToFile(const std::vector< std::vector<bool> >& arena,
                           const std::string&                      prefix,
                           int                                     generation)
{
    std::stringstream ss;
    ss << prefix << generation << ".life";
	
    std::ofstream file(ss.str().c_str());
	
    if (!file.is_open()) {
        return;
    }
	
    for (std::vector< std::vector<bool> >::const_iterator rowIter = arena.begin();
		 arena.end() != rowIter;
		 ++rowIter) {
        for (std::vector<bool>::const_iterator colIter = rowIter->begin();
			 rowIter->end() != colIter;
			 ++colIter) {
            file << (int)*colIter << " ";
        }
		
        file << std::endl;
    }
	
	file.close();
}

int main(int argc, char *argv[])
{
    if (argc < 4) {
        std::cout << "Usage: basiclife <rows> <cols> <numstart> <generations> <prefix>" << std::endl;
        return 0;
    }
	
	int rows = atoi(argv[1]);
	int cols = atoi(argv[2]);
	int numStart = atoi(argv[3]);
	int numGenerations = atoi(argv[4]);
	std::string prefix(argv[5]);
	
    std::vector< std::vector<bool> > arena;
	
	initializeArena(arena, rows, cols, numStart);
	
	int generationCount = 0;
	
	while (generationCount < numGenerations) {
		writeGenerationToFile(arena, prefix, generationCount);
		computeNextGeneration(arena);
		generationCount++;
	}
}
