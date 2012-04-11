/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package cbits;

import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

/**
 *
 * @author Pratyush
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    static int A[];
    static int B[];
    static int bits;
    static int query;
    
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner cin = new Scanner(System.in);
        bits = cin.nextInt();
        query = cin.nextInt();
        init(cin.next(), cin.next());
        while(query-- > 0)
        {
            String str = cin.next();
            if(str.equals("set_a"))
            {
                int idx = cin.nextInt();
                int bit = cin.nextInt();
                A[bits - idx - 1] = bit;
            }
            else if(str.equals("set_b"))
            {
                int idx = cin.nextInt();
                int bit = cin.nextInt();
                B[bits - idx - 1] = bit;
            }
            else
            {
                int idx = cin.nextInt();
                String aStr = Arrays.toString(A).replace(" ","").replace(",","").replace("[","").replace("]","");
                String bStr = Arrays.toString(B).replace(" ","").replace(",","").replace("[","").replace("]","");
//System.out.println(aStr);
//System.out.println(bStr);
                BigInteger aBig = new BigInteger(aStr, 2);
                BigInteger bBig = new BigInteger(bStr, 2);
//                System.out.println(aBig);
                BigInteger C = aBig.add(bBig);
                String CC = C.toString(2);
                int length = CC.length();
                if(idx == bits)
                {
                    CC = "0" + CC;
                    length += 1;
                }
                System.out.print(CC.charAt(length - 1 - idx));
            }
        }
    }

    private static void init(String AA, String BB) {
        A = new int[bits];
        B = new int[bits];
        for(int i = bits - 1; i >= 0; --i)
        {
            A[i] = AA.charAt(i) - '0';
        }
        for(int i = bits - 1; i >= 0; --i)
        {
            B[i] = BB.charAt(i) - '0';
        }
    }
}
