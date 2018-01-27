import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] a){
        Scanner input = new Scanner(System.in);
        BigInteger[] dat = new BigInteger[1001];
        dat[0]=dat[1]=BigInteger.ZERO;
        dat[2]=BigInteger.ONE;
        for (int i=3;i<=1000;i++) dat[i]=dat[i-1].add(dat[i-2].multiply(BigInteger.valueOf(2)));
        while (input.hasNext()) System.out.println(dat[input.nextInt()]);
    }
}
