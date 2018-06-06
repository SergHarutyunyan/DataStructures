using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithms.SortingAlgorithms
{
    internal sealed class Sorting
    {
        /// <summary>
        /// Based on Insertion Sort. But steps are going by 3x + 1.
        /// Insertion Sort goes 1 by 1.
        /// </summary>
        /// <param name="unSortedArray"></param>
        public static void ShellSort(int[] unSortedArray)
        {
            int h = 1;
            while (h < unSortedArray.Length / 3) h = 3 * h + 1;

            while (h >= 1)
            {
                for (int i = h; i < unSortedArray.Length; i++)
                {
                    for (int j = i; j - h >= 0; j = j - h) {
                        if (unSortedArray[j-h] > unSortedArray[j])
                            Exchange.Swap(unSortedArray, j, j-h);
                    }
                }
                h = h / 3;
            }
        }    
        
        /// <summary>
        /// MergeSort with Recursion
        /// </summary>
        /// <param name="unsortedArray"></param>
        /// <param name="extraSpaceArray"></param>
        /// <param name="low"></param>
        /// <param name="high"></param>
        public static void MergeSortWithRecursion(int[] unsortedArray, int[] extraSpaceArray, int low, int high)
        {
            if (high <= low) return;
            int mid = low + (high - low) / 2;
            MergeSortWithRecursion(unsortedArray, extraSpaceArray, low, mid);
            MergeSortWithRecursion(unsortedArray, extraSpaceArray, mid+1, high);
            if (unsortedArray[mid] < unsortedArray[mid + 1]) return;
            mergeSubArrays(unsortedArray, extraSpaceArray, low, mid, high);
        }

        private static void mergeSubArrays(int[] unsortedArray, int[] extraSpaceArray, int low, int mid, int high)
        {
            for (int k = low; k <= high; k++)
                extraSpaceArray[k] = unsortedArray[k];

            int i = low, j = mid + 1;
            for(int k = low; k <= high; k++)
            {
                if      (i > mid)                                   unsortedArray[k] = extraSpaceArray[j++];
                else if (j > high)                                  unsortedArray[k] = extraSpaceArray[i++];
                else if (extraSpaceArray[i] < extraSpaceArray[j])   unsortedArray[k] = extraSpaceArray[i++];
                else                                                unsortedArray[k] = extraSpaceArray[j++];
            }
        }

        private static int[] extraArray;

        public static void MergeSortWithoutRecursion(int[] unsortedArray)
        {
            int N = unsortedArray.Length;
            extraArray = new int[N];
            for (int i = 1; i < N; i+=i)
            {
                for (int lo = 0; lo < N-i; lo+= i+i)
                {
                    mergeSubArrays(unsortedArray, extraArray, lo, lo + i - 1, Math.Min(lo+i+i-1, N-1));
                }
            }
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="unsortedArray"></param>
        /// <param name="low"></param>
        /// <param name="high"></param>
        public static void QuickSort(int[] unsortedArray, int low, int high)
        {
            if (high <= low) return;
            int j = partition(unsortedArray, low, high);
            QuickSort(unsortedArray, low, j - 1);
            QuickSort(unsortedArray, j + 1, high);
        }

        private static int partition(int[] arr, int low, int high)
        {
            int i = low, j = high + 1;
            while (true)
            {
                while (arr[++i] < arr[low])     // Find item on left to swap
                    if (i == high) break;

                while (arr[low] < arr[--j])     // Find item on right to swap
                    if (j == low) break;

                if (i >= j) break;              // Check if pointers cross
                Exchange.Swap(arr, i, j);       // Swap
            }

            Exchange.Swap(arr, low, j);         // Swap with partitioning item
            return j;                           // Return index of item now known to be in place
        }



    }
}
