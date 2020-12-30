/*
输出合法的括号种类：
eg:
1
()
2
()(), (())
3
((()))
(()())
(())()
()(())
()()()
vector<string> validparentheses(int num);

 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

void validparent(int left, int right, vector<string> &res, string path){
	if (left == 0 && right == 0) {
		res.push_back(path);
		return;
	}
	if (left > 0) {
		//尝试填入左括号
		path.push_back('(');
		validparent(left-1, right, res, path);
		path.pop_back();
	}
	if (right > left && right >0) {
		path.push_back(')');
		validparent(left, right-1, res, path);
		path.pop_back();
	}
	return;
}

vector<string> validparentheses(int num)
{
	string path;
	vector<string> res;
	validparent(num, num, res, path);
	return res;
}

int main() {
	vector<string> res = validparentheses(3);
	for (const auto & item : res) {
		std::cout << item << std::endl;
	}
}

/*
题目难度：中等偏下
LOC：20
考察点：递归&&分治
评分标准：
* 无提示，无bug：5分
* 如果候选人无思路，可以提示使用递归求解
	*提示下给出无bug答案：4分
	*提示下给出答案,bug 少于一个：3～4分
	*提示下无法写出答案，或者bug比较多、比较严重：Fail
*/
