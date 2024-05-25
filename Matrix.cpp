#include "Matrix.h"

namespace ns 
{

template <typename T, std::size_t nRows, std::size_t nColumns>
Matrix<T, nRows, nColumns>::Matrix()
{ }

template <typename T, std::size_t nRows, std::size_t nColumns>
Matrix<T, nRows, nColumns>::Matrix(std::initializer_list<std::initializer_list<T>> list)
{ 
    if (list.size() != nRows)
        throw std::invalid_argument("Initializer list does not match intended number of rows.");

    for (std::size_t i = 0; i < nRows; ++i)
    {
        if (list.begin()[i].size() != nColumns)
            throw std::invalid_argument("Initializer list does not match intended number of columns.");

        std::copy(list.begin()[i].begin(), list.begin()[i].end(), elements.begin()+i*nColumns);
    }
}

template <typename T, std::size_t nRows, std::size_t nColumns>
Matrix<T, nRows, nColumns>::Matrix(const Matrix& other) 
{
    std::copy(other.elements.begin(), other.elements.end(), elements.begin());
}

template <typename T, std::size_t nRows, std::size_t nColumns>
Matrix<T, nRows, nColumns>::~Matrix()
{ }

template <typename T, std::size_t nRows, std::size_t nColumns>
const T& Matrix<T, nRows, nColumns>::at(std::size_t row, std::size_t col) const
{
    if (row > nRows) 
        throw std::out_of_range("Row index exceeds indexable range.");

    if (row <= 0) 
        throw std::out_of_range("Row index below indexable range.");

    if (col > nColumns)
        throw std::out_of_range("Column index exceeds indexable range.");

    if (col <= 0)
        throw std::out_of_range("Column index below indexable range.");

    return elements[((row - 1) * nColumns) + (col - 1)];
}

template <typename T, std::size_t nRows, std::size_t nColumns>
T& Matrix<T, nRows, nColumns>::at(std::size_t row, std::size_t col)
{
    return const_cast<T&>(const_cast<const Matrix&>(*this).at(row, col));
}

}