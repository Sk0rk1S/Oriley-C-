#include <iostream>
#include <cmath>
/* DOES EXACTLY THE SAME SHIT AS averageFrameClusterFuck.cpp (which was 3D) BUT IN 4D
Each frame consists of 3 layers, R, G, B instead of 1 layer like averageFrameClusterFuck.cpp */

void getAverage(const int arr[3][3][3][3], double averageF[3][3][3], int size);
void appendToAverage(double averageF[3][3][3], int rSum, int gSum, int bSum, int& outerLoop, int& innerLoop);
//void test(double averageF[3][3][3]);
void getBestFrame(const double averageF[3][3][3], const int arr[3][3][3][3], int& bestIndex);
void printBestFrame(const int arr[3][3][3][3], int bestIndex);

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

    getAverage(arr, averageF, size); 
    getBestFrame(averageF, arr, bestIndex);
    //test(averageF);
    std::cout << "The best frame is at index: " << bestIndex << "\n";
    printBestFrame(arr, bestIndex);
}

void getAverage(const int arr[3][3][3][3], double averageF[3][3][3], int size)
{
    int rSum = 0;
    int gSum = 0;
    int bSum = 0;

    int innerLoop = 0;
    int outerLoop = 0;

    for(int i = 0; i < 3; i++) //How many frames there are
    {
        //std::cout << " NEW COLOR: " << "\n\n\n";
        for(int j = 0; j < 3; j++) 
        {
            for(int k = 0; k < 3; k++)
            {
                /*
                std::cout << "RED: " << arr[k][0][j][i] << "\n"; //[k][0]
                std::cout << "GREEN: " << arr[k][1][j][i] << "\n";
                std::cout << "BLUE: " << arr[k][2][j][i] << "\n";
                */
               //This is traversing vertically btw
               rSum += arr[k][0][j][i];
               gSum += arr[k][1][j][i];
               bSum += arr[k][2][j][i];
            }
            appendToAverage(averageF, rSum, gSum, bSum, outerLoop, innerLoop);
            /*
            std::cout << (double)rSum/3 << "\n";
            std::cout << (double)gSum/3 << "\n";
            std::cout << (double)bSum/3 << "\n";
            std::cout << "\n";
            */
            innerLoop++;
            rSum = 0;
            gSum = 0;
            bSum = 0;
        }
        innerLoop = 0;
        outerLoop++;
    }
} 


void appendToAverage(double averageF[3][3][3], int rSum, int gSum, int bSum, int& outerLoop, int& innerLoop)
{
    int total_number_of_frames = 3;

    for(int i = outerLoop; i < outerLoop + 1; i++)
    {
        for(int j = innerLoop; j < innerLoop + 1; j++)
        {
            /*
            std::cout << "0 " << i << " " << j << "       ";
            std::cout << double(rSum)/3;
            std::cout << "\n";
            */
           //This is traversing vertically btw
           averageF[0][i][j] = double(rSum)/total_number_of_frames;
           averageF[1][i][j] = double(gSum)/total_number_of_frames;
           averageF[2][i][j] = double(bSum)/total_number_of_frames;
        }
    }
}

/*
void test(double averageF[3][3][3])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                std::cout << averageF[i][j][k] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n\n";
    }
}
*/

void getBestFrame(const double averageF[3][3][3], const int arr[3][3][3][3], int& bestIndex) //I FORGOT TO PASS BESTINDEX BY REFERENCE FUCKKKCKCKKCKCKKC
{
    double minSum = 0;
    double tempMinSum = 0;

    /*Initializing minSum*/
    for(int i = 0; i < 1; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                // std::cout << arr[i][0][k][j] << " "; //n'th frames red location
                // std::cout << arr[i][1][k][j] << " "; //n'th frames green location
                // std::cout << arr[i][2][j][k] << " "; //n'th frames blue location
                // std::cout << averageF[0][j][k] << " ";
                minSum += (std::abs(arr[i][0][k][j] - averageF[0][j][k]) + std::abs(arr[i][1][k][j] - averageF[1][j][k]) + std::abs(arr[i][2][k][j] - averageF[2][j][k]));
            }
        }
        //std::cout << "minSum is: " << minSum << "\n";
    }
    
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                tempMinSum += (std::abs(arr[i][0][k][j] - averageF[0][j][k]) + std::abs(arr[i][1][k][j] - averageF[1][j][k]) + std::abs(arr[i][2][k][j] - averageF[2][j][k]));
            }
        }
        if(tempMinSum < minSum) //OK APPARENTLY I NEEDED TO DO THIS ON THE MID FOR LOOP OMFG
        {
            minSum = tempMinSum;
            bestIndex = i;
        }
        tempMinSum = 0;
    }
}

void printBestFrame(const int arr[3][3][3][3], int bestIndex)
{
    for(int i = bestIndex; i < bestIndex + 1; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                for(int l = 0; l < 3; l++)
                {
                    std::cout << arr[i][j][k][l] << " ";
                }
                std::cout << "\n";
            }
        }
    }
}
