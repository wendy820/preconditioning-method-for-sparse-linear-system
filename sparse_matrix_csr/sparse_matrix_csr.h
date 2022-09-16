#include<iostream>
/*
1.此处值数组和行列是在一起的，是否改成子类继承的关系
2.对角线元素要不要摘出来单独存，这里默认对角线和非对角线元素存在了一起
3.数组存储数据的原因，矩阵基本运算比较难实现（主要是不好开空间）
  如果用vector来存储，矩阵基本运算好实现
  要不要改成vector来存？
*/
namespace SparseMatrix
{
	class CSR
	{
	public:
		CSR();
		CSR(const int& rowNum, const int& len);
		~CSR();
		int& getRowNum();
		int& getLen();
		int* getRowOffset();
		int* getColIndices();
		void insertColsValsByRow(const int& rowNo, int* colIndices, const int colIndicesNum, float* vals, const int valNum);
		void getColIndicesByRow(const int& rowNo,int*& colIndices,int& colIndicesNum);
		void getValue(const int& rowNo, const int& colNo, float& val);
		void getValuesByRow(const int& rowNo, float*& vals, int& valNum);
		

	private:
		int m_rowNum{ 0 };//矩阵行数
		int m_len{ 0 };//矩阵所有非零元的个数
		int* m_rowOffset{ nullptr };//行偏移数组
		int* m_colIndices{ nullptr };//列索引数组
		float* m_value{ nullptr };//值数组
		int m_offset;//当前行偏移

	};
}
