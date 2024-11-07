/*
Problema 2: Squares of a Sorted Array
Link: https://leetcode.com/problems/squares-of-a-sorted-array/

"Given an integer array nums sorted in non-decreasing order, 
return an array of the squares of each number sorted in non-decreasing order."

SOLUÇÃO:
Vamos, primeiro calcular o quadrado de cada número no array
Depois usamos o Bubble Sort para ordenar os quadrados. 
*/

#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // Calcula o quadrado de cada número
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] = nums[i] * nums[i];
        }
        
        // Aplica bubble sort para ordenar os quadrados
        bubbleSort(nums);
        return nums;
    }

private:
    // Função de ordenação usando Bubble Sort
    void bubbleSort(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                // Troca se o elemento atual é maior que o próximo
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
    }
};