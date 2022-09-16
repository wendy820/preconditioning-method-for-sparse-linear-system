#include "sparse_matrix_csr.h"

SparseMatrix::CSR::CSR()
{
}

SparseMatrix::CSR::CSR(const int& rowNum, const int& len)
{
	m_len = len;
	m_rowNum = rowNum;
	m_rowOffset = new int[rowNum + 1]();
	m_colIndices = new int[len + 1]();
	m_offset = 0;
	m_value = new float[len + 1]();
}

SparseMatrix::CSR::~CSR()
{
	delete[] m_colIndices;
	delete[] m_rowOffset;
	delete[] m_value;
}

int& SparseMatrix::CSR::getRowNum()
{
	return m_rowNum;
}

int& SparseMatrix::CSR::getLen()
{
	return m_len;
}

int* SparseMatrix::CSR::getRowOffset()
{
	return m_rowOffset;
}

int* SparseMatrix::CSR::getColIndices()
{
	return m_colIndices;
}

void SparseMatrix::CSR::getColIndicesByRow(const int& rowNo, int*& colIndices, int& colIndicesNum)
{
	colIndices =& m_colIndices[m_rowOffset[rowNo]];
	colIndicesNum = m_rowOffset[rowNo + 1] - m_rowOffset[rowNo];
}

void SparseMatrix::CSR::insertColsValsByRow(const int& rowNo, int* colIndices, const int colIndicesNum, float* vals, const int valNum)
{
	memcpy((void*)(m_colIndices + m_offset), (void*)colIndices, 4 * colIndicesNum);
	memcpy((void*)(m_value + m_offset), (void*)vals, 4 * valNum);
	m_offset += colIndicesNum;
	m_rowOffset[rowNo + 1] = m_offset;
}

void SparseMatrix::CSR::getValue(const int& rowNo, const int& colNo, float& val)
{
	for (int i = m_rowOffset[rowNo]; i < m_rowOffset[rowNo+1]; i++)
	{
		if (m_colIndices[i] == colNo)
			val = m_value[i];
	}
}

void SparseMatrix::CSR::getValuesByRow(const int& rowNo, float*& vals, int& valNum)
{
	vals = &m_value[m_rowOffset[rowNo]];
	valNum = m_rowOffset[rowNo + 1] - m_rowOffset[rowNo];
}
