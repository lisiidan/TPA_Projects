#include <iostream>
#include <fstream>
#define MOD_NUMBER 666013
std::ifstream fin("kfib.in");
std::ofstream fout("kfib.out");

void multiply_matrix(long long int R[2][2], long long int A[2][2], long long int B[2][2]){
    R[0][0] = ((A[0][0] * B[0][0]) % MOD_NUMBER + (A[0][1] * B[1][0]) % MOD_NUMBER) % MOD_NUMBER;
    R[0][1] = ((A[0][0] * B[0][1]) % MOD_NUMBER + (A[0][1] * B[1][1]) % MOD_NUMBER) % MOD_NUMBER;
    R[1][0] = ((A[1][0] * B[0][0]) % MOD_NUMBER + (A[1][1] * B[1][0]) % MOD_NUMBER) % MOD_NUMBER;
    R[1][1] = ((A[1][0] * B[0][1]) % MOD_NUMBER + (A[1][1] * B[1][1]) % MOD_NUMBER) % MOD_NUMBER;

}

void my_pow_matrix(long long int R[2][2], long long int Z[2][2], long long int P){
    long long int R_temp[2][2],Z_temp[2][2];
    R[0][0] = 1;
    R[0][1] = 0;
    R[1][0] = 0;
    R[1][1] = 1;
    while(P > 0){
        if(P % 2 == 1) {
            for(int i = 0; i < 2; i++){
                for(int j = 0; j < 2; j++){
                    R_temp[i][j] = R[i][j];
                }
            }
            multiply_matrix(R,R_temp,Z);
        }
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                Z_temp[i][j] = Z[i][j];
            }
        }
        multiply_matrix(Z,Z_temp,Z_temp);
        P /= 2;
    }
}

int main(){
    long long int Z[2][2] = {0,1,1,1},Z_pow[2][2];
    long long int k;
    fin >> k;
    my_pow_matrix(Z_pow,Z,k-1);
    fout << Z_pow[1][1];
    return 0;
}

// VARIANTA DE 20 DE PUNCTE

// for(long long int i = 1; i < k - 1; i++){
//         Z[0][0] = Z[0][1] % MOD_NUMBER;
//         Z[0][1] = Z[1][1] % MOD_NUMBER;
//         Z[1][0] = Z[1][1] % MOD_NUMBER;
//         Z[1][1] = Z[0][0] % MOD_NUMBER + Z[0][1] % MOD_NUMBER;
//     }
//     fout << Z[1][1] % MOD_NUMBER; 