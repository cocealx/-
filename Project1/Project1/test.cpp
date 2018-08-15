////leet_code 62
////һ��������λ��һ�� m x n ��������Ͻ� ����ʼ������ͼ�б��Ϊ��Start�� ����
////
////������ÿ��ֻ�����»��������ƶ�һ������������ͼ�ﵽ��������½ǣ�����ͼ�б��Ϊ��Finish������
////
////���ܹ��ж�������ͬ��·����
//#include<vector>
//#include<iostream>
//using namespace std;
//class Solution1{
//public:
//	int uniquePaths(int m, int n) {
//		if (n == 1)
//			return 1;
//		vector<int>ret;
//		ret.resize(m, 1);
//		for (int i = 0; i<n - 1; i++)
//		{
//			for (int j = 1; j<m; ++j)
//				ret[j] += ret[j - 1];
//		}
//		return ret[m - 1];
//	}
//
//};
//leet_code 63
//һ��������λ��һ�� m x n ��������Ͻ� ����ʼ������ͼ�б��Ϊ��Start�� ����
//
//������ÿ��ֻ�����»��������ƶ�һ������������ͼ�ﵽ��������½ǣ�����ͼ�б��Ϊ��Finish������
//
//���ܹ��ж�������ͬ��·����
//�����е��ϰ���Ϳ�λ�÷ֱ��� 1 �� 0 ����ʾ��


//class Solution {
//public:
//	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//		int n = obstacleGrid.size();
//		if (n == 0)
//			return 0;
//		vector<int>ret;
//		int m = obstacleGrid[0].size();
//		ret.resize(m, !obstacleGrid[0][0]);
//	
//		for (auto i = 1; i<m; ++i)
//		{
//			if (obstacleGrid[0][i] || ret[i - 1] == 0)
//				ret[i] = 0;
//			else
//				ret[i] = !obstacleGrid[0][i];
//		}
//		int j = 1;
//		for (; j<n; j++)
//		{
//			if (obstacleGrid[j][0] == 1)
//				ret[0] = 0;
//			for (int i = 1; i<m; ++i)
//			if (obstacleGrid[j][i] != 1)
//			{
//				ret[i] += ret[i - 1];
//			}
//			else
//			{
//				ret[i] = 0;
//			}
//		}
//		return ret[m - 1];
//	}
//};
//int main()
//{
//	int array[3][3] = { { 0, 0, 0 }, { 0, 1, 0 }, { 0, 0, 0 } };
//	vector<vector<int>>m;
//	m.resize(3);
//	for (int i = 0; i < 3; i++)
//	{
//		m[i].resize(3);
//		for (int j = 0; j < 3; j++)
//		{
//			m[i][j] = array[i][j];
//		}
//	}
//	Solution s1;
//	s1.uniquePathsWithObstacles(m);
//}

//
////Leet_code 64 ��С·����
////����һ�������Ǹ������� m x n �������ҳ�һ�������Ͻǵ����½ǵ�·����ʹ��·���ϵ������ܺ�Ϊ��С��
////
////˵����ÿ��ֻ�����»��������ƶ�һ����
////
////ʾ�� :
////
////���� :
////	[
////		[1, 3, 1],
////		[1, 5, 1],
////		[4, 2, 1]
////	]
////��� : 7
////���� : ��Ϊ·�� 1��3��1��1��1 ���ܺ���С��
//
//
//#include<algorithm>
//class Solution {
//public:
//	int minPathSum(vector<vector<int>>& grid) {
//		vector<int> ret;
//		int n = grid.size();
//		if (n == 0)
//			return 0;
//		int m = grid[0].size();
//		ret.resize(m);
//		ret[0] = grid[0][0];
//		for (int k = 1; k<m; k++)
//		{
//			ret[k] = ret[k - 1] + grid[0][k];
//		}
//		for (int i = 1; i<n; i++)
//		{
//			ret[0] += grid[i][0];
//			for (int j = 1; j<m; ++j)
//			{
//				ret[j] = min(ret[j], ret[j - 1]) + grid[i][j];
//			}
//		}
//		return ret[m - 1];
//	}
//};
//int main()
//{
//	int array[3][3] = { { 1, 3, 1 }, { 1, 5, 1 }, { 4, 2, 1 } };
//	vector<vector<int>>m;
//	m.resize(3);
//	for (int i = 0; i < 3; i++)
//	{
//		m[i].resize(3);
//		for (int j = 0; j < 3; j++)
//		{
//			m[i][j] = array[i][j];
//		}
//	}
//	Solution s1;
//	cout << s1.minPathSum(m) << endl   ;
//}


#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//int find(vector<int>&array, vector<int>&brray, int size)
//{
//	int count = 0;
//	vector<int>maxa(array);
//	vector<int>minb(brray);
//	int ci = size;
//	while (ci>0)
//	{
//		for (int j = 0; j < ci; j++)
//		{
//			if (maxa[j] < minb[j])
//				++count;
//		}
//		for (int j = 0; j < ci - 1; j++)
//		{
//			maxa[j] = max(maxa[j], maxa[j + 1]);
//			minb[j] = min(minb[j], minb[j + 1]);
//		}
//		--ci;
//	}
//	return count;
//}
//
//int main()
//{
//	vector<int>array;
//	vector<int>brray;
//	int n = 0;
//	cin >> n;
//	array.resize(n);
//	brray.resize(n);
//	for (auto i = 0; i < n; i++)
//		cin >> array[i];
//	for (auto i = 0; i < n; i++)
//		cin >> brray[i];
//	cout << find(array, brray, n) << endl;
//	return 0;
//}


////����һ���ַ��� (s) ��һ���ַ�ģʽ (p)��ʵ��֧�� '.' �� '*' ��������ʽƥ�䡣

//'.' ƥ�����ⵥ���ַ���
//'*' ƥ���������ǰ���Ԫ�ء�
//ƥ��Ӧ�ø��������ַ���(s) �������ǲ����ַ�����
//
//˵�� :
//
//s ����Ϊ�գ���ֻ������ a - z ��Сд��ĸ��
//p ����Ϊ�գ���ֻ������ a - z ��Сд��ĸ���Լ��ַ�.�� *��
//s = "mississippi"
//p = "mis*is*p*."
//s = "aa"
//p = "a*"
//class Solution {
//public:
//	bool isMatch(string s, string p) {
//		if (!s.empty() && p.empty())
//			return false;
//		if (p.size() == 1)
//		{
//			if (p.size() == 1)
//			{
//				if (p[0] == s[0] || p[0] == '.')
//					return true;
//				else
//					return false;
//			}
//		}
//	}
//};
//#include<string>
//int main()
//{
//	string s;
//	///string���Զ���������뺯��
//	getline(cin, s);
//	char buf[1024];
//	cin.getline(buf,1024);
//	string p(buf);
//	Solution s1;
//	if (s1.isMatch(s, p))
//		cout << "yes" << endl;
//	else
//		cout << "NO" << endl;
//	return 0;
//}

