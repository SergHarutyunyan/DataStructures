using Containers.Hashing;
using Containers.Queue;
using Containers.Stack;
using Containers.Tree;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Containers
{
    public class Demo
    {
        static void Main(string[] args)
        {
            #region Stack

            /********************************** Stack Contigous ****************************************/

            //StackContiguous<int> stackContiguous = new StackContiguous<int>(5);

            //stackContiguous.Pop();
            //Console.WriteLine("\nTop()");
            //stackContiguous.Top();
            //Console.WriteLine();

            //stackContiguous.Push(2);
            //stackContiguous.Push(1);
            //stackContiguous.Push(6);
            //Console.WriteLine("\nTop() = " + stackContiguous.Top());
            //stackContiguous.Print();

            //stackContiguous.Push(5);
            //stackContiguous.Push(4);
            //stackContiguous.Push(8);
            //Console.WriteLine();
            //Console.WriteLine("\nTop() = " + stackContiguous.Top());
            //stackContiguous.Print();

            //stackContiguous.Pop();
            //stackContiguous.Pop();
            //Console.WriteLine("\nTop() = " + stackContiguous.Top());
            //stackContiguous.Print();


            /********************************** Stack Linked ****************************************/

            //StackLinked<int> stackLinked = new StackLinked<int>();

            //stackLinked.Pop();
            //Console.WriteLine(stackLinked.Top()); Console.WriteLine();

            //stackLinked.Push(5);
            //stackLinked.Push(6);
            //stackLinked.Push(7);
            //Console.WriteLine();
            //Console.WriteLine($"Top() = " + stackLinked.Top()); Console.WriteLine();
            //stackLinked.Print(); Console.WriteLine();

            //stackLinked.Push(9);
            //stackLinked.Push(2);
            //stackLinked.Push(1);
            //Console.WriteLine();
            //stackLinked.Print(); Console.WriteLine();

            //stackLinked.Pop();
            //stackLinked.Pop();
            //Console.WriteLine();
            //Console.WriteLine($"Top() = " + stackLinked.Top()); Console.WriteLine();
            //stackLinked.Print();

            #endregion

            #region Queue

            /********************************************* Contigous Queue *****************************************/

            //QueueContigous<int> queueContigous = new QueueContigous<int>(5);

            //queueContigous.Pop();
            //Console.WriteLine(queueContigous.Front());

            //queueContigous.Push(4);
            //queueContigous.Push(9);
            //queueContigous.Push(3);
            //queueContigous.Push(5);
            //queueContigous.Print();

            //queueContigous.Pop();
            //queueContigous.Print();

            //queueContigous.Push(12);
            //queueContigous.Push(2);
            //queueContigous.Print();

            //queueContigous.Push(1);

            /********************************************* Linked Queue **********************************************/

            //QueueLinked<char> queueLinked = new QueueLinked<char>();

            //Console.Write(queueLinked.Front());
            //queueLinked.Pop();

            //queueLinked.Push('c');
            //queueLinked.Push('t');
            //queueLinked.Push('i');
            //Console.WriteLine(queueLinked.Front());
            //queueLinked.Print();

            //queueLinked.Pop();
            //queueLinked.Print();

            //queueLinked.Push('a');
            //queueLinked.Push('y');
            //queueLinked.Push('m');
            //queueLinked.Push('g');
            //Console.WriteLine(queueLinked.Front());
            //queueLinked.Print();

            /********************************************* Queue Array Resizing **********************************************/

            QueueArrayResizing<string> queueArrayResizing = new QueueArrayResizing<string>();
            queueArrayResizing.Enqueue("a");
            queueArrayResizing.Enqueue("b");
            queueArrayResizing.Enqueue("c");
            queueArrayResizing.Enqueue("d");

            queueArrayResizing.Print();

            queueArrayResizing.Dequeue();
            queueArrayResizing.Print();

            queueArrayResizing.Dequeue();
            queueArrayResizing.Dequeue();
            queueArrayResizing.Dequeue();

            queueArrayResizing.Enqueue("e");
            queueArrayResizing.Enqueue("f");
            queueArrayResizing.Enqueue("g");
            queueArrayResizing.Enqueue("h");


            /*****************************************  Priority Queue *************************************/

            //PriorityQueueHeap priorityQueue = new PriorityQueueHeap(6);

            //priorityQueue.Push(15);
            //priorityQueue.Push(10);
            //priorityQueue.Push(35);
            //priorityQueue.Push(25);
            //priorityQueue.Push(20);
            //priorityQueue.Push(5);

            //priorityQueue.DisplayHeap();

            //Console.WriteLine($"Top() = {priorityQueue.Top()}");
            //Console.WriteLine();
            //Console.WriteLine("Popping...");
            //priorityQueue.Pop();
            //priorityQueue.DisplayHeap();

            //Console.WriteLine();
            //Console.WriteLine("Popping...");
            //priorityQueue.Pop();
            //priorityQueue.DisplayHeap();

            /*************  Heap Sort **********/

            //int[] array = new int[5];
            //array[0] = 7;
            //array[1] = 15;
            //array[2] = 4;
            //array[3] = 12;
            //array[4] = 1;

            //customHeapSort(array, 5);

            //for (int i = 0; i < 5; i++) Console.Write(array[i] + " ");

            #endregion

            #region Tree

            /************************************ Binary Search Tree ****************************************/

            //BinarySearchTree binarySearchTree = new BinarySearchTree();

            //binarySearchTree.Insert(10);
            //binarySearchTree.Insert(15);
            //binarySearchTree.Insert(18);
            //binarySearchTree.Insert(17);
            //binarySearchTree.Insert(7);
            //binarySearchTree.Insert(9);
            //binarySearchTree.Insert(8);
            //binarySearchTree.Insert(4);
            //binarySearchTree.Insert(5);

            //binarySearchTree.DisplayTree(binarySearchTree.Find(10));

            //Console.WriteLine(binarySearchTree.Predecessor(binarySearchTree.Find(10)).value);
            //Console.WriteLine(binarySearchTree.Successor(binarySearchTree.Find(15)).value);
            //Console.WriteLine();

            //binarySearchTree.Remove(7);
            //binarySearchTree.DisplayTree(binarySearchTree.Find(10));

            //binarySearchTree.Remove(10);
            //binarySearchTree.DisplayTree(binarySearchTree.Find(9));

            #endregion

            #region Hash Tables

            /************************************ Close Addressing Hash Table ****************************************/

            //HashTableCA hashTable = new HashTableCA(5);

            ////hashTable.Remove(10);

            //hashTable.Insert(5);
            //hashTable.Insert(7);
            //hashTable.Insert(6);
            //hashTable.Insert(3);
            //hashTable.Insert(4);
            //hashTable.Insert(1);
            //hashTable.Insert(2);
            //hashTable.Insert(9);
            //hashTable.Display();

            //Console.WriteLine(); Console.WriteLine();

            //hashTable.Remove(6);
            //hashTable.Display();

            //Console.WriteLine(); Console.WriteLine();

            //hashTable.Remove(1);
            //hashTable.Display();

            #endregion

            Console.Read();
        }

        #region Heap Sort

        private static void customHeapSort(int[] arr, int size)             // O(n*log(n))
        {
            PriorityQueueHeap priorityQueue = new PriorityQueueHeap(size);

            for (int i = 0; i < size; i++)
                priorityQueue.Push(arr[i]);

            for (int i = 0; i < size; i++)
            {
                arr[i] = priorityQueue.Top();
                priorityQueue.Pop();
            }
        }

        #endregion
    }
}
