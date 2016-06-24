#include<iostream>
#include<cmath>
#include<ctime>
#include<vector>
#include<cstring>
#include<tuple>
#include<fstream>
#include<sstream>
using namespace std;

#define K 5
#define MAXSIZE 100
typedef vector<double>Tuple;
int dimNum;		//数据的维数，即课程数
int dataNum;		//数据量的大小，即所有学生所有课程的成绩的数量

double getMax(const vector<Tuple>& tuples,int col);		//取得当前列的最大值
double getMin(const vector<Tuple>& tuples,int col);		//取得当前列的最小值
void normalize(vector<Tuple>&tuples);		//将元组正规化

double getDistance(const Tuple &t1, const Tuple &t2);		//利用欧几里得距离计算两个元组之间的相异度
char clusterOfTuple(Tuple means[],const Tuple &tuple);		//为元组聚类

Tuple moveCentroids(vector<Tuple> cluster);		//移动质心
double getCentroids(vector<Tuple>clusters[], Tuple means[]);		//得到质心与它所在的簇的距离
bool selected(int n, vector<int>v, const vector<Tuple>tuples);		//判断某随机数是否已经生成
void KMeans(vector<Tuple>& tuples);		//K-Means算法，进行质心初始化和聚类
void print(Tuple means[], const vector<Tuple>& tuples);		//打印出各学生的等级评分

double getMax(const vector<Tuple>& tuples,int col)		//col为元组的属性列，即课程
{
	double max = 0;
	for (int i = 0; i != tuples.size(); ++i){
		if (max < (tuples[i])[col])		//tuples存储了所有的元组，tuples[i]表示第i个元组，(tuples[i])[col]即第i个元组第col列的值
			max = (tuples[i])[col];
	}
	return max;
}

double getMin(vector<Tuple>&tuples, int col)
{
	double min = 0;
	for (int i = 0; i != tuples.size(); ++i){
		if (min >(tuples[i])[col])
			min = (tuples[i])[col];
	}
	return min;
}

void normalize(vector<Tuple>&tuples)
{
	for (int i = 0; i != tuples.size(); ++i){		//遍历每一个元组
		for (int j = 0; j != dimNum; ++j){		//遍历每一个元组中的每一个属性列
			(tuples[i])[j] = ((tuples[i])[j] - getMin(tuples, j)) / (getMax(tuples, j) - getMin(tuples, j));		//对每一个数据进行正规化
		}
	}
}

double getDistance(const Tuple &t1, const Tuple &t2)		
{
	double dis = 0;
	for (int i = 0; i != dimNum; ++i){
		dis += (t1[i] - t2[i]) * (t1[i] - t2[i]);
	}
	return sqrt(dis);
}

char clusterOfTuple(Tuple means[], const Tuple &tuple)
{
	char labelOfTuple;
	int j = 0;		//用来存储相异度最小时的质心的编号
	double minDis = getDistance(means[0], tuple);
	//cout << minDis << endl;
	for (int i = 1; i != K; ++i){
		if (minDis > getDistance(means[i], tuple)){		//求出离当前元组最近的质心
			minDis = getDistance(means[i], tuple);		
			j = i;
		}
	}
	switch (j){		//根据编号来为每一个元组设定标签，距第一个质心最近的元组标记为A，以此类推
	case 0:	labelOfTuple = 'A'; break;
	case 1:	labelOfTuple = 'B'; break;
	case 2:	labelOfTuple = 'C'; break;
	case 3:	labelOfTuple = 'D'; break;
	case 4:	labelOfTuple = 'E'; break;
	default:	cout << "error:can't find out any means cluster belongs to   "; break;
	}
	return labelOfTuple;
}

double getCentroids(vector<Tuple>clusters[], Tuple means[])
{
	double var = 0;
	for (int i = 0; i != K; ++i){
		for (int j = 0; j != clusters[i].size(); ++j){
			var += getDistance((clusters[i])[j], means[i]);		//计算出质心和其所在簇的所有元组的距离和
		}
	}
	return var;
}

Tuple moveCentroids(vector<Tuple> cluster){
	Tuple t(dimNum,0);
	for (int i = 0; i != cluster.size(); ++i){
		for (int j = 0; j != dimNum; ++j){
			t[j] += (cluster[i])[j];
		}
		 }
	for (int i = 0; i != dimNum; ++i){
		t[i] /= cluster.size();
	}
	return t;
}

void print(Tuple means[],const vector<Tuple>&tuples)
{
	cout << "\nThe result is : " << endl;
	for (int i = 0; i != tuples.size(); ++i){
		switch (i){
		case 0:	cout << "迪迦\t" << clusterOfTuple(means, tuples[i])<<endl; break;		//第一个元组表示的是第一个学生，第一个学生名字是迪迦，以此类推
		case 1:	cout << "雷欧\t" << clusterOfTuple(means, tuples[i]) << endl; break;
		case 2:	cout << "怪兽\t" << clusterOfTuple(means, tuples[i]) << endl; break;
		case 3:	cout << "奥特之王\t" << clusterOfTuple(means, tuples[i]) << endl; break;
		case 4:	cout << "奥特之母\t" << clusterOfTuple(means, tuples[i]) << endl; break;
		case 5:	cout << "奥特之父\t" << clusterOfTuple(means, tuples[i]) << endl; break;
		case 6:	cout << "光之使者\t" << clusterOfTuple(means, tuples[i]) << endl; break;
		case 7:	cout << "梦比优斯\t" << clusterOfTuple(means, tuples[i]) << endl; break;
		case 8:	cout << "赛文\t" << clusterOfTuple(means, tuples[i]) << endl; break;
		case 9:	cout << "泰罗\t" << clusterOfTuple(means, tuples[i]) << endl; break;
		default:	cout << "error:This name doesn't exists!\n"; break;
		}
	}
}

bool selected(int n, vector<int>v,const vector<Tuple>tuples)
{
	static int log = 0;
	static int flag = 0;
	if (n == 0 && flag == 0){
		flag = 1;
		v[log++] = n;
		return false;
	}else{
		for (int i = 0; i != v.size(); ++i){
			if (v[i] == n)
				return true;
		}
	}
	//cout << log <<"  "<<flag<<"  "<<n<< endl;
	v[log ++] = n;
	return false;
}



void KMeans(vector<Tuple>& tuples)
{
	vector<Tuple> clusters[K];		//定义了K个簇，每一个簇里都存放了其所包含的元组
	Tuple means[K];			//定义了K个质心
	/*手动初始化质心*/
	for (int j = 0; j != dimNum; ++j){
		means[0].push_back((tuples[8])[j]);
	}
	for (int j = 0; j != dimNum; ++j){
		means[1].push_back((tuples[0])[j]);
	}
	for (int j = 0; j != dimNum; ++j){
		means[2].push_back((tuples[7])[j]);
	}
	for (int j = 0; j != dimNum; ++j){
		means[3].push_back((tuples[5])[j]);
	}
	for (int j = 0; j != dimNum; ++j){
		means[4].push_back((tuples[6])[j]);
	}
	/*随机初始化质心*/
	/*srand( time(0));
	vector<int>judgeSelect(tuples.size());
	for (int i = 0; i != K;){
		int select = rand() % tuples.size();
		if (!selected(select,judgeSelect,tuples)){
			for (int k = 0; k != dimNum; ++k){
				means[i].push_back((tuples[select])[k]);
			}
			++i; 
		}
	}*/
	cout << "Initialize means to : " << endl;
	for (int i = 0; i != K; ++i){
		for (int j = 0; j != dimNum; ++j){
			cout << means[i][j] << "  ";
		}
		cout << endl;
	}
	char label;		//设定标签，即学生的等级
	for (int i = 0; i != tuples.size(); ++i){
		label = clusterOfTuple(means, tuples[i]);		//标签是根据元组所在的簇得到的
		clusters[label - 65].push_back(tuples[i]);		//label-65是将字母转换为数字。如'A'-65等于0
	}
	double oldCentroids = 0;		//旧的中心值
	double newCentroids = getCentroids(clusters,means);		//新的中心值
	while ((newCentroids - oldCentroids) != 0){		//当新的中心不再变化时，说明质心已收敛
		oldCentroids = newCentroids;
		for (int i = 0; i != K; ++i){
			means[i] = moveCentroids(clusters[i]);		//移动质心
		}
		for (int i = 0; i != K; ++i){		//清空每一个簇
			clusters[i].clear();
		}
		for (int i = 0; i != tuples.size(); ++i){			//根据新的质心对元组重新进行划分
			label = clusterOfTuple(means, tuples[i]);
			clusters[label - 65].push_back(tuples[i]);
		}
		newCentroids = getCentroids(clusters, means);
	}
		print(means,tuples);		
}

int main()
{
	char filename[256];
	cout << "Input file name contains datas we need: ";
	cin >> filename;
	cout << "Input the number of courses: ";
	cin >> dimNum;
	cout << "Input the total datas: ";
	cin >> dataNum;
	ifstream infile;
	infile.open(filename);
	if(!infile){
		cout << "error: " << filename << " doesn't exist in current directory!" << endl;
		system("pause");
		return -1;
	}
	vector<Tuple>tuples;		//用于存放所有元组
	for (int i = 0; i != dataNum && !infile.eof(); ++i){
		string str;
		getline(infile, str);		
		istringstream inf(str);
		Tuple tuple(dimNum , 0);
		for (int j = 0; j != dimNum; ++j)
			inf >> tuple[j];
		tuples.push_back(tuple);
	}
	normalize(tuples);		//对输入数据进行正规化
	cout << "start clustering..." << endl;
	KMeans(tuples);
	infile.close();
	system("pause");
}