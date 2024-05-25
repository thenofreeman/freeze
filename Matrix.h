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

        Matrix<T, nRows, nColumns>& operator=(Matrix<T, nRows, nColumns>&& other) noexcept;

        const T& at(std::size_t row, std::size_t col) const;
        T& at(std::size_t row, std::size_t col);

        std::pair<int, int> getDimensions() const;
    
    public:

    private:

    private:
        std::array<T, nRows + nColumns> elements;

};

} 

#include "Matrix.cpp"
#include "MatrixOperations.cpp"