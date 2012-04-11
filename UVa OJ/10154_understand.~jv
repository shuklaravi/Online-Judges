import java.io.FileReader;
import java.util.Arrays;
import java.util.Scanner;
import static java.lang.Math.min;

class Turtle {

        int MAX = 5608;
        int MAXINT = 2000000000;
        int[][] minweight = new int[2][MAX];

        SingleTurtle[] turtles = new SingleTurtle[MAX];
        int numTurtles;

        int solve(int load, int size) {
                int i, k;
                int curMax = 0; /* max height of the stack so far */
                int clear;
                int row;
                int prev_row;
                /* only use 2 rows, because we don't care about previous */
                for (i = 0; i < numTurtles; i++)
                        minweight[0][i] = MAXINT;

                for (i = 0; i < 2; i++)
                        minweight[i][0] = 0;

                for (i = 1; i <= numTurtles; i++) {
                        for (k = 1; k <= numTurtles; k++) {
                                /* we can lift the next turtle */
                                row=i%2;
                                prev_row=(row==1)?0:1;
                                if (minweight[prev_row][k - 1] + turtles[i].weight <= turtles[i].load) {
                                        minweight[row][k] = min(minweight[prev_row][k - 1]+ turtles[i].weight, minweight[prev_row][k]);
                                        if (k > curMax && minweight[row][k] < MAXINT)
                                                curMax = k;
                                } else
                                        minweight[row][k] = minweight[prev_row][k];
                        }
                        /*
                         * copy over the calculation from this iteration to make it the
                         * previous iteration. Get rid of previous iteration by overwriting
                         */
//                      for (clear = 0; clear <= i; clear++)
//                              minweight[0][clear] = minweight[1][clear];
                }
                return (curMax);
        }

        public void start() {
                Scanner in;
                try {
                        // in = new Scanner(System.in);
                        in = new Scanner(new FileReader("D.dat"));
                        int i = 1;
                        int max = 0;
                        // if (debug) System.out.println("Original");
                        /* Read input from the data file */
                        while (in.hasNext()) {
                                int weight = in.nextInt();
                                int load = in.nextInt();
                                SingleTurtle tempTurtle = new SingleTurtle(weight, load, load - weight);
                                turtles[i] = tempTurtle;
                                i++;
                        }
                        Arrays.sort(turtles, 1, i - 1);
                        numTurtles = i - 1;
                        max = solve(0, 0);
                        System.out.println(max);
                } catch (Exception e) {
                        // TODO Auto-generated catch block
                        e.printStackTrace();
                }
        }
        public static void main(String[] args) {
                Turtle t = new Turtle();
                t.start();
        }
}
class SingleTurtle implements Comparable<SingleTurtle> {
        int weight;
        int load;
        int diff;
        public SingleTurtle(int weight, int load, int diff) {
                this.weight = weight;
                this.load = load;
                this.diff = diff;
        }
        public int compareTo(SingleTurtle nuevo) {
                return new Integer(diff) - (nuevo.diff);
        }
}
