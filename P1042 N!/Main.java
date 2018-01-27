import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] a){
        Scanner input = new Scanner(System.in);
        BigInteger[] dat = new BigInteger[10001];
        dat[0] = dat[1] = BigInteger.ONE;
        for (int i=2;i<dat.length;i++) dat[i]=dat[i-1].multiply(BigInteger.valueOf(i));
        while (input.hasNextInt()) System.out.println(dat[input.nextInt()]);
    }
}
