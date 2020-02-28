#ifndef PRACTICE_00_MATRIX_MATRIX_H_
#define PRACTICE_00_MATRIX_MATRIX_H_

#include <array>
#include <algorithm>
#include <string>
#include <sstream>

namespace practice_00
{
namespace matrix
{

/// \brief This is mathmatical matrix class
///
/// \tparam ValueType thie is type of the matrix elements. this could be float, double, int, etc.
/// \tparam rows matrix max rows
/// \tparam cols matrix max columns
template <typename ValueType, unsigned int rows, unsigned int cols>
class Matrix
{
public:
    /// \brief Constructor of the Matrix
    ///
    Matrix() {}
    /// \brief Constructor of the Matrix from initialization list
    ///
    /// \param data initialization list
    Matrix(const std::array<ValueType, cols * rows> &data)
    {
        std::copy(data.begin(), data.end(), data_.begin());
    }
    /// \brief Copy constructor of the Matrix. this is deep copy
    ///
    /// \param other reference of copy
    Matrix(Matrix &other)
    {
        std::copy(other.data_.begin(), other.data_.end(), data_.begin());
    }

    /// \brief Access the element of the matrix with row and column indices.
    ///
    /// \param row row index
    /// \param col column index
    /// \return ValueType& lvalue of the element
    ValueType &at(unsigned int row, unsigned int col)
    {
        return data_[cols * row + col];
    }

    /// \brief String casting operator. You can get pretty formatted strings from this operator.
    ///
    /// \return std::string formatted matrix string.
    operator std::string()
    {
        std::string str;
        std::stringstream sstr;
        for (unsigned int i = 0; i < rows; ++i)
        {
            sstr << "[ ";
            for (unsigned int j = 0; j < cols - 1; ++j)
            {
                sstr << at(i, j) << ",\t";
            }
            sstr << at(i, cols - 1) << " ]\n";
        }
        return sstr.str();
    }

    /// \brief scalar product operator
    ///
    /// \param val scalar value
    /// \return Matrix scalar product result matrix.
    Matrix operator*(float val)
    {
        Matrix mat(*this);
        auto iter = mat.data_.begin();
        auto end = mat.data_.end();
        while (iter != end)
        {
            (*iter) = (*iter) * val;
            iter++;
        }
        return mat;
    }

    /// \brief matrix sum operator
    ///
    /// \param other second matrix operand. the rows and the cols of second matrix should match to the first one.
    /// \return Matrix matrix sum result.
    Matrix operator+(Matrix<ValueType, rows, cols> &other)
    {
        Matrix mat(*this);
        auto iter = mat.data_.begin();
        auto iter_other = other.data_.begin();
        auto end = mat.data_.end();
        while (iter != end)
        {
            (*iter) += (*iter_other);
            iter++;
            iter_other++;
        }
        return mat;
    }
    /// \brief Matrix inner product operator
    ///
    /// \tparam other_rows second matrix operand's rows
    /// \tparam other_cols second matrix operand's cols
    /// \param other second matrix operand
    /// \return Matrix matrix inner product result.
    template <unsigned int other_rows, unsigned int other_cols>
    Matrix operator*(Matrix<ValueType, other_rows, other_cols> &other)
    {
        Matrix<ValueType, rows, other_cols> result;
        for (unsigned int i = 0; i < rows; ++i)
        {
            for (unsigned int j = 0; j < other_cols; ++j)
            {
                for (unsigned int k = 0; k < cols; ++k)
                {
                    result.at(i, j) += at(i, k) * other.at(k, j);
                }
            }
        }
        return result;
    }
    /// \brief Matrix Copy assignment operator
    ///
    /// \param other reference matrix
    /// \return Matrix assigned matrix
    Matrix &operator=(const Matrix &other)
    {
        std::copy(other.data_.begin(), other.data_.end(), data_.begin());
        return *this;
    }

    /// \brief Set this matrix as identity matrix.
    ///
    void SetIdentity()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (i == j)
                {
                    at(i, j) = 1;
                }
                else
                {
                    at(i, j) = 0;
                }
            }
        }
    }

    /// \brief Set this matrix as zero matrix.
    ///

    void SetZero()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                at(i, j) = 0;
            }
        }
    }

private:
    /// \brief matrix elements data
    std::array<ValueType, rows * cols> data_;
};

} // namespace matrix
} // namespace practice_00
#endif // MATRIX_MATRIX_H_
