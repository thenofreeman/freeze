#pragma once

#include <initializer_list>
#include <array>
#include <utility>

namespace ns 
{

template <typename T, std::size_t nRows, std::size_t nColumns>
class Matrix
{
    public:
        Matrix();
        Matrix(std::initializer_list<std::initializer_list<T>> list);
        Matrix(const T& scalar);
        Matrix(const Matrix& other);
        ~Matrix();

        const T& at(std::size_t row, std::size_t col) const;
        T& at(std::size_t row, std::size_t col);

        std::pair<int, int> getDimensions() const
        {
            return { nRows, nColumns };
        }

        Matrix<T, nRows, nColumns>& operator=(Matrix<T, nRows, nColumns>&& other) noexcept
        {
            if (this != &other)
                elements = std::move(other.elements);

            return *this;
        }
    
    public:

    private:

    private:
        std::array<T, nRows + nColumns> elements;

};

template <typename T, std::size_t nRows, std::size_t nColumns>
    Matrix<T, nRows, nColumns> 
        add(const Matrix<T, nRows, nColumns>& lhs, const Matrix<T, nRows, nColumns>& rhs)
        {
            if (lhs.getDimensions() != rhs.getDimensions())
                throw std::invalid_argument("Matrixes being operated on have different dimensions.");

            Matrix<T, nRows, nColumns> temp;

            for (size_t i = 1; i <= nRows; ++i)
                for (size_t j = 1; j <= nColumns; ++j)
                    temp.at(i, j) = lhs.at(i, j) + rhs.at(i, j);

            return temp;
        }

template <typename T, std::size_t nRows, std::size_t nColumns, typename Other>
    Matrix<T, nRows, nColumns> 
        add(const Matrix<T, nRows, nColumns>& lhs, const Other& other)
        {
            return add(lhs, Matrix<T, nRows, nColumns>(other));
        }

template <typename T, std::size_t nRows, std::size_t nColumns, typename Other>
    Matrix<T, nRows, nColumns> 
        add(const Other& other, const Matrix<T, nRows, nColumns>& rhs)
        {
            return add(Matrix<T, nRows, nColumns>(other), rhs);
        }

template <typename T, std::size_t nRows, std::size_t nColumns>
    Matrix<T, nRows, nColumns> 
        operator+(const Matrix<T, nRows, nColumns>& lhs, const Matrix<T, nRows, nColumns>& rhs)
        {
            return add(lhs, rhs);
        }

template <typename T, std::size_t nRows, std::size_t nColumns, typename Other>
    Matrix<T, nRows, nColumns> 
        operator+(const Matrix<T, nRows, nColumns>& lhs, const Other& other)
        {
            return add(lhs, other);
        }

template <typename T, std::size_t nRows, std::size_t nColumns, typename Other>
    Matrix<T, nRows, nColumns> 
        operator+(const Other& other, const Matrix<T, nRows, nColumns>& rhs)
        {
            return add(other, rhs);
        }

/*

template <typename T, std::size_t nRows, std::size_t nColumns>
    Matrix<T, nRows, nColumns> 
        subtract(const Matrix<T, nRows, nColumns>& lhs, const Matrix<T, nRows, nColumns>& rhs);

template <typename T, std::size_t nRows, std::size_t nColumns>
    Matrix<T, nRows, nColumns> 
        multiply(const Matrix<T, nRows, nColumns>& lhs, const Matrix<T, nRows, nColumns>& rhs);

template <typename T, std::size_t nRows, std::size_t nColumns>
    Matrix<T, nRows, nColumns> 
        divide(const Matrix<T, nRows, nColumns>& lhs, const Matrix<T, nRows, nColumns>& rhs);

template <typename T, std::size_t nRows, std::size_t nColumns>
    Matrix<T, nRows, nColumns> 
        inverse(const Matrix<T, nRows, nColumns>& matrix);

template <typename T, std::size_t nRows, std::size_t nColumns>
    Matrix<T, nRows, nColumns> 
        transpose(const Matrix<T, nRows, nColumns>& matrix);

*/

} 

#include "Matrix.cpp"