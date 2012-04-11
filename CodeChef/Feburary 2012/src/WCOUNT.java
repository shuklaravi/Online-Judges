import java.math.BigInteger;
import java.util.Scanner;
public class WCOUNT {

	/**
	 * @param args
	 */
	static BigInteger[] fact = new BigInteger[501];
	static BigInteger MOD = BigInteger.valueOf(1000000007);
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		fact();
		int t;
		t = nextInt();
		while(t--!=0)
		{
			String s = nextLine();
			int[] lower = new int[26];
			int[] upper = new int[26];
			for(int i=0;i<s.length();i++)
			{
				if(s.charAt(i) <= 'Z' && s.charAt(i) >= 'A') {
					upper[s.charAt(i)-'A'] = getCount(s,s.charAt(i));
				}
				else
				{
					lower[s.charAt(i)-'a'] = getCount(s,s.charAt(i));
				}
			}
			BigInteger res = fact[s.length()];
			for(int i=0;i<26;i++) {
				if(lower[i] <= 1) continue;
				res = res.divide(fact[lower[i]]);
			}
			for(int i=0;i<26;i++) {
				if(upper[i] <= 1) continue;
				res = res.divide(fact[upper[i]]);
			}
			System.out.println(res.mod(MOD));
		}
		
	}
	private static int getCount(String s, char charAt) {
		// TODO Auto-generated method stub
		int count = 0;
		for(int i=0;i<s.length();i++)
		{
			if(s.charAt(i) == charAt) count++;
		}
		return count;
	}
	private static void fact() {
		// TODO Auto-generated method stub
		fact[0] = fact[1] = BigInteger.ONE;
		for(int i=2;i<501;i++)
		{
			fact[i] = fact[i-1].multiply(BigInteger.valueOf(i));
		}
	}
	static int nextInt(){
        try{
            int c = System.in.read();
            if(c == -1) return c;
            while(c != '-' && (c < '0' || '9' < c)){
                c = System.in.read();
                if(c == -1) return c;
            }
            if(c == '-') return -nextInt();
            int res = 0;
            do{
                res *= 10;
                res += c - '0';
                c = System.in.read();
            }while('0' <= c && c <= '9');
            return res;
        }catch(Exception e){
            return -1;
        }
    }
	static String nextLine(){
        try{
            StringBuilder res = new StringBuilder("");
            int c = System.in.read();
            while(c == '\r' || c == '\n')
                c = System.in.read();
            do{
                res.append((char)c);
                c = System.in.read();
            }while(c != '\r' && c != '\n');
            return res.toString();
        }catch(Exception e){
            return null;
        }
    }
}
