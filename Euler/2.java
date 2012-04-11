/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package euler;

import java.math.BigInteger;

/**
 *
 * @author Pratyush
 */
public class p2 {
    public static void main(String args[]) {
    BigInteger o,n,t,TWO;
    o=BigInteger.ONE;
    TWO=BigInteger.ONE.add(BigInteger.ONE);
    n=BigInteger.ONE.add(BigInteger.ONE);
    BigInteger count=BigInteger.ZERO;
        System.out.println(n.compareTo(BigInteger.valueOf(4000000)) <= 0);
    while(n.compareTo(BigInteger.valueOf(4000000)) <= 0) {
        if(n.mod(TWO)==BigInteger.ZERO) count=count.add(n);
        t=n;
        n=n.add(o);
        o=t;
//        System.out.println(n.divide(TWO) + " ---- "+n);
    }
        System.out.println(count);
    }
}
