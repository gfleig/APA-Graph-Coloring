#include "constructor.hpp"

/*returns an array of size matrixsize + 1
  the first element is the k-coloring!!!*/
int* constructSolution(const int matrixSize, int** matrix)
{
    int* solution = new int[matrixSize + 1];                                //solution amtrix to be returned; index 0 is k-coloring

    std::vector <int> colors(matrixSize, 0);                                //vector of colors of each vertex; 0 is "null"

    for(int vertex = 0; vertex < matrixSize; ++vertex)                       //for each vertex
    {
        std::vector <int> neighbourColors;                                  //make a vector of the colors of neighbours

        for(int neighbour = 0; neighbour < matrixSize; ++neighbour)         //for each neighbour
        {
            if(matrix[vertex][neighbour])                                   //if they are both connected
            {
                neighbourColors.push_back(colors[neighbour]);               //add the color to the neighbours vector
            }
        }

        std::sort(neighbourColors.begin(), neighbourColors.end());          //sort the neighbour colors

        int color = 0;

        for(unsigned int i = 0; i < neighbourColors.size() - 1; ++i)                 //try to get the smallest color in a gap between neighbour colors
        {
            if(neighbourColors[i] + 1 < neighbourColors[i + 1])
            {
                color = neighbourColors[i] + 1;
                break;
            }            
        }

        if(color == 0)                                                      //if no gap, get biggest color + 1
        {
            color = neighbourColors.back() + 1;
        }

        colors[vertex] = color;                                             //update the colors vector
    }

    for(int i = 0; i < matrixSize; ++i)                                     //update solution array after solution is created
    {
        solution[i+1] = colors[i];
    }

    std::sort(colors.begin(), colors.end());                                //sort colors to get k coloring

    solution[0] = colors.back();                                            //index 0 is k coloring!!

    return solution;
}
