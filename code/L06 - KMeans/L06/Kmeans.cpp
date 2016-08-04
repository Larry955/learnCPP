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
int dimNum;		//���ݵ�ά�������γ���
int dataNum;		//�������Ĵ�С��������ѧ�����пγ̵ĳɼ�������

double getMax(const vector<Tuple>& tuples,int col);		//ȡ�õ�ǰ�е����ֵ
double getMin(const vector<Tuple>& tuples,int col);		//ȡ�õ�ǰ�е���Сֵ
void normalize(vector<Tuple>&tuples);		//��Ԫ�����滯

double getDistance(const Tuple &t1, const Tuple &t2);		//����ŷ����þ����������Ԫ��֮��������
char clusterOfTuple(Tuple means[],const Tuple &tuple);		//ΪԪ�����

Tuple moveCentroids(vector<Tuple> cluster);		//�ƶ�����
double getCentroids(vector<Tuple>clusters[], Tuple means[]);		//�õ������������ڵĴصľ���
bool selected(int n, vector<int>v, const vector<Tuple>tuples);		//�ж�ĳ������Ƿ��Ѿ�����
void KMeans(vector<Tuple>& tuples);		//K-Means�㷨���������ĳ�ʼ���;���
void print(Tuple means[], const vector<Tuple>& tuples);		//��ӡ����ѧ���ĵȼ�����

double getMax(const vector<Tuple>& tuples,int col)		//colΪԪ��������У����γ�
{
	double max = 0;
	for (int i = 0; i != tuples.size(); ++i){
		if (max < (tuples[i])[col])		//tuples�洢�����е�Ԫ�飬tuples[i]��ʾ��i��Ԫ�飬(tuples[i])[col]����i��Ԫ���col�е�ֵ
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
	for (int i = 0; i != tuples.size(); ++i){		//����ÿһ��Ԫ��
		for (int j = 0; j != dimNum; ++j){		//����ÿһ��Ԫ���е�ÿһ��������
			(tuples[i])[j] = ((tuples[i])[j] - getMin(tuples, j)) / (getMax(tuples, j) - getMin(tuples, j));		//��ÿһ�����ݽ������滯
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
	int j = 0;		//�����洢�������Сʱ�����ĵı��
	double minDis = getDistance(means[0], tuple);
	//cout << minDis << endl;
	for (int i = 1; i != K; ++i){
		if (minDis > getDistance(means[i], tuple)){		//����뵱ǰԪ�����������
			minDis = getDistance(means[i], tuple);		
			j = i;
		}
	}
	switch (j){		//���ݱ����Ϊÿһ��Ԫ���趨��ǩ�����һ�����������Ԫ����ΪA���Դ�����
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
			var += getDistance((clusters[i])[j], means[i]);		//��������ĺ������ڴص�����Ԫ��ľ����
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
		case 0:	cout << "����\t" << clusterOfTuple(means, tuples[i])<<endl; break;		//��һ��Ԫ���ʾ���ǵ�һ��ѧ������һ��ѧ�������ǵ��ȣ��Դ�����
		case 1:	cout << "��ŷ\t" << clusterOfTuple(means, tuples[i]) << endl; break;
		case 2:	cout << "����\t" << clusterOfTuple(means, tuples[i]) << endl; break;
		case 3:	cout << "����֮��\t" << clusterOfTuple(means, tuples[i]) << endl; break;
		case 4:	cout << "����֮ĸ\t" << clusterOfTuple(means, tuples[i]) << endl; break;
		case 5:	cout << "����֮��\t" << clusterOfTuple(means, tuples[i]) << endl; break;
		case 6:	cout << "��֮ʹ��\t" << clusterOfTuple(means, tuples[i]) << endl; break;
		case 7:	cout << "�α���˹\t" << clusterOfTuple(means, tuples[i]) << endl; break;
		case 8:	cout << "����\t" << clusterOfTuple(means, tuples[i]) << endl; break;
		case 9:	cout << "̩��\t" << clusterOfTuple(means, tuples[i]) << endl; break;
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
	vector<Tuple> clusters[K];		//������K���أ�ÿһ�����ﶼ���������������Ԫ��
	Tuple means[K];			//������K������
	/*�ֶ���ʼ������*/
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
	/*�����ʼ������*/
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
	char label;		//�趨��ǩ����ѧ���ĵȼ�
	for (int i = 0; i != tuples.size(); ++i){
		label = clusterOfTuple(means, tuples[i]);		//��ǩ�Ǹ���Ԫ�����ڵĴصõ���
		clusters[label - 65].push_back(tuples[i]);		//label-65�ǽ���ĸת��Ϊ���֡���'A'-65����0
	}
	double oldCentroids = 0;		//�ɵ�����ֵ
	double newCentroids = getCentroids(clusters,means);		//�µ�����ֵ
	while ((newCentroids - oldCentroids) != 0){		//���µ����Ĳ��ٱ仯ʱ��˵������������
		oldCentroids = newCentroids;
		for (int i = 0; i != K; ++i){
			means[i] = moveCentroids(clusters[i]);		//�ƶ�����
		}
		for (int i = 0; i != K; ++i){		//���ÿһ����
			clusters[i].clear();
		}
		for (int i = 0; i != tuples.size(); ++i){			//�����µ����Ķ�Ԫ�����½��л���
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
	vector<Tuple>tuples;		//���ڴ������Ԫ��
	for (int i = 0; i != dataNum && !infile.eof(); ++i){
		string str;
		getline(infile, str);		
		istringstream inf(str);
		Tuple tuple(dimNum , 0);
		for (int j = 0; j != dimNum; ++j)
			inf >> tuple[j];
		tuples.push_back(tuple);
	}
	normalize(tuples);		//���������ݽ������滯
	cout << "start clustering..." << endl;
	KMeans(tuples);
	infile.close();
	system("pause");
}