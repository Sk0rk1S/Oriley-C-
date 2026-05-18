#include <iostream>
#include <cmath>

void getAverageF(const int arr[3][3][3], double averageF[3][3], int size);
void appendAverage(unsigned int sum, int& innerIndex, int& outerIndex, double averageF[3][3]);

void getEuclidean(const int arr[3][3][3], int size, const double averageF[3][3], int& bestIndex);
void test(const int arr[3][3][3], int size, int& bestIndex);

int main()
{
    int arr[3][3][3] = {6, 6, 8, 9, 10, 3, 5, 6, 1,
                        10, 4, 10, 5, 9, 0, 8, 3, 10,
                        7, 0, 0, 7, 4, 9, 0, 4, 6};
    int size = 3;
    int bestIndex;

    double averageF[3][3] = {0};
    double tempFrame[3][3] = {0}; //Temporary frame so we can add up the total euclidean distance, then move onto the next frame
    double tempMin = 0;
    
    //True median
    getAverageF(arr, averageF, size); //Fills up the averageF array after calling
    
    //Now I need to find the euclidean distance of each frame, relative to averageF
    getEuclidean(arr, size, averageF, bestIndex);
    test(arr, size, bestIndex);
}

void getAverageF(const int arr[3][3][3], double averageF[3][3], int size)
{
    unsigned int sum = 0;
    int innerIndex = 0;
    int outerIndex = 0;

    std::cout << "THE AVERAGE FRAME IS: \n";
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            for(int k = 0; k < size; k++)
            {
                sum += arr[k][i][j]; //Prints by column, transcending each 2d array (or you could say the coordinate)
            }
            appendAverage(sum, innerIndex, outerIndex, averageF); //Now we pass sum to the appendAverage() function
            innerIndex++;
            sum = 0;
        }
        innerIndex = 0; //Reset the inner index to 0 after each outer for loop increment
        outerIndex++; //Increment outer index here ig?? because we just incremented inner index above lol
        std::cout << "\n";
    }
    std::cout << "\n\n";
}

/*
appends the values from getAverage to the averageF[3][3] array
*/

void appendAverage(unsigned int sum, int& innerIndex, int& outerIndex, double averageF[3][3])
{
    //std::cout << (double)sum / 3 << " ";
    for(int i = outerIndex; i < outerIndex + 1; i++)
    {
        for(int j = innerIndex; j < innerIndex + 1; j++)
        {
            averageF[i][j] = (double)sum / 3;
            std::cout << averageF[i][j] << " ";
        }
    }
}

void getEuclidean(const int arr[3][3][3], int size, const double averageF[3][3], int& bestIndex)
{
    //std::cout << "EUCLIDEAN DISTANCE FOR EACH FRAME: \n";
    double tempSum = 0;
    double minSum = 0;

    /*
    This first triple for loop is to initialize minSum
    */
    for(int i = 0; i < 1; i++)
    {
        for(int j = 0; j < size; j++)
        {
            for(int k = 0; k < size; k++)
            {
                //std::cout << std::abs(arr[i][j][k] - averageF[i][j]) << " "; //abs() will only give int, std::abs() can give double
                //std::cout << arr[i][j][k] << "      " << averageF[j][k] << "          "; OK NOW IT WORKS 
                minSum += std::abs(arr[i][j][k] - averageF[j][k]);
            }
            //std::cout << "\n";
        }
        //std::cout << "\n\n";
    }

    //After minSum is initialized, we can now start to find the median frame
    //The frame that has the least total euclidean distance will be the frame selected.
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            for(int k = 0; k < size; k++)
            {
                tempSum += std::abs(arr[i][j][k] - averageF[j][k]);
            }
            if(tempSum < minSum)
            {
                minSum = tempSum;
                std::cout << "The best frame is at index: " << i;
                bestIndex = i;
            }
            //std::cout << "\n";
        }
        //std::cout << "\n\n";
    }
}

//Now we will go through the original array of frames and check the value at "bestIndex"
//bestIndex should contain the location of the median frame.
void test(const int arr[3][3][3], int size, int& bestIndex)
{
    std::cout << "\n";
    std::cout << "THE BEST FRAME IS: \n";
    for(int i = bestIndex; i < bestIndex + 1; i++) //Because we only want the outermost for loop to run once
    {
        for(int j = 0; j < size; j++)
        {
            for(int k = 0; k < size; k++)
            {
                std::cout << arr[i][j][k] << " ";
            }
            std::cout << "\n";
        }
    }
}
