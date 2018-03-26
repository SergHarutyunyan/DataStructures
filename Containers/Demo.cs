using Containers.Queue;
using Containers.Stack;
using Containers.Tree;
using System;
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
            //stackContiguous.Top();

            //stackContiguous.Push(2);
            //stackContiguous.Push(1);
            //stackContiguous.Push(6);
            //Console.WriteLine(stackContiguous.Top());
            //stackContiguous.Print();

            //stackContiguous.Push(5);
            //stackContiguous.Push(4);
            //stackContiguous.Push(8);
            //Console.WriteLine(stackContiguous.Top());
            //stackContiguous.Print();

            //stackContiguous.Pop();
            //stackContiguous.Pop();
            //Console.WriteLine(stackContiguous.Top());
            //stackContiguous.Print();


            /********************************** Stack Linked ****************************************/

            //StackLinked<int> stackLinked = new StackLinked<int>();

            //stackLinked.Pop();
            //Console.WriteLine(stackLinked.Top());

            //stackLinked.Push(5);
            //stackLinked.Push(6);
            //stackLinked.Push(7);
            //Console.WriteLine(stackLinked.Top());
            //stackLinked.Print();

            //stackLinked.Push(9);
            //stackLinked.Push(2);
            //stackLinked.Push(1);

            //stackLinked.Pop();
            //stackLinked.Pop();
            //Console.WriteLine(stackLinked.Top());
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

            //Console.WriteLine(queueLinked.Front()); 
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

            #endregion

            #region Tree

            /************************************ Binary Search Tree ****************************************/

            BinarySearchTree binarySearchTree = new BinarySearchTree();

            binarySearchTree.Insert(10);
            binarySearchTree.Insert(15);
            binarySearchTree.Insert(18);
            binarySearchTree.Insert(17);
            binarySearchTree.Insert(7);
            binarySearchTree.Insert(9);
            binarySearchTree.Insert(8);
            binarySearchTree.Insert(4);
            binarySearchTree.Insert(5);

            //Console.WriteLine(binarySearchTree.Predecessor(binarySearchTree.Find(10)).value);
            //Console.WriteLine(binarySearchTree.Successor(binarySearchTree.Find(15)).value);
            Console.WriteLine();


            //binarySearchTree.PostorderPrint(binarySearchTree.Find(10));

            //binarySearchTree.PrintInorder(binarySearchTree.Find(10));

            //binarySearchTree.Remove(15);
            //Console.WriteLine();
            //binarySearchTree.PrintInorder(binarySearchTree.Find(10));

            #endregion

            Console.Read();
        }
    }
}
