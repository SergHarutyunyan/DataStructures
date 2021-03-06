﻿using System;
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
            int[] arrWithDuplicates = { 1, 2, 3, 3, 4, 5, 5, 5, 6, 7, 7, 8, 9, 10, 10, 10 };

            Shuffle.KnuthShuffle(arr);
            Console.Write("Shuffled array - ");
            printArray(arr);

            Shuffle.KnuthShuffle(arrWithDuplicates);
            Console.Write("Shuffled array with duplicates - ");
            printArray(arrWithDuplicates);

            //Sorting.ShellSort(arr);
            //printArray(arr);

            //Shuffle.KnuthShuffle(arr);
            //printArray(arr);

            //int[] extraArrayForMergeSort = new int[arr.Length];
            //Sorting.MergeSortWithRecursion(arr, extraArrayForMergeSort, 0, arr.Length - 1);
            //printArray(arr);

            //Shuffle.KnuthShuffle(arr);
            //printArray(arr);

            //Sorting.QuickSort(arr, 0, arr.Length - 1);
            //printArray(arr);

            //int a = Sorting.QuickSelect(arr, 6);

            //Shuffle.KnuthShuffle(arrWithDuplicates);
            //printArray(arrWithDuplicates);

            //Sorting.QuickSort3Way(arrWithDuplicates, 0, arrWithDuplicates.Length - 1);
            //printArray(arrWithDuplicates);

            //BinaryHeap binaryHeap = new BinaryHeap(arr);
            //binaryHeap.HeapSort();
            //Console.Write("HeapSorted array - ");
            //printArray(arr);

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
