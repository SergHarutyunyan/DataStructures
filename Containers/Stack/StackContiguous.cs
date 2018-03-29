using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Containers.Stack
{
    class StackContiguous<T>
    {
        T[] arr;
        int size;
        int top;

        private bool empty() { return top == -1; }
        private bool full() { return top == size - 1; }

        public StackContiguous(int size)
        {
            this.size = size;
            top = -1;
            arr = new T[size];
        }

        public T Top()
        {
            if(!empty())
            {
                return arr[top];
            }
            else
            {
                Console.WriteLine("Stack is empty.");
                return default(T);
            }
        }

        public void Pop()
        {
            if (!empty())
            {
                Console.WriteLine("Popping");
                top--;
            }
            else
            {
                Console.WriteLine("Popping - Stack is empty.");
            }
        }

        public void Push(T value)
        {
            if (!full())
            {
                Console.WriteLine($"Pushing {value}");
                arr[++top] = value;
            }
            else
            {
                Console.WriteLine($"Can't Push value {value} - Stack is full.");
            }         
        }

        public void Print()
        {
            Console.WriteLine("\nDisplaying Stack.");
            for (int i = 0; i <= top; i++)
            {
                Console.Write(arr[i] + "->");
            }
            Console.WriteLine("\n");
        }
    }
}
