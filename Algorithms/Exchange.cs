using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithms
{
    sealed class Exchange
    {
        /// <summary>
        ///     
        /// </summary>
        /// <param name="arr"> the actual array </param>
        /// <param name="i"> index </param>
        /// <param name="j"> index </param>
        public static void Swap(int[] array, int i, int j)
        {      
            array[i] = array[i] + array[j];
            array[j] = array[i] - array[j];
            array[i] = array[i] - array[j];          
        }
    }
}
