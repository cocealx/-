////leet_code 62
////一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
////
////机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
////
////问总共有多少条不同的路径？
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
//一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
//
//机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
//
//问总共有多少条不同的路径？
//网格中的障碍物和空位置分别用 1 和 0 来表示。


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
////Leet_code 64 最小路径和
////给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
////
////说明：每次只能向下或者向右移动一步。
////
////示例 :
////
////输入 :
////	[
////		[1, 3, 1],
////		[1, 5, 1],
////		[4, 2, 1]
////	]
////输出 : 7
////解释 : 因为路径 1→3→1→1→1 的总和最小。
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


////给定一个字符串 (s) 和一个字符模式 (p)。实现支持 '.' 和 '*' 的正则表达式匹配。

//'.' 匹配任意单个字符。
//'*' 匹配零个或多个前面的元素。
//匹配应该覆盖整个字符串(s) ，而不是部分字符串。
//
//说明 :
//
//s 可能为空，且只包含从 a - z 的小写字母。
//p 可能为空，且只包含从 a - z 的小写字母，以及字符.和 *。
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
//	///string类自定义的流输入函数
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

