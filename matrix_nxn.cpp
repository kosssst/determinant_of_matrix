#include <iostream>
#include <cmath>
#include <fstream>

long long int det2(long long int ** arr){
    return (arr[0][0]*arr[1][1])-(arr[1][0]*arr[0][1]);
}
long long int det_n(long long int n, long long int ** arr){
    long long int result = 0;
    if(n > 2){
        for(long long int i = 0;i < n;i++){
            auto ** matrix = new long long int * [n-1];
            for(long long int create_2_array = 0;create_2_array < (n-1);create_2_array++){
                matrix[create_2_array] = new long long int [n-1];
            }
            for(long long int x = 1;x < n;x++){
                for(long long int y = 0; y < i;y++){
                    matrix[x-1][y] = arr[x][y];
                }
                for(long long int y = (i+1); y < n;y++){
                    matrix[x-1][y-1] = arr[x][y];
                }
            }
            result += (int)pow(-1, (double)i) * arr[0][i] * det_n(n-1, matrix);
//            for(long long int k = 0;k < n;k++){
//                delete [] matrix[k];
//            }
//            delete [] matrix;
        }
    }else{
        result = det2(arr);
    }
    return result;
}
int main() {
    std::ifstream input("test.in");
    long long int matrix_size;
    char c;
    bool b = true;
    while(b){
        std::cout << R"(Choose input type ("c" - console input; "f" - file input): )";
        std::cin >> c;
        switch(c){
            case 'c':
                std::cout << "Enter the matrix size: ";
                std::cin >> matrix_size;
                b = false;
                break;
            case 'f':
                input >> matrix_size;
                b = false;
                break;
            default:
                continue;
        }
    }
    auto ** matrix = new long long int * [matrix_size];
    for(long long int i = 0;i < matrix_size;i++){
        matrix[i] = new long long int [matrix_size];
    }
    switch(c){
        case 'c':
            for(long long int i = 0; i < matrix_size;i++){
                for(long long int j = 0;j < matrix_size;j++){
                    std::cin >> matrix[i][j];
                }
            }
            break;
        case 'f':
            for(long long int i = 0; i < matrix_size;i++){
                for(long long int j = 0;j < matrix_size;j++){
                    input >> matrix[i][j];
                }
            }
            break;
        default:
            break;
    }
    if(matrix_size == 2){
        std::cout << std::endl << "Result = " << det2(matrix) << std::endl;
    }
    else{
        std::cout << std::endl << "Result = " << det_n(matrix_size, matrix) << std::endl;
    }
//    for(long long int i = 0;i < matrix_size;i++){
//        delete [] matrix[i];
//    }
//    delete [] matrix;
    return 0;
}