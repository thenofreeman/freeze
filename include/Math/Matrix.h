#pragma once

#include <array>
#include <initializer_list>
#include <iomanip>
#include <sstream>
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

        Matrix<T, nRows, nColumns>& operator=(const Matrix<T, nRows, nColumns>& other);

        const T& at(std::size_t row, std::size_t col) const;
        T& at(std::size_t row, std::size_t col);

        std::pair<int, int> getDimensions() const;

        std::string toString() const;

        friend std::ostream& operator<<(std::ostream& os, const Matrix<T, nRows, nColumns>& matrix)
        {
            os << matrix.toString();

            return os;
        }

        friend bool operator==(const Matrix<T, nRows, nColumns>& lhs, const Matrix<T, nRows, nColumns>& rhs)
        {
            for (size_t i = 1; i <= nRows; ++i)
                for (size_t j = 1; j <= nColumns; ++j)
                    if (lhs.at(i, j) != rhs.at(i, j))
                        return false;

            return true;
        }

        friend Matrix<T, nRows, nColumns> add(const Matrix<T, nRows, nColumns>& lhs, const Matrix<T, nRows, nColumns>& rhs)
        {
            if (lhs.getDimensions() != rhs.getDimensions())
                throw std::invalid_argument("Matrices being operated on have different dimensions.");

            Matrix<T, nRows, nColumns> temp;

            for (size_t i = 1; i <= nRows; ++i)
                for (size_t j = 1; j <= nColumns; ++j)
                    temp.at(i, j) = lhs.at(i, j) + rhs.at(i, j);

            return temp;
        }

        friend Matrix<T, nRows, nColumns> operator+(const Matrix<T, nRows, nColumns>& lhs, const Matrix<T, nRows, nColumns>& rhs)
        {
            return add(lhs, rhs);
        }

        friend Matrix<T, nRows, nColumns> subtract(const Matrix<T, nRows, nColumns>& lhs, const Matrix<T, nRows, nColumns>& rhs)
        {
            if (lhs.getDimensions() != rhs.getDimensions())
                throw std::invalid_argument("Matrices being operated on have different dimensions.");

            Matrix<T, nRows, nColumns> temp;

            for (size_t i = 1; i <= nRows; ++i)
                for (size_t j = 1; j <= nColumns; ++j)
                    temp.at(i, j) = -rhs.at(i, j);

            return temp;
        }

        friend Matrix<T, nRows, nColumns> operator-(const Matrix<T, nRows, nColumns>& lhs, const Matrix<T, nRows, nColumns>& rhs)
        {
            return subtract(lhs, rhs);
        }

        friend Matrix<T, nRows, nColumns> operator-(const Matrix<T, nRows, nColumns>& rhs)
        {
            return subtract(0, rhs);
        }
    
    public:

    private:

    private:
        std::array<T, nRows * nColumns> elements;

};

} 

#include "Matrix.tpp"
#include "MatrixOperations.tpp"