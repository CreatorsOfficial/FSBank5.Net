using System;
using System.Runtime.InteropServices;

namespace FSBankNet
{
    internal class Program
    {
        [DllImport("FSBankNative.dll")]
        public static extern void Create();
        static void Main(string[] args)
        {
            Create();
            Console.ReadLine();
        }
    }
}
