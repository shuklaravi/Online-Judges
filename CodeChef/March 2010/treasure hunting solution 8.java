/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */



/**
 *
 * @author Ishani
 */
import java.util.*;

class State{
    int x,y,sts,trs;

    State(int xx,int yy,int tt,int ss){
        x= xx;
        y = yy;
        trs = tt;
        sts=ss;
    }
}

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
        int[] dx = {-1,0,1,0} , dy = {0,1,0,-1};


        while(t-- >0){
            sc.nextLine();
            int N = Integer.parseInt(sc.nextLine());
            int goal = 0;
            char[][] maze = new char[N][N];

            for(int i=0;i<N;i++)maze[i] = sc.nextLine().toCharArray();

            for(int i=0;i<N;i++)for(int j=0;j<N;j++)if(maze[i][j]=='*'){
                maze[i][j] = (char)('a'+goal);
                goal++;
            }
            boolean[][][] vis = new boolean[N][N][(1<<(goal))];
            Queue<State> Q= new  LinkedList<State>();
            Q.add(new State(0,0,0,0));
            vis[0][0][0]=true;
            boolean got = false;

            while(!Q.isEmpty()){
                State now = Q.remove();
              //  System.out.println("--> "+now.x+" --> "+now.y+" --> "+now.trs+" --> "+now.sts);
                if(now.x==N-1 && now.y==N-1 && Integer.bitCount(now.trs)==goal){


                    System.out.println(now.sts);
                    got = true;
                    break;
                }
                for(int i=0;i<4;i++){
                    int nx = now.x+dx[i] , ny = now.y+dy[i] , nt = now.trs;
                    if(nx<0 || ny<0 || nx>=N || ny>=N || maze[nx][ny]=='#')continue;

                    if(maze[nx][ny]!='.'){
                        int pos = maze[nx][ny]-'a';
                        nt = nt|(1<<pos);

                    }
                    if(vis[nx][ny][nt])continue;
                    vis[nx][ny][nt] = true;


                    Q.add(new State(nx, ny, nt, now.sts+1));

                }
            }

            if(!got){
                System.out.println(-1);
            }
        }

    }
}
