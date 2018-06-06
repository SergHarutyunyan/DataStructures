using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Containers.Queue
{
    class QueueArrayResizing<T>
    {
        T[] arr;
        int N = 0;
        int front = 0;
        int end = 0;

        public QueueArrayResizing() { arr = new T[2]; }      

        private bool empty() { return N == 0; }

        private void enlargeArray()
        {
            T[] enlargedArray = new T[arr.Length * 2];
            copyArray(ref enlargedArray);
        }

        private void shrinkArray()
        {
            T[] shrinkedArray = new T[arr.Length / 2];
            copyArray(ref shrinkedArray);
        }

        private void copyArray(ref T[] newArray)
        {
            if (front < end)
            {
                for (int i = front; i < end; i++)
                    newArray[i] = arr[i];
            }
            else
            {
                int i = 0;
                for (int k = front; k < arr.Length; k++)
                    newArray[i++] = arr[k];

                for (int j = 0; j < end; j++)
                {
                    newArray[i++] = arr[j];
                }
            }
            front = 0;
            end = N;
            arr = newArray;
        }

        public void Enqueue(T value)
        {
            if (N == arr.Length)
                enlargeArray();
            arr[end] = value;
            if (end == arr.Length - 1)
                end = 0;
            else
                end++;
            N++;
        }

        public void Dequeue()
        {
            if (!empty())
            {
                arr[front] = default(T);
                front++;
                N--;
                if (N < arr.Length / 4)
                    shrinkArray();
            }
            else
                Console.WriteLine("Queue is empty.");
        }

        public void Print()
        {
            if (!empty())
            {
                for (int i = front; i != arr.Length; i++)
                {
                    Console.Write(arr[i] + "<-");
                }
                for (int i = 0; i != end; i++)
                {
                    Console.Write(arr[i] + "<-");
                }
            }
            Console.WriteLine();
        }
    }
}

