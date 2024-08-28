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
    std::vector<double> x(dimension), y(dimension, 0);

    std::srand(static_cast<unsigned int>(std::time(0)));
    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            A[i][j] = static_cast<double>(std::rand()) / RAND_MAX;
        }
        x[i] = static_cast<double>(std::rand()) / RAND_MAX;
    }

    auto start = std::chrono::high_resolution_clock::now();

    for (int j = 0; j < dimension; j++)
    {
        for (int i = 0; i < dimension; i++)
        {
            y[i] += A[i][j] * x[j];
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Loop2: " << elapsed.count() << " seconds" << std::endl;

    return 0;
}
