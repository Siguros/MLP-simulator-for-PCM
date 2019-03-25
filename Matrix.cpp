#include "Matrix.h"

Matrix::Matrix()
{
	numrow = 0;
	numcol = 0;
}

Matrix::~Matrix()
{
}

Matrix::Matrix(const int numrow, const int numcol, const bool init)
{
	this->numrow = numrow;
	this->numcol = numcol;
	for (int row = 0; row < numrow; row++) {
		vector<double> vec;
		for (int col = 0; col < numcol; col++) {
			vec.push_back(0);
		}
		val.push_back(vec);
		vec.clear();
	}
	if (init == true) {
		for (int row = 0; row < numrow; row++) {
			for (int col = 0; col < numcol; col++) {
				val.at(row).at(col) = 0;
			}
		}
	}
}

void Matrix::Initialize(const int numrow, const int numcol, const bool r)
{
	
	this->numrow = numrow;
	this->numcol = numcol;

	for (int row = 0; row < numrow; row++) {
		vector<double> vec;
		for (int col = 0; col < numcol; col++) {
			vec.push_back(0);
		}
		val.push_back(vec);
		vec.clear();
	}
	if (r == true) {
		this->RandMatrix();
	}
}

void Matrix::RandMatrix()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<double> dist(0, 1);
	for (int row = 0; row < numrow; row++) {
			for (int col = 0; col < numcol; col++) {
				val.at(row).at(col) = dist(rd);
			}
		}

	
}

void Matrix::SetMatrix(int rowidx, int colidx, double val)
{
	this->val.at(rowidx).at(colidx) = val;
}

const double Matrix::GetVal(int rowidx, int colidx)
{
	return val.at(rowidx).at(colidx);
}

void Matrix::printMatrx()
{
	cout << "==========" << "MATRIX" << "===========" << endl;
	for (int row = 0; row < numrow; row++) {
		for (int col = 0; col < numcol; col++) {
			cout << val.at(row).at(col) << " ";
		}
		cout << endl;
	}

}

const vector<vector<double>>& Matrix::GetVector() const
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	return this->val;
}


Matrix Matrix::MatrixMultply(const Matrix & m)
{
	assert(numcol == m.numrow);
	Matrix result(numrow, m.numcol,true);

	for (int row = 0; row < numrow; row++) {
		for (int col = 0; col < numcol; col++) {
			for (int mcol = 0; mcol < m.numcol; mcol++) {
				double val = (this->val.at(row).at(col))*(m.val.at(col).at(mcol));
				result.val.at(row).at(mcol) += val;
			}
		}
	}
	return result;
}

Matrix Matrix::TransPose()
{
	Matrix result;
	result.Initialize(this->numcol, this->numrow, true);
	for (int row = 0; row < numrow; row++) {
		for (int col = 0; col < numcol; col++) {
			result.val.at(col).at(row) = this->val.at(row).at(col);
		}
	}

	return result;
}

Matrix Matrix::DotMultplyMat(const Matrix & m)
{
	assert(numcol == m.numcol);
	assert(numrow == m.numrow);
	Matrix result;
	result = m;
	for (int row = 0; row < numrow; row++){
		for (int col = 0; col < numcol; col++) {
			double val = this->GetVal(row, col)*result.GetVal(row, col);
			result.SetMatrix(row, col, val);
		}
	}
	return result;
}

Matrix Matrix::DotMultplyVec(const Matrix & m)
{
	assert(numrow = m.numrow);
	assert(m.numcol == 1);
	Matrix result;
	Matrix m1;
	m1 = m;
	result.Initialize(numrow, numcol, false);
	for (int row = 0; row < numrow; row++) {
		for (int col = 0; col < numcol; col++) {
			double val = this->GetVal(row, col)*m1.GetVal(row, 0);
			result.SetMatrix(row, col, val);
		}
	}
	return result;

}
