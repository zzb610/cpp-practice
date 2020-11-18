class Matrix
{
public:
    Matrix(int row, int col) : row_(row), col_(col)
    {
        pmat_ = new double[row * col];
    }
    Matrix &operator=(const Matrix &rhs);
    ~Matrix()
    {
        delete[] pmat_;
    }
    int row() const { return row_; }
    int col() const { return col_; }

private:
    int row_, col_;
    double *pmat_;
};