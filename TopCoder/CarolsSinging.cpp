public class CarolsSinging{
    public int choose(String[] lyrics) {
        int[] masks=new int[lyrics.length];
        for (int i=0;i<lyrics.length;i++)
            masks[i]=Integer.valueOf(lyrics[i].replaceAll("Y","1").replaceAll("N","0"),2);
        int best=lyrics.length;
        bigLoop:
        for (int i=1;i<(1<<lyrics[0].length())+1;i++){
            for (int j=0;j<masks.length;j++){
                if ((i&masks[j])==0) continue bigLoop;
            }
            best=Math.min(best,Integer.bitCount(i));
        }
        return best;
    }
    }
