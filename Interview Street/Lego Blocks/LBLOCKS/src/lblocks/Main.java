/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package lblocks;

import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * @author Pratyush
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    static BigInteger solid[] = new BigInteger[1005];
    static BigInteger notSolid[][] = new BigInteger[1005][1005];
    static BigInteger wd[] = new BigInteger[1005];
    static BigInteger MOD = BigInteger.valueOf(1000000007);
    static int solid_[] = new int [10005];
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner cin = new Scanner(System.in);
        int t;
        t = cin.nextInt();
        wd[0] = BigInteger.ONE;
        wd[1] = BigInteger.ONE;
        wd[2] = BigInteger.valueOf(2);
        wd[3] = BigInteger.valueOf(4);
        for(int i = 4; i < 1001; ++i)
            wd[i] = wd[i-1].add(wd[i-2].add(wd[i-3].add(wd[i-4]))).mod(MOD);
        for(int i = 1; i < 1001; ++i)
        {
            for (int j = 1; j < 1001; ++j)
            {
                notSolid[i][j] = power(wd[i], j);
            }
        }
        while(t-- != 0)
        {
            int n,m;
            n = cin.nextInt();
            m = cin.nextInt();
            
            solid[1] = BigInteger.ONE;
            for(int i = 2; i <= m; ++i)
            {
                BigInteger temp = BigInteger.ZERO;
                for(int j = 1; j < i; ++j)
                {
                    temp = temp.add(solid[j].multiply(notSolid[i-j][n]));
                }
                solid[i] = notSolid[i][n].subtract(temp);
            }
            System.out.println(solid[m].mod(MOD));
        }
    }

    private static BigInteger power(BigInteger bigInteger, int n) {
        if(n == 1) return bigInteger;
        if(n == 0) return BigInteger.ONE;
        if(n % 2 == 1)
            return power(bigInteger, n - 1).multiply(bigInteger).mod(MOD);
        return power(bigInteger, n/2).pow(2).mod(MOD);
    }
}
