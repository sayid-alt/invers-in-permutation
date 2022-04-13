#include <iostream>
using namespace std;
void printArray(int arr[], int n);
void random_array(int arr[], int n);
void arr_permutation(int arr[], int size);
int sum_inv(int arr[], int size);
void input_element(int arr[], int size);
bool even_parameter(int num);
int factorial(int num);

// Driver code
int main(){
	int size;
	cout << "size: "; cin >> size;
	int arr[size];
	// input element of array
	input_element(arr, size);
	// Permutation and invers determining
	sort(arr, arr + size);
	printArray(arr, size);
	cout << endl;

	cout << "==== Permutation ====" << endl;
	int permutation_loop = factorial(size);
	int i = 0;
	while(i < permutation_loop){
		next_permutation(arr, arr + size);
		printArray(arr, size);
		int num_inv = sum_inv(arr, size);
		bool is_even = even_parameter(num_inv);
		if (is_even){
			cout << " sum of permutation = " << num_inv << " (even permutation)" << endl;
		} else{
			cout << " sum of permutation = " << num_inv << " (odd permutation)" << endl; 
		}
		i++;
	}
	cout << "there is " << i << " loops of permutation" << endl;
	return 0;
}

 // =======================================================================
void printArray(int arr[], int n){
	for (int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
}
int sum_inv(int arr[], int size){
	int num_inv = 0;
	for (int j = 0; j < size; j++){
		for (int k = j; k < size; k++){
			if (arr[j] > arr[k]){
				num_inv++;
			}
		}
	}
	return num_inv;
}
void input_element(int arr[], int size){
	for (int i = 0; i < size; i++){
		cout << "arr[" << i << "]: ";
		cin >> arr[i];
	}
}
bool even_parameter(int num){
	return (num % 2) == 0;
}
int factorial(int num){
	if ((num == 0) | (num == 1)){
		return 1;
	} else{
		return num * factorial(num - 1);
	}
}