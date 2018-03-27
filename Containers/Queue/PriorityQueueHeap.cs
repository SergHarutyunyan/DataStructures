using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Containers.Queue
{
    class PriorityQueueHeap
    {
        int[] arr;
        int size;
        int numberOfElements;

        public PriorityQueueHeap(int size)
        {
            this.size = size + 1;
            arr = new int[this.size];
        }

        private bool full() { return numberOfElements + 1 == size; }

        private bool empty() { return numberOfElements == 0; }

        public int Top() { if (!empty()) return arr[1]; else return -1; }

        public void Push(int elem)
        {
            if (!full())
            {
                arr[++numberOfElements] = elem;
                int current = numberOfElements;
                int parrent;
                int temp;
                while (current > 1)
                {
                    parrent = current / 2;
                    if (arr[parrent] < arr[current]) return;
                    temp = arr[current];
                    arr[current] = arr[parrent];
                    arr[parrent] = temp;
                    current = parrent;
                }
            }
        }

        public void Pop()
        {
            if (!empty())
            {
                arr[1] = arr[numberOfElements--];
                int current = 1;
                int minChildIndex;

                int temp;
                while ((minChildIndex = (current<<1)) <= numberOfElements)
                {
                    if (minChildIndex + 1 <= numberOfElements && arr[minChildIndex + 1] < arr[minChildIndex])
                        minChildIndex++;

                    if (arr[current] <= arr[minChildIndex]) return;

                    temp = arr[current];
                    arr[current] = arr[minChildIndex];
                    arr[minChildIndex] = temp;

                    current = minChildIndex;
                }
            }
        }

        public void DisplayHeap()
        {
            if (!empty()) {

                int nBlanks = 32;
                int itemsPerRow = 1;
                int column = 0;
                int j = 0;                         
                String dots = "...............................";            
                Console.WriteLine(dots + dots); 

                while (numberOfElements > 0)              
                {
                    if (column == 0)                  
                        for (int k = 0; k < nBlanks; k++)
                            Console.Write(' ');

                    Console.Write(arr[++j]);

                    if (j == numberOfElements)          
                        break;

                    if (++column == itemsPerRow)        
                    {
                        nBlanks /= 2;                 
                        itemsPerRow *= 2;             
                        column = 0;
                        Console.WriteLine();        
                    }
                    else                             
                        for (int k = 0; k < nBlanks * 2 - 2; k++)
                            Console.Write(' ');     
                }
                Console.WriteLine("\n" + dots + dots); 
            }
        }  

    }
}
