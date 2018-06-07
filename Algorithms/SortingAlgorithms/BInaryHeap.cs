using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithms.SortingAlgorithms
{
    // Not resizable
    class BinaryHeap
    {
        private int[] pq;
        private int N;

        public BinaryHeap(int capacity)
        {
            pq = new int[capacity + 1];
        }

        public BinaryHeap(int[] arr)
        {
            pq = arr;
        }

        public bool isEmpty() { return N == 0; }

        public void Insert(int a)
        {
            pq[++N] = a;
            swim(N);
        }

        public int DeleteMax()
        {
            int max = pq[1];
            Exchange.Swap(pq, 1, N--);

            sink(1);
            pq[N + 1] = 0;
            return max;
        }

        private void swim(int k)
        {
            while (k > 1 && pq[k / 2] < pq[k])
            {
                Exchange.Swap(pq, k/2, k);
                k = k / 2;
            }
        }

        private void sink(int k)
        {
            while (2 * k <= N)
            {
                int j = 2 * k;
                if (j < N && pq[j] < pq[j + 1]) j++;
                if (pq[k] >= pq[j]) break;

                Exchange.Swap(pq, k, j);
                k = j;
            }
        }

        public void HeapSort()                  // For this working, required to change all less and exchange operations
        {                                       // from 1-based indexing to 0-base
            int N = pq.Length;

            for (int k = N / 2; k >= 1; k--)
                sink(k);

            while(N > 1)
            {
                Exchange.Swap(pq, 1, N);
                N--;
                sink(1);
            }
        }
    }
}
