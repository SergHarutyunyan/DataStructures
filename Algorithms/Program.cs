using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Algorithms.SortingAlgorithms;
using Algorithms.Shuffling;

namespace Algorithms
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] arr = { 1, 2, 3, 4, 5, 6, 7, 8 , 9 , 10 };

            //Shuffle.KnuthShuffle(arr);
            //printArray(arr);

            //Sorting.ShellSort(arr);
            //printArray(arr);

            //Shuffle.KnuthShuffle(arr);
            //printArray(arr);

            //int[] extraArrayForMergeSort = new int[arr.Length];
            //Sorting.MergeSortWithRecursion(arr, extraArrayForMergeSort, 0, arr.Length - 1);
            //printArray(arr);

            Shuffle.KnuthShuffle(arr);
            printArray(arr);

            Sorting.QuickSort(arr, 0, arr.Length - 1);
            printArray(arr);


            Console.Read();
        }

        static void printArray(int[] arr)
        {
            for(int i = 0; i < arr.Length; i++)
                Console.Write(arr[i] + " ");
            Console.WriteLine();
        }
    }
}
