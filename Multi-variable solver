//Author: Chunguang Li
#include<iostream>
#include<cmath>
#include<fstream>
#include<stdlib.h>
using namespace std;

// This program aims to solve equations include multi-variables

void print(double (*pArray)[4], int iWidth,int iHigh);

int main(){
	int n,m;

	/* This method can be used in n*n isometric matrix

    for example n=3, in the following case,
        100*x0+10*x1+1*x2=10
        400*x0+20*x1+1*x2=20
        900*x0+30*x1+1*x2=10
    run the program to solve this problem

    variable n, and matrix size can be changed if needed
    */

	double a[3][4] = {
		{100, 10, 1, 10},
		{400, 20, 1, 20},
		{900, 30, 1, 10},
	};// the 4th column is augmented Matrix

	int i,j;
	n = 3; // numbers of variables
	cout<<"Enter numbers of variables: ";
	cout<<n<<endl;
	cout<<"Enter the Matrix£º"<<endl;
	for(i = 0; i < n; i++){
		for(j = 0; j < n + 1;j++){
			cout<<a[i][j]<<"   ";
		}
		cout<<endl;
	}


	for(j = 0; j < n; j++){
		double max = 0;
		double imax = 0;
		for(i = j; i < n; i++){
			if(imax < fabs(a[i][j])){
				imax = fabs(a[i][j]);
				max = a[i][j];//Get the maximum column elements in each row
				m = i;
			}
		}

		if(fabs(a[j][j]) != max) {
			double b = 0;
			for(int k = j;k < n + 1; k++){
				b = a[j][k];
				a[j][k] = a[m][k];
				a[m][k] = b;
			}
		}

		//print(a, 3, 4);

		for(int r = j;r < n + 1;r++){
			a[j][r] = a[j][r] / max;//divide first element of the column, in order to get 1 for the first element
		}
		//print(a, 3, 4);

		for(i = j + 1;i < n; i++){
			double c = a[i][j];
			if(c == 0)  continue;
			for(int s = j;s < n + 1;s++){
				double tempdata = a[i][s];
				a[i][s] = a[i][s] - a[j][s] * c;//deduct the adjacent rows, so the first element of one row could be 0
				//print(a, 3, 4);
			}
			//print(a, 3, 4);
		}
		//print(a, 3, 4);
	}

	for(i = n - 2; i >= 0; i--){
		for(j = i + 1;j < n; j++){
			double tempData = a[i][j];
			double data1 = a[i][n];
			double data2 = a[j][n];
			a[i][n] = a[i][n] - a[j][n] * a[i][j];
			//print(a, 3, 4);
		}
	}
	//print(a, 3, 4);

	cout<<"The solutions of the equation are£º"<<endl;
	for(int k = 0; k < n; k++){
		cout<<"x"<<k<<" = "<<a[k][n]<<endl;
	}
}

//print out array

void print(double (*pArray)[4], int iWidth,int iHigh) {
	std::cout<<"Array: "<<"\n";
	for(int i = 0; i < iWidth; i++){
		for(int j = 0; j < iHigh;j++){
			cout<<pArray[i][j]<<"   ";
		}
		cout<<endl;
	}
}

