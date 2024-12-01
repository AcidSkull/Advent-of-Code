#include<iostream>
#include<fstream>
#include<cmath>

void counting_sort(int *input_vector, int N, int place){
    int *output_array = new int[N];
    int count_array[10] = {0};

    for(int i = 0; i < N; ++i)
        count_array[(input_vector[i] / place) % 10]++;
    
    for(int i = 1; i < 10; ++i)
        count_array[i] += count_array[i - 1];

    for(int i = N - 1; i >= 0; --i){
        int index = (input_vector[i] / place) % 10;
        --count_array[index];
        output_array[count_array[index]] = input_vector[i];
    }

    for(int i = 0; i < N; ++i){
        input_vector[i] = output_array[i];
    }

    delete [] output_array;
}

void radix_sort(int *input_vector, int N){
    int max = 0, i = 1;
    for(int i = 0; i < N; ++i)
        if(input_vector[i] > max) max = input_vector[i];
    
    while(max / i > 0){
        counting_sort(input_vector, N, i);
        i *= 10;
    }
}

int main(int argc, char const *argv[])
{
    std::ifstream file("day1.txt");
    if(!file.is_open()) return 1;

    int *array1 = new int[1000]; 
    int *array2 = new int[1000]; 

    int n1, n2, i=0;
    while(file >> n1 >> n2){
        array1[i] = n1;
        array2[i] = n2;
        ++i;
    }

    radix_sort(array1, 1000);
    radix_sort(array2, 1000);

    long long result = 0;
    for(int i = 0; i < 1000; i++){
        result += std::abs(array1[i] - array2[i]);
    }
    std::cout << result << '\n'; // 1580061

    delete [] array1, array2;
    return 0;
}
