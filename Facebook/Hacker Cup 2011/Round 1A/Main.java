/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */



import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * @author Pratyush Verma
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int test;
        BigInteger arr[]=new BigInteger[105];
        arr[0]=BigInteger.ONE;
        arr[1]=BigInteger.ONE;
        for(int i=2;i<104;i++)
        {
            arr[i]=(BigInteger.valueOf(i).multiply(arr[i-1]).add((BigInteger.valueOf(i-1).multiply(arr[i-2]))));
        }
        arr[0]=BigInteger.ZERO;
        for(int i=1;i<104;i++)
        {
            arr[i]=arr[i].subtract(arr[i-1]);
        }
        BigInteger bc[][]=new BigInteger[105][105];
        for(int i=0;i<104;i++)
        {
            for(int j=0;j<104;j++)
            {
                bc[i][j] = BigInteger.ONE;
            }
        }
        for(int i=1;i<104;i++)
        {
            for(int j=1;j<i;j++)
            {
                bc[i][j]=bc[i-1][j-1].add(bc[i-1][j]);
            }
        }
        BigInteger res;
        Scanner cin=new Scanner(System.in);
        test=cin.nextInt();
        while(test--!=0)
        {
            res=BigInteger.ZERO;
            int x,y;
            x=cin.nextInt();
            y=cin.nextInt();
            for(int i=y;i<x;i++)
            {
//                System.out.println(bc[x][i]+" "+x+" "+i+" "+arr[x-i-1]);
                res=res.add(bc[x][i].multiply(arr[x-i-1]));
//                System.out.println(res);
            }
            res=res.add(BigInteger.ONE);
            res=res.mod(BigInteger.valueOf(1051962371));
            System.out.println(res);
        }
    }
}
