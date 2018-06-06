using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithms.Shuffling
{
    sealed class Shuffle
    {
        static Random random = new Random(DateTime.Now.Second);

        public static void KnuthShuffle(int[] arr)
        {
            for (int i = 1; i < arr.Length; i++)
                Exchange.Swap(arr, i, random.Next(i));
        }
    }
}
