/*
有一个字符串集合，输出这些字符串集合组成的全排列
eg:
input: "abc"
output: "abc", "acb", "bac", "bca", "cab", "cba"

vector<string> get_full_range(vector<char> &input);
 */
#include<iostream>
#include<vector>
#include<string>
using namespace std;

void _gen_full_range(const vector<char> &input, vector<bool> &occu, vector<string> &res, string &path)
{
	if (path.size() == input.size()){
		res.push_back(path);
		return;
	}
	for(int i=0; i<input.size(); i++) {
		if (occu[i])
			continue;
		path.push_back(input[i]);
		occu[i] = true;
		_gen_full_range(input, occu, res, path);
		path.pop_back();
		occu[i] = false;
	}
	return;
}
vector<string> gen_full_range(vector<char> &input) 
{
	vector<bool> occu(input.size(), false);
	vector<string> res;
	string path;
	_gen_full_range(input, occu, res, path);
	return res;
}
int main()
{
	vector<char> input = {'a', 'b', 'c', 'd'};
	auto rest = gen_full_range(input);
	for (const auto item : rest) {
		std::cout << item << std::endl;
	}
}

/*
难度：中等偏下
LOC：25
关键点：_gen_full_range()
 * */
