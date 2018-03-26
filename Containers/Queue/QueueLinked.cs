using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Containers.Queue
{
    class QueueLinked<T>
    {
        class Node
        {
            internal T value;
            internal Node link;

            internal Node() { }
            internal Node(T value, Node link = null)
            {
                this.value = value;
                this.link = link;
            }
        }

        Node front;
        Node rear;

        private bool empty() { return front == null; }

        public void Push(T value)
        {
            if (empty())
            {
                rear = new Node(value);
                front = new Node(default(T),rear);
            }
            else
                rear = rear.link = new Node(value);          
        }

        public void Pop()
        {
            if (!empty())
                front.link = front.link.link;
            else
                Console.WriteLine("Queue is empty.");
        }

        public T Front()
        {
            if (!empty())
                return front.link.value;
            else
            {
                Console.WriteLine("Queue is empty.");
                return default(T);
            }
        }

        public void Print()
        {
            Node temp = new Node(default(T), front.link);
            do
            {
                Console.Write(temp.link.value + "->");
                temp.link = temp.link.link;
            } 
            while (temp.link != rear.link);
            Console.WriteLine();
        }
    }
}
