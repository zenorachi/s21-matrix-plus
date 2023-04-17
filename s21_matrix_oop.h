#include <cmath>
#include <iostream>

class S21Matrix {
 public:
  // CONSTRUCTORS
  S21Matrix() noexcept;
  explicit S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other) noexcept;
  S21Matrix(S21Matrix&& other) noexcept;

  // DESTRUCTOR
  ~S21Matrix();

  // MATRIX-OPERATIONS
  bool EqMatrix(const S21Matrix& other) const noexcept;
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose() const;
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  // GETTERS && SETTERS
  int getRows() const noexcept;
  int getCols() const noexcept;
  void setRows(int rows_);
  void setCols(int cols_);

  // OPERATORS OVERLOADING
  S21Matrix operator+(const S21Matrix& other) const;
  S21Matrix operator-(const S21Matrix& other) const;
  S21Matrix operator*(const S21Matrix& other) const;
  S21Matrix operator*(const double num) const;
  bool operator==(const S21Matrix& other) const noexcept;
  bool operator!=(const S21Matrix& other) const noexcept;
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator*=(const double num);
  double& operator()(int i, int j);

  void debug() {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        std::cout << matrix_[i][j] << " ";
      }
      std::cout << std::endl;
    }
  }

 private:
  int rows_, cols_;
  double** matrix_;
  void __initialize();
  bool __equalSize(const S21Matrix& other) const noexcept;
  void __getOffsetMatrix(int row, int col, S21Matrix* tmp);
  void __getDeterminant(double** matrix, int size, double* result);
};