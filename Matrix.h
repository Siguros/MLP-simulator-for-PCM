#pragma once
#include <vector>
#include <iostream>
#include <ctime>
#include <random>
#include <assert.h>
using namespace std;

class Matrix {
private:
	int numrow;
	int numcol;
	vector<vector<double>> val;

public:
	// initialize
	Matrix();
	~Matrix();
	Matrix(const int numrow, const int numcol, const bool init);
	void Initialize(const int numrow, const int numcol, const bool r);
	// property function
	void RandMatrix();
	void SetMatrix(int rowidx, int colidx, double val);
	const double GetVal (int rowidx, int colidx);
	void printMatrx();
	const vector<vector<double>>& GetVector()const;
	const int GetRow() const{ return this->numrow; }
	const int GetCol() const{ return this->numcol; }
	//functional function
	Matrix MatrixMultply(const Matrix &m);
	Matrix TransPose();
	Matrix DotMultplyMat(const Matrix&m);
	Matrix DotMultplyVec(const Matrix& m);
	// operator
	void operator==(Matrix &m) {
		this->numrow = m.numrow;
		this->numcol = m.numcol;
		this->val = m.GetVector();
	}
	void operator+=(const Matrix &m) {
		assert(numcol = m.numcol);
		assert(numrow = m.numrow);
		for (int row = 0; row < numrow; row++) {
			for (int col = 0; col < numcol; col++) {
				this->val.at(row).at(col) += m.val.at(row).at(col);
			}
		}
	}
	void operator-=(const Matrix &m) {
		assert(numcol = m.numcol);
		assert(numrow = m.numrow);
		for (int row = 0; row < numrow; row++) {
			for (int col = 0; col < numcol; col++) {
				this->val.at(row).at(col) -= m.val.at(row).at(col);
			}
		}
	}
	Matrix operator+(const Matrix &m) {
		assert(numcol = m.numcol);
		assert(numrow = m.numrow);
		Matrix result;
		result = m;
		for (int row = 0; row < numrow; row++) {
			for (int col = 0; col < numcol; col++) {
				result.val.at(row).at(col) += this->val.at(row).at(col);
			}
		}
		return result;
	}
	Matrix operator-(const Matrix &m) {
		assert(numcol = m.numcol);
		assert(numrow = m.numrow);
		Matrix result;
		result = m;
		for (int row = 0; row < numrow; row++) {
			for (int col = 0; col < numcol; col++) {
				result.val.at(row).at(col) -= this->val.at(row).at(col);
			}
		}
		return result;
	}
	Matrix operator*(const double& m) {
		Matrix result;
		result.Initialize(this->numrow, this->numcol, false);
		for (int row = 0; row < numrow; row++) {
			for (int col = 0; col < numcol; col++) {
				result.val.at(row).at(col) = this->val.at(row).at(col)*m;
			}
		}
		return result;
	}
};