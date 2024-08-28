#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Uso: " << argv[0] << " <dimension>" << std::endl;
        return 1;
    }

    int dimension = std::atoi(argv[1]);
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

    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            for (int k = 0; k < dimension; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Classic Mult Algorithm: " << elapsed.count() << " seconds" << std::endl;


    return 0;
}
