// Pca.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <opencv.hpp>
#include <fstream>

using namespace cv;
using namespace std;



int _tmain(int argc, _TCHAR* argv[])
{
	const int SAMPLE_NUM = 31;
	const int VECTOR_NUM = 7;
	fstream fp;
	string temp;
	char* filename = "pca_data.txt";
	Mat pcaSet(SAMPLE_NUM, VECTOR_NUM, CV_32F);
	// 读取数据，生成pcaSet  
	fp.open(filename, ios::in);
	for (int i = 0; i<SAMPLE_NUM; i++)
	{
		getline(fp, temp, ' ');
		for (int j = 0; j<VECTOR_NUM; j++)
		{
			fp >> pcaSet.at<float>(i, j);
		}
	}
	fp.close();
	//cout << pcaSet;

	//  cout << pcaSet << endl;  
	PCA pca(pcaSet, Mat(), CV_PCA_DATA_AS_ROW,0.9);
	cout << pca.eigenvalues << endl;
	cout << endl;
	//cout << pca.eigenvectors << endl;
	Mat Pca_r = pca.project(pcaSet);
	cout <<Pca_r;
	return 0;
}