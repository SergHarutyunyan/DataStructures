using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Containers.Hashing
{
    class HashTableCA
    {
        class Node
        {
            internal int key;
            internal Node next;
            public Node(int key = 0, Node next = null)
            {
                this.key = key;
                this.next = next;
            }
        }

        int size;
        Node[] table;

        private int hashcode(int key)
        {
            return (7 * key) % size;
        }

        public HashTableCA(int size)
        {
            this.size = size;
            table = new Node[size];

            for (int i = 0; i < size; i++)
            {
                table[i] = new Node(i);
            }
        }

        public bool Search(int key)
        {
            int i = hashcode(key);
            Node current = table[i].next;

            while (current != null)
            {
                if (current.key == key) return true;
                current = current.next;
            }
            return false;
        }

        public void Insert(int key)
        {
            if (!Search(key))
            {
                int i = hashcode(key);
                Node previous = table[i];
                Node current = table[i].next;

                while (current != null)
                {
                    previous = current;
                    current = current.next;
                }

                current = new Node(key);
                previous.next = current;
            }
            else Console.WriteLine($"Key {key} already exist in hash table.");
        }

        public void Remove(int key)
        {
            if (Search(key))
            {
                int i = hashcode(key);
                Node previous = table[i];
                Node current = table[i].next;

                while (current.key != key)
                {
                    previous = current;
                    current = current.next;
                }

                previous.next = current.next;
            }
            else Console.WriteLine($"Key {key} doesn't exist in hash table.");
        }

        public void Display()
        {       
            for (int i = 0; i < size; i++)
            {
                Console.Write("{" + i + "} -> ");
                Node current = table[i].next;

                while(current != null)
                {
                    Console.Write(current.key + " -> ");
                    current = current.next;
                }
                Console.WriteLine();
            }
        }

    }
}
