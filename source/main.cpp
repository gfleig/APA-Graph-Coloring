#include "initializer.hpp"
#include "constructor.hpp"

int main()
{
    char* filename = "input/myciel3.col";

    int** adjMatrix;
    int nVertices;

    int* solution;

    adjMatrix = buildAdjMatrix(filename, &nVertices);    
    
    solution = constructSolution(nVertices, adjMatrix);

    printSolution(nVertices, solution);

    return 0;
}