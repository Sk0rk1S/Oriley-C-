#include <vector>
#include <iostream>
#include <algorithm>

//Given a 2d grid, what is the most expensive path one can take from the top left corner to the bottom right corder of the grid?
// Constraints are you can ONLY move down or right
// FIND THE OPTIMAL SOLUTION FOR THIS PROBLEM

//Step 1, initialize the costs of moving all the way right and all the way down, aswell as initialize an "answer" matrix
//Step 2, check if the top cell is more expensive than the left cell, and add whichever is more expensive add it
//I cant list all the steps lmao, Its better if i had a whiteboard to explain the algorithm...

//Helper function to initialize answer matrix's row and columns
//THIS FUNCTION WORKS!!!
//Also passing by reference because I know the concept of memory efficiency
std::vector<std::vector<int>> answerMatrix(const std::vector<std::vector<int>>& matrix)
{
    //This looks very ugly yeah...but its how you initialize a 2D array in O(1) time
    std::vector<std::vector<int>> answer(matrix.size(), std::vector<int>(matrix[0].size()));;
    answer[0][0] = matrix[0][0];
    int previous = answer[0][0];
    //Initializing the 0th row
    for(int i = 1; i < matrix[0].size(); i++)
    {
        answer[0][i] = previous + matrix[0][i];
        previous = answer[0][i];
    }
    //dont forget to reset previous to answer[0][0] lmao
    previous = answer[0][0];

    //Initializing the 0th column
    for(int j = 1; j < matrix.size(); j++)
    {
        answer[j][0] = previous + matrix[j][0];
        previous = answer[j][0];
    }

    return answer;
}

//Initializes the rest of the grid using the output from answerMatrix() as a starting template
//Uses answerMatrix() as a helper function
std::vector<std::vector<int>> initializedGrid(const std::vector<std::vector<int>>& matrix)
{
    std::vector<std::vector<int>> answerMat = answerMatrix(matrix);
    for(int i = 0; i < answerMat.size() - 1; i++)
    {
        for(int j = 1; j < answerMat[i].size(); j++)
        {
            if(answerMat[i][j] > answerMat[i + 1][j - 1])
            {
                answerMat[i + 1][j] = answerMat[i][j] + matrix[i + 1][j];
            }
            else
            {
                answerMat[i + 1][j] = answerMat[i + 1][j - 1] + matrix[i + 1][j];
            }
        }
    }
    return answerMat;
}

//Uses initializedGrid() as a helper function
//Returns the sequence of numbers you need to take for the most expensive path from top left, to bottom right
//With moving constraints being: you can only move down or right

std::vector<int> mostExpensivePath(const std::vector<std::vector<int>>& matrix)
{
    std::vector<std::vector<int>> answerMat = initializedGrid(matrix);
    std::vector<int> path;
    
    //Peak redneck software engineering below:

    int i = matrix.size() - 1;
    int j = matrix[0].size() - 1;
    //Push the end of the path first
    path.push_back(answerMat[i][j]);

    //What is this while loop doing?? It is Backtracking lmao
    // ̶B̶e̶c̶a̶u̶s̶e̶ ̶i̶f̶ ̶t̶h̶e̶y̶ ̶a̶r̶e̶ ̶b̶o̶t̶h̶ ̶o̶n̶e̶,̶ ̶w̶e̶ ̶h̶a̶v̶e̶ ̶e̶x̶i̶t̶e̶d̶ ̶t̶h̶e̶ ̶l̶o̶o̶p̶.̶.̶.̶b̶e̶c̶a̶u̶s̶e̶ ̶w̶e̶ ̶a̶r̶e̶ ̶o̶n̶e̶ ̶i̶n̶d̶e̶x̶ ̶a̶w̶a̶y̶ ̶f̶r̶o̶m̶ ̶t̶h̶e̶ ̶s̶t̶a̶r̶t̶ ̶(̶a̶l̶s̶o̶ ̶d̶i̶d̶ ̶t̶h̶i̶s̶ ̶b̶e̶c̶a̶u̶s̶e̶ ̶t̶h̶e̶r̶e̶ ̶w̶o̶u̶l̶d̶ ̶b̶e̶ ̶a̶n̶ ̶o̶u̶t̶ ̶o̶f̶ ̶b̶o̶u̶n̶d̶s̶ ̶e̶r̶r̶o̶r̶ ̶i̶f̶ ̶I̶ ̶d̶i̶d̶n̶t̶)̶
    // Wait why tf did this work...???????
    // I literally just wrote this while loop condition and have no idea why it worked
    // I kinda know how it works but not intuitively 
    // while(i > 1 || j > 1)... this was the old while loop condition before it changed into whatever tf this is
    while(((i != 1 || j != 0) && (i != 0 || j != 1)))
    {
        if(answerMat[i - 1][j] == answerMat[i][j] - matrix[i][j])
        {
            // YOU DUMBAHH UPDATE THE INDEX NOT THE VALUES OMFG
            // answerMat[i][j] = answerMat[i - 1][j];
            i = i - 1;
            path.push_back(answerMat[i][j]);
        }
        else
        {
            // answerMat[i][j] = answerMat[i][j - 1];
            j = j - 1;
            path.push_back(answerMat[i][j]);
        }
    }
    // The new while loop condition above was so I didn't need to include the below commented out code...lmao
    // path.push_back(answerMat[i][j] - matrix[i][j]);

    path.push_back(answerMat[0][0]);
    // std::reverse(path.begin(), path.end());
    return path;
}

int main()
{
    std::vector<std::vector<int>> matrix = {
    {5, 4, 1, 3, 4, 1},
    {1, 2, 6, 2, 1, 5},
    {4, 1, 1, 2, 9, 11},
    {3, 1, 2, -4, 3, 6},
    {4, 4, 1, 2, 9, 2}};

    // I was testing to see if answerMatrix() worked or not, IT WORKS
    // std::vector<std::vector<int>> answerMat = answerMatrix(matrix);

    // for(int i = 0; i < answerMat.size(); i++)
    // {
    //     for(int j = 0; j < answerMat[i].size(); j++)
    //     {
    //         std::cout << answerMat[i][j] << "   ";
    //     }
    //     std::cout << std::endl;
    // }

    // Testing to see if initializeGrid() works:
    // WORKS
    // Printed out the answer matrix for reference/to verify the output is indeed the correct path
  
    std::vector<std::vector<int>> answerMat = initializedGrid(matrix);

    for(int i = 0; i < answerMat.size(); i++)
    {
        for(int j = 0; j < answerMat[i].size(); j++)
        {
            std::cout << answerMat[i][j] << "   ";
        }
        std::cout << std::endl;
    }

    std::vector<int> path = mostExpensivePath(matrix);
    std::cout << " Note: this path is backwards lol, I could do std::reverse but nah " << std::endl;
    for(int i = 0; i < path.size(); i++)
    {
        std::cout << path[i] << " ";
    }

    return 0;
}
