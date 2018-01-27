import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    private static BigInteger[][] ans=new BigInteger[200][200];

    private static BigInteger find_out(int input_size,int buffer_size){
        if (input_size==0) return BigInteger.ONE;
        if (ans[input_size][buffer_size] != null)
            return ans[input_size][buffer_size];
        //input from queue
        BigInteger ret = find_out(input_size-1,buffer_size+1);
        //output from buffer
        if (buffer_size > 0) ret = ret.add(find_out(input_size,buffer_size-1));
        return ans[input_size][buffer_size]=ret;
    }
    public static void main(String[] args){
        Scanner cin=new Scanner(System.in);
        while (cin.hasNext()){
            final int N=cin.nextInt();
            System.out.println(find_out(N,0));
        }
    }
}
