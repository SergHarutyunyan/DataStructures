using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Containers.Stack
{ 
    class StackLinked<T>
    {
        class Node
        {
            internal T value;
            internal Node next;

            public Node() { }

            public Node(T value, Node next)
            {
                this.value = value;
                this.next = next;
            }
        }

        Node top;

        private bool empty() { return top == null; }

        public T Top()
        {
            if (!empty())
                return top.value;
            else
            {
                Console.WriteLine("Can't Top - Stack is empty.");
                return default(T);
            }

        }

        public void Push(T value)
        {
            if (empty())
            {
                Console.WriteLine($"Pushing value {value}");
                top = new Node(value, null);
            }
            else
            {
                Console.WriteLine($"Pushing value {value}");
                Node temp = new Node(value, top);
                top = temp;
            }
        }

        public void Pop()
        {
            if (!empty())
            {
                Console.WriteLine("Popping");
                top = top.next;
            }
            else
            {
                Console.WriteLine("Can't Pop - Stack is empty.");
            }
        }

        public void Print()
        {
            Console.WriteLine("Displaying stack.");
            Node temp = top;
            while (temp != null)
            {
                Console.Write(temp.value + "<-");
                temp = temp.next;
            }
            Console.WriteLine();
        }
    }
}
