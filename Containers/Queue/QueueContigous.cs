using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Containers.Queue
{
    class QueueContigous<T>
    {
        T[] arr;
        int size;
        int front;
        int rear;

        public QueueContigous(int size)
        {
            this.size = size + 1;
            arr = new T[this.size];
        }

        private bool full() { return (rear + 1 < size) ? rear + 1 == front : front == 0; }

        private bool empty() { return front == rear; }

        public T Front()
        {
            if (!empty())
                return (front + 1 < size) ? arr[front + 1] : arr[0];
            else
            {
                Console.WriteLine("Queue is empty.");
                return default(T);
            }
        }

        public void Push(T value)
        {
            if (!full())
            {
                rear = (rear + 1 < size) ? rear + 1 : 0;
                arr[rear] = value;
            }
            else
            {
                Console.WriteLine("Queue is full.");
            }
        }

        public void Pop()
        {
            if (!empty())
                front = (front + 1 < size) ? front + 1 : 0;
            else
                Console.WriteLine("Queue is empty.");
        }

        public void Print()
        {
            if (!empty())
            {
                for (int i = front + 1; i != rear + 1; i++)
                {
                    if (i == size)
                        i = 0;
                    Console.Write(arr[i] + "<-");
                }
            }
            Console.WriteLine();
        }
    }
}
