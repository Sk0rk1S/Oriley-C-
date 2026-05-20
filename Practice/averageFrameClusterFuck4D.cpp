#include <iostream>
#include <cmath>
/*
DOES EXACTLY THE SAME SHIT AS averageFrameClusterFuck.cpp (which was 3D) BUT IN 4D
Each frame consists of 3 layers, R, G, B instead of 1 layer like averageFrameClusterFuck.cpp
*/
void getAverage(const int arr[3][3][3][3], double averageF[3][3][3], int size);
void appendToAverageF(double averageF[3][3][3], int sum, int& innerLoop, int& midLoop, int& outerLoop);
void getBestFrame(const int arr[3][3][3][3], const double averageF[3][3][3], int size, int& bestIndex);
void printArray(const int arr[3][3][3][3], int size, int bestIndex);

int main()
{
    int arr[3][3][3][3] = {{{126, 188, 74, 102, 49, 22, 24, 213, 213},  //Frame 1 start
                           {89, 248, 129, 71, 196, 219, 221, 95, 248},
                           {244, 47, 177, 32, 61, 24, 213, 24, 81}},    
                           {{19, 129, 135, 167, 53, 60, 89, 97, 85},  //Frame 2 start
                           {188, 130, 142, 205, 55, 159, 97, 4, 241},
                           {77, 209, 86, 105, 229, 174, 239, 39, 229}},
                           {{28, 103, 206, 131, 218, 165, 204, 155, 107}, //Frame 3 start
                           {161, 118, 137, 124, 67, 118, 238, 193, 6},
                           {28, 204, 174, 246, 229, 227, 250, 182, 251}}};
    int bestIndex = 0;
    int size = 3; //How long each column is
    double averageF[3][3][3] = {0};

    //Fills up the averageF array after calling getAverage()
    getAverage(arr, averageF, size); 

    //printArray(averageF, size);
    //KNN

    //Finds the best frame that has the smallest distance from the average frame
    getBestFrame(arr, averageF, size, bestIndex); 

    printArray(arr, size, bestIndex);
}

void getAverage(const int arr[3][3][3][3], double averageF[3][3][3], int size)
{
    int sum = 0;
    int innerLoop = 0;
    int midLoop = 0;
    int outerLoop = 0;

    for(int i = 0; i < size; i++)
    {
        //std::cout << " NEW COLOR: " << "\n\n\n";
        for(int j = 0; j < size; j++)
        {
            for(int k = 0; k < size; k++)
            {
                for(int l = 0; l < size; l++)
                {
                    sum += arr[l][i][j][k];
                }
                //std::cout << "\n SUM UP THESE NUMBERS ABOVE"; 
                appendToAverageF(averageF, sum, innerLoop, midLoop, outerLoop);//Append to averageF array
                innerLoop++;//Increment inner for loop of averageF
                sum = 0; //REMEMBER TO RESET SUM TO ZERO ASWELL FOR FUCKS SAKESs
            }
            innerLoop = 0;//Reset inner loop
            midLoop++;//Increment middle for loop of averageF
            //std::cout << "\n";
        }
        midLoop = 0;//Reset midloop
        outerLoop++;//Increment outermost for loop of averageF
    }
}

/*
appends the values from getAverage to the averageF[3][3][3] array
*/

void appendToAverageF(double averageF[3][3][3], int sum, int& innerLoop, int& midLoop, int& outerLoop)
{
    //We only want these loops to run once
    for(int i = outerLoop; i < outerLoop + 1; i++)
    {
        for(int j = midLoop; j < midLoop + 1; j++)
        {
            for(int k = innerLoop; k < innerLoop + 1; k++)
            {
                averageF[i][j][k] = (double)sum / 3;
            }
        }
    }
}

void getBestFrame(const int arr[3][3][3][3], const double averageF[3][3][3], int size, int& bestIndex)
{
    double minsum = 0;
    double tempsum = 0;

    /*
    This first quadruple for loop is to initialize minSum
    */
    for(int i = 0; i < 1; i++)
    {
        for(int j = 0; j < size; j++)
        {
            for(int k = 0; k < size; k++)
            {
                for(int l = 0; l < size; l++)
                {
                    minsum += std::abs(arr[i][j][k][l] - averageF[j][k][l]);
                }
            }
        }
    }

    //After minSum is initialized, we can now start to find the median frame
    //The frame that has the least total euclidean distance will be the frame selected.
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            for(int k = 0; k < size; k++)
            {
                for(int l = 0; l < size; l++)
                {
                    tempsum += std::abs(arr[i][j][k][l] - averageF[j][k][l]);
                }
                if(tempsum < minsum)
                {
                    minsum = tempsum;
                    bestIndex = i;
                    //std::cout << "The best index is now at: " << bestIndex << "\n"; For testing purposes
                }
                /* For testing purposes
                std::cout << "minSum is: " << minsum << "\n";
                std::cout << "tempSum is: " << tempsum << "\n";
                */
                tempsum = 0;
            }
        }
    }
}

//Prints the array that was selected
void printArray(const int arr[3][3][3][3], int size, int bestIndex)
{
    for(int i = bestIndex; i < bestIndex + 1; i++)
    {
        for(int j = 0; j < size; j++)
        {
            for(int k = 0; k < size; k++)
            {
                for(int l = 0; l < size; l++)
                {
                    std::cout << arr[i][j][k][l] << "  ";
                }
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
}
