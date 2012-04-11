import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class R1SquishedStatus {
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new FileReader("testI.txt"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("testO.txt"));
		int N = in.nextInt(), kase = 0;
		while(N-- > 0) {
			int M = in.nextInt();
			String s = in.next();
			char[] seq = s.toCharArray();
			long[] dp = new long[seq.length + 1];
			dp[seq.length] = 1;
			for(int i = seq.length - 1; i >= 0; i--) {
				dp[i] = (((single(seq[i] - '0',M)) ? dp[i + 1] : 0) +
						((i < seq.length - 1 && tens(seq[i]-'0',seq[i + 1] -'0', M)) ? dp[i + 2] : 0) +
						((i < seq.length - 2 && hundreds(seq[i] - '0',seq[i + 1]-'0',seq[i + 2]-'0', M)) ? dp[i + 3] : 0)) % 4207849484L;
			}
			bw.write("Case #" + ++kase + ": " + dp[0] + "\n");
		}
		bw.close();
	}
	
	public static boolean single(int x, int m) {
		if (x > m || x == 0)
			return false;
		return true;
	}

	public static boolean tens(int x0, int x1, int m) {
		if ((x1 + 10 * x0) > m || x0 == 0)
			return false;
		return true;
	}

	public static boolean hundreds(int x0, int x1, int x2, int m) {
		if ((x2 + 10 * x1 + 100 * x0) > m || x0 == 0)
			return false;
		return true;
	}

}
