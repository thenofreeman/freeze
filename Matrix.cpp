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
    Matrix<T, nRows, nColumns>::Matrix(const T& scalar)
    { 
        for (size_t i = 1; i <= nRows; ++i)
            for (size_t j = 1; j <= nColumns; ++j)
                at(i, j) = scalar;
        
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
    Matrix<T, nRows, nColumns>& 
        Matrix<T, nRows, nColumns>::operator=(Matrix<T, nRows, nColumns>&& other) noexcept
        {
            if (this != &other)
                elements = std::move(other.elements);

            return *this;
        }

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

template <typename T, std::size_t nRows, std::size_t nColumns>
    std::pair<int, int> 
        Matrix<T, nRows, nColumns>::getDimensions() const
        {
            return { nRows, nColumns };
        }

template <typename T, std::size_t nRows, std::size_t nColumns>
    std::string 
        Matrix<T, nRows, nColumns>::toString() const
        {
            std::stringstream output;

            std::array<int, nColumns> columnWidths;
            columnWidths.fill(0);

            for (std::size_t i = 1; i <= nRows; ++i)
            {
                for (std::size_t j = 1; j <= nColumns; ++j)
                {
                    int value = at(i, j);
                    int width = std::to_string(value).length();

                    if (value < 0) 
                        width++;
                    if (width > columnWidths[j - 1]) 
                        columnWidths[j - 1] = width;
                }
            }

            for (std::size_t i = 1; i <= nRows; ++i)
            {
                output << '[';

                for (std::size_t j = 1; j <= nColumns; ++j)
                {
                    output << ' ' << std::setw(columnWidths[j - 1]) << at(i, j);
                }

                if (i != nRows) 
                    output << " ]" << '\n';
                else 
                    output << " ]";
            }

            return output.str();
        }

}