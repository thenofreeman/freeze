#include "Matrix.h"

#include <ostream>

namespace ns
{


template <typename T, std::size_t nRows, std::size_t nColumns>
    std::ostream&
        operator<<(std::ostream& os, const Matrix<T, nRows, nColumns>& matrix)
        {
            os << matrix.toString();

            return os;
        }

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

template <typename T, std::size_t nRows, std::size_t nColumns>
    Matrix<T, nRows, nColumns> 
        operator-(const Matrix<T, nRows, nColumns>& rhs)
        {
            Matrix<T, nRows, nColumns> temp;

            for (size_t i = 1; i <= nRows; ++i)
                for (size_t j = 1; j <= nColumns; ++j)
                    temp.at(i, j) = -rhs.at(i, j);

            return temp;
        }

template <typename T, std::size_t nRows, std::size_t nColumns>
    Matrix<T, nRows, nColumns> 
        subtract(const Matrix<T, nRows, nColumns>& lhs, const Matrix<T, nRows, nColumns>& rhs)
        {
            return add(lhs, -rhs);
        }

template <typename T, std::size_t nRows, std::size_t nColumns, typename Other>
    Matrix<T, nRows, nColumns> 
        subtract(const Matrix<T, nRows, nColumns>& lhs, const Other& other)
        {
            return add(lhs, -Matrix<T, nRows, nColumns>(other));
        }

template <typename T, std::size_t nRows, std::size_t nColumns, typename Other>
    Matrix<T, nRows, nColumns> 
        subtract(const Other& other, const Matrix<T, nRows, nColumns>& rhs)
        {
            return add(Matrix<T, nRows, nColumns>(other), -rhs);
        }

template <typename T, std::size_t nRows, std::size_t nColumns>
    Matrix<T, nRows, nColumns> 
        operator-(const Matrix<T, nRows, nColumns>& lhs, const Matrix<T, nRows, nColumns>& rhs)
        {
            return add(lhs, -rhs);
        }

template <typename T, std::size_t nRows, std::size_t nColumns, typename Other>
    Matrix<T, nRows, nColumns> 
        operator-(const Matrix<T, nRows, nColumns>& lhs, const Other& other)
        {
            return add(lhs, -other);
        }

template <typename T, std::size_t nRows, std::size_t nColumns, typename Other>
    Matrix<T, nRows, nColumns> 
        operator-(const Other& other, const Matrix<T, nRows, nColumns>& rhs)
        {
            return add(other, -rhs);
        }

/*

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

template <typename T, std::size_t nRows, std::size_t nColumns>
    Matrix<T, nRows, nColumns> 
        cross(const Matrix<T, nRows, nColumns>& lhs, const Matrix<T, nRows, nColumns>& rhs);

template <typename T, std::size_t nRows, std::size_t nColumns>
    Matrix<T, nRows, nColumns> 
        determinant(const Matrix<T, nRows, nColumns>& matrix);

template <typename T, std::size_t nRows, std::size_t nColumns>
    Matrix<T, nRows, nColumns> 
        trace(const Matrix<T, nRows, nColumns>& matrix);

template <typename T, std::size_t nRows, std::size_t nColumns>
    Matrix<T, nRows, nColumns> 
        operator==(const Matrix<T, nRows, nColumns>& lhs, const Matrix<T, nRows, nColumns>& rhs);

*/

};