/*
初始状态:AAAXBBB
最终状态:BBBXAAA

移动规则：
AAAXBBB > AAXABBB
AABXBAB > AXBABAB

如上图所示，有7个左右排列的盒子，里面左侧三个放着字母A，右边三个放着字母B（如图一）。现在需要把A都移动到右边的三个盒子，B移动到左边的三个盒子（如图二）。移动规则如下（如图三）：
● A只能向右移动，B只能向左移动
● 左移（或者右移）只有两种方式
	○ 移动到相邻的位置（此位置必须是空盒子）
	○ 移动到相隔一个盒子的位置（此位置必须是空盒子）
 */
#include<vector>
#include<iostream>
using namespace std;

bool is_end_status(const vector<int> &cur, int num) {
    for (int i = 0; i<num; i++) {
        if (cur[i] >= 0 || cur[cur.size() - num] <=0)
            return false;
    }
    return true;
}

//获取i可以移动的类型：1表示移动，2表示跳跃
vector<int> get_move_types(const vector<int> &array, int i) {
    vector<int> res;
    if (array[i] > 0 ) {
        for (int move_type = 1; move_type <3; move_type ++) {
            if (i+move_type < array.size() && array[i+move_type] == 0) {
                res.push_back(move_type);
            }
        }
    } else if (array[i] < 0) {
        for (int move_type = 1; move_type <3; move_type ++) {
            if (i-move_type >=0 && array[i-move_type] == 0) {
                res.push_back(move_type);
            }
        }
    }
    return res;
}

struct Store {
    Store( int f, int s, vector<int> input) : first(f), second(s), array(input){}
    int first;
    int second;
    vector<int> array;
};
int rotation(vector<int> &array, int num, vector<Store> &res) {
    if (is_end_status(array, num))
        return 0;
    //移动最左侧可以移动的数据
    for (int i = 0; i<array.size(); i++)
    {
        auto move_types = get_move_types(array, i);
        for( const auto type: move_types)
        {
            //move/jump
            int step = array[i] > 0 ? type : -1 * type;
            swap(array[i], array[i+step]);
            res.push_back(Store(i, i+step, array));
            if (rotation(array, num, res) == 0)
                return 0;
            else {
                swap(array[i], array[i+step]);
                res.pop_back();
            }
        }
    }
    return -1;
}

int main () {
    int car_num = 3;
    vector<int> input;
    for (int i = 1; i<= car_num; i++) {
        input.push_back(1);
    }
    input.push_back(0);
    for (int i = 1; i<= car_num; i++) {
        input.push_back(-1);
    }
    for (const auto data : input)
        std::cout << data << " ";
    std::cout << std::endl;
    vector<Store> store;
    int ans = rotation(input, car_num, store);
    if (ans == 0) {
        for (const auto p : store) {
            std::cout << p.first << "<>" << p.second << " : ";
            for (const auto data : p.array)
                std::cout << data << " ";
            std::cout << std::endl;
        }
    } else {
        std::cout << "no ans" << std::endl;
    }
    std::cout << "total step:" << store.size()   << std::endl;
    return 0;
}

/*
难度：中等偏上
LOC:  55
考察点：递归解决思路的清晰与代码的简洁性
*/
