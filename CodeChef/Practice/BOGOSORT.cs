using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Numerics;

namespace CodeChef
{
    class BOGOSORT
    {
        BigInteger[] fact = new BigInteger[155];
        BigInteger[] q = new BigInteger[155];
        BigInteger[,,] p = new BigInteger[155,155,2]; // 0 for numerator 1 for denominator
        BigInteger[,] E = new BigInteger[155,2]; // 0 for numerator 1 for denominator

        static void Main(string[] args)
        {
            BOGOSORT ob = new BOGOSORT();
            ob.SolveAll();
        }
        public void SolveAll()
        {
            int test;
            test = Int32.Parse(Console.ReadLine());
            Factorial();
            CalcQ();
            CalcP();
            CalcE();
            while (test-- > 0)
            {
                int n;
                n = Int32.Parse(Console.ReadLine());
                if (n == 1)
                {
                    Console.WriteLine("0");
                    continue;
                }
                BigInteger gcd = BigInteger.GreatestCommonDivisor(E[n, 0], E[n, 1]);
                if (BigInteger.Divide(E[n, 1], gcd).Equals(1) == true)
                {
                    Console.WriteLine(BigInteger.Divide(E[n, 0], gcd));
                }
                else
                {
                    Console.WriteLine(BigInteger.Divide(E[n, 0], gcd) + "/" + BigInteger.Divide(E[n, 1], gcd));
                }
            }
        }
        public void Factorial()
        {
            fact[0] = BigInteger.One;
            fact[1] = BigInteger.One;
            for (int i = 2; i < 155; i++)
            {
                fact[i] = BigInteger.Multiply(fact[i - 1], BigInteger.Parse(i.ToString()));
            }
        }
        public void CalcQ()
        {
            q[0] = BigInteger.One;
            q[1] = BigInteger.One;
            for (int i = 2; i < 155; i++)
            {
                q[i] = BigInteger.Add(BigInteger.Multiply(BigInteger.Pow(BigInteger.Parse((i - 2).ToString()), 2), fact[i - 2]), fact[i - 1]);
            }
        }
        public void CalcP()
        {
            BigInteger gcd;
            p[1, 1, 0] = BigInteger.One;
            for (int n = 2; n < 153; n++)
            {
                for (int k = 1; k <= n; k++)
                {
                    p[k, n, 0] = BigInteger.Multiply(q[k], BigInteger.Parse((n - k + 1).ToString()));
                    p[k, n, 1] = fact[n];
                    gcd = BigInteger.GreatestCommonDivisor(p[k, n, 0], p[k, n, 1]);
                    p[k, n, 0] = BigInteger.Divide(p[k, n, 0], gcd);
                    p[k, n, 1] = BigInteger.Divide(p[k, n, 1], gcd);
                }
            }
        }
        public void CalcE()
        {
            BigInteger gcd;
            E[1, 0] = 0;
            E[1, 1] = 0;
            for (int n = 2; n < 153; n++)
            {
//                Console.WriteLine(n);
                E[n, 0] = BigInteger.Zero;
                E[n, 1] = BigInteger.Zero;
                BigInteger num = BigInteger.Zero;
                BigInteger den = BigInteger.One;
                for (int k = 2; k < n; k++)
                {
                    den = BigInteger.Multiply(den, BigInteger.Multiply(E[k, 1], p[k, n, 1]));
//                    Console.WriteLine(E[k, 1] + "*" + p[k, n, 1] + "=" + den);
                }
                for(int k = 2; k < n; k++)
                {
                    BigInteger num1 = BigInteger.Multiply(p[k, n, 0], BigInteger.Multiply(E[k, 0],den));
                    BigInteger den1 = BigInteger.Multiply(E[k, 1], p[k, n, 1]);
                    num = BigInteger.Add(num, BigInteger.Divide(num1,den1));
  //                  Console.WriteLine(num1 + " " + den1 + " " + num);
                }


    //            Console.WriteLine(num + " " + den);


                num = BigInteger.Add(den, num);

                gcd = BigInteger.GreatestCommonDivisor(num, den);
                num = BigInteger.Divide(num, gcd);
                den = BigInteger.Divide(den, gcd);

      //          Console.WriteLine(num + " " + den);


                E[n, 0] = BigInteger.Multiply(num, fact[n]);
                E[n, 1] = BigInteger.Multiply(den, BigInteger.Subtract(fact[n], q[n]));

        //        Console.WriteLine(E[n, 0] + " " + E[n, 1]);

                gcd = BigInteger.GreatestCommonDivisor(E[n, 0], E[n, 1]);
                E[n, 0] = BigInteger.Divide(E[n, 0], gcd);
                E[n, 1] = BigInteger.Divide(E[n, 1], gcd);


          //      Console.WriteLine(n);
        //        Console.WriteLine(p[n, n, 1] + " " + p[n, n, 0]);
            //    Console.WriteLine(E[n, 0] + " " + E[n, 1]);
//                int i = Console.Read();
            }
        }
    }
}
