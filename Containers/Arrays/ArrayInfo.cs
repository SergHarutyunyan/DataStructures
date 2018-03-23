using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Containers.Arrays
{
    class ArrayInfo
    {
        #region Array Class

        public static Array CreateArray<T>(int length)
        {
            return Array.CreateInstance(typeof(T), length);
        }

        public static void Reverse(Array array)
        {
            Array.Reverse(array);
        }

        public static void Sort(Array array)
        {
            Array.Sort(array);
        }

        public static void ClearArrayRange(Array array, int index, int length)
        {
            Array.Clear(array, index, length);
        }

        public static void SetValue<T>(ref Array array, int index, T value)
        {
            if(index >= array.Length)
                Console.WriteLine("Can't set value. Index out of bound.");
            else
                array.SetValue(value, index);
        }

        public static void ArrayResize<T>(ref T[] array, int newSize)
        {
            Array.Resize(ref array, newSize);
        }

        public static int BinarySearchInteger(Array array, int value)
        {
            return Array.BinarySearch(array, value);
        }

        public static int BinarySearchGeneric<T>(T[] array, T value)
        {
            return Array.BinarySearch(array, value);
        }

        #endregion

        #region Jagged and Multidimensional array

        #endregion
    }
}
