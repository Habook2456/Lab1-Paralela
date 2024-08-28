#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        return 1;
    }
    int dimension = std::atoi(argv[1]);
    int blockSize = std::atoi(argv[2]);

    std::vector<std::vector<double>> A(dimension, std::vector<double>(dimension));
    std::vector<std::vector<double>> B(dimension, std::vector<double>(dimension));
    std::vector<std::vector<double>> C(dimension, std::vector<double>(dimension, 0.0));

    std::srand(static_cast<unsigned int>(std::time(0)));
    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            A[i][j] = static_cast<double>(std::rand()) / RAND_MAX;
            B[i][j] = static_cast<double>(std::rand()) / RAND_MAX;
        }
    }

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < dimension; i += blockSize)
    {
        for (int j = 0; j < dimension; j += blockSize)
        {
            for (int k = 0; k < dimension; k += blockSize)
            {
                for (int iBlock = i; iBlock < std::min(i + blockSize, dimension); ++iBlock)
                {
                    for (int jBlock = j; jBlock < std::min(j + blockSize, dimension); ++jBlock)
                    {
                        double sum = 0.0;
                        for (int kBlock = k; kBlock < std::min(k + blockSize, dimension); ++kBlock)
                        {
                            sum += A[iBlock][kBlock] * B[kBlock][jBlock];
                        }
                        C[iBlock][jBlock] += sum;
                    }
                }
            }
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Block Mult Algorithm: " << elapsed.count() << " seconds" << std::endl;


    return 0;
}
