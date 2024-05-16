1.基于LBS的司、乘信息查询

在网约车场景下，每次打开乘客端，输入起点，就会展示周边小车。设计一个在线服务，实现如下的功能，讲明算法、数据结构、公共组件。

* 司机侧

- 上线: `void online(int did, int lng, int lat)`
- 下线：`void offline(int did)`
- 移动: `void moveTo(int lng, int lat)`, 对于每个已经上线的司机，司机平均2s移动一次


* 乘客侧

- 查询乘客直线距离`周边3KM`内，距离乘客`路面距离`最近的10个司机：返回这些司机的坐标。 `std::vector<Point> getNearbyDrivers(int lng, int lat)`


说明：

司机、乘客的位置使用坐标来表示Point <lat, lng>，为了简化，假设lat/lng均为整数，范围为[0, 100KM)，且假设司机乘客所在空间为平面直角坐标系之下。

路面距离的查询可以调用接口 `int getDistance(Point from, Point to)`获取，但是本接口按次收费，尽可能少减少调用。直线距离按照欧式距离计算。

本服务的司机侧用户大概有1000W，乘客侧用户为100W，司机/乘客单个用户qps分别为1/2s， 1/10s


