#include <iostream>
#include <cmath>

using namespace std;

int matrix2(int matrix[2][2]){
	int result = (matrix[0][0]*matrix[1][1])-(matrix[0][1]*matrix[1][0]);
	return result;
}

int matrix3(int matrix[3][3]){
	int result = 0;
	for(int i = 0;i < 3;i++){
		int t[2][2];
		int t1[4];
		int p = 0;
		for(int k = 1;k < 3;k++){
			for(int m = 0;m < 3;m++){
				if(m == i){
					continue;
				}else{
					t1[p] = matrix[k][m];
					p++;
				}
			}
		}
		int p1 = 0;
		for(int j = 0;j < 2;j++){
			for(int b = 0;b < 2;b++){
				t[j][b] = t1[p1];
				p1++;
			}
		}
		result += pow(-1, i)*(matrix[0][i])*matrix2(t);
	}
	return result;
}

int matrix4(int matrix[4][4]){
	int result = 0;
	for(int i = 0;i < 4;i++){
		int t[3][3];
		int t1[9];
		int p = 0;
		for(int k = 1;k < 4;k++){
			for(int m = 0;m < 4;m++){
				if(m == i){
					continue;
				}else{
					t1[p] = matrix[k][m];
					p++;
				}
			}
		}
		int p1 = 0;
		for(int j = 0;j < 3;j++){
			for(int b = 0;b < 3;b++){
				t[j][b] = t1[p1];
				p1++;
			}
		}
		result += pow(-1, i)*(matrix[0][i])*matrix3(t);
	}
	return result;
}

int main(){
	cout << "Enter the matrix size : ";
	int n;
	cin >> n;
	switch(n){
		case 2:
			int matrix22[2][2];
			for(int i = 0;i < 2;i++){
				for(int j = 0;j < 2;j++){
					cin >> matrix22[i][j];
				}
			}
			cout << endl << "Result = " << matrix2(matrix22) << endl;
			break;
		case 3:
			int matrix33[3][3];
			for(int i = 0;i < 3;i++){
				for(int j = 0;j < 3;j++){
					cin >> matrix33[i][j];
				}
			}
			cout << endl << "Result = " << matrix3(matrix33) << endl;
			break;
		case 4:
			int matrix44[4][4];
			for(int i = 0;i < 4;i++){
				for(int j = 0;j < 4;j++){
					cin >> matrix44[i][j];
				}
			}
			cout << endl << "Result = " << matrix4(matrix44) << endl;
			break;
		default:
			cout << "Enter right size!!! MOTHERFUCKER" << endl;
			break;
	}
	return 0;
}