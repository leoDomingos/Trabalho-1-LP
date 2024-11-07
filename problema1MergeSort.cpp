/*
Problema 1: Sort an Array
Link: https://leetcode.com/problems/sort-an-array/

Enunciado:
"Given an array of integers nums, sort the array in ascending order and return it."

SOLUÇÃO:
Vamos usar o Merge Sort para ordenar, e uma função auxiliar para mesclar as duas 
partes ordenadas, para que o array final esteja em ordem crescente.
*/

#include <vector>
using namespace std;

class Solution {
public:
    // Função principal para chamar o merge sort
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

private:
    // dividir o array e aplicar merge sort
    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return; // Base da recursão
        
        int mid = left + (right - left) / 2;
        
        // mergeSort recursivamente para a primeira metade
        mergeSort(nums, left, mid);
        
        // mergeSort recursivamente para a segunda metade
        mergeSort(nums, mid + 1, right);
        
        // junta as duas metades ordenadas
        merge(nums, left, mid, right);
    }

    // Função que junta as duas metades ordenadas
    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;

        // Combina itens de ambas as metades em ordem crescente
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }

        // Adiciona os itnes restantes da primeira metade
        while (i <= mid) {
            temp[k++] = nums[i++];
        }

        // Adiciona os itens restantes da segunda metade
        while (j <= right) {
            temp[k++] = nums[j++];
        }

        // Copia o array de volta ao original
        for (int i = left, k = 0; i <= right; ++i, ++k) {
            nums[i] = temp[k];
        }
    }
};