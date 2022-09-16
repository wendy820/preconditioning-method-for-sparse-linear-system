#include<iostream>
/*
1.�˴�ֵ�������������һ��ģ��Ƿ�ĳ�����̳еĹ�ϵ
2.�Խ���Ԫ��Ҫ��Ҫժ���������棬����Ĭ�϶Խ��ߺͷǶԽ���Ԫ�ش�����һ��
3.����洢���ݵ�ԭ�򣬾����������Ƚ���ʵ�֣���Ҫ�ǲ��ÿ��ռ䣩
  �����vector���洢��������������ʵ��
  Ҫ��Ҫ�ĳ�vector���棿
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
		int m_rowNum{ 0 };//��������
		int m_len{ 0 };//�������з���Ԫ�ĸ���
		int* m_rowOffset{ nullptr };//��ƫ������
		int* m_colIndices{ nullptr };//����������
		float* m_value{ nullptr };//ֵ����
		int m_offset;//��ǰ��ƫ��

	};
}
