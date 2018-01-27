import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner in=new Scanner(System.in);
        int N=in.nextInt();

        for (int i=0;i<N;i++){
            final int n=in.nextInt();
            ArrayList<BigInteger> dat=new ArrayList<>();
            for (int j=0;j<n;j++) dat.add(in.nextBigInteger());

            BigInteger ans=dat.stream().reduce(null,(a,b) -> {
                if (a==null) return b;
                else return a.multiply(b).divide(a.gcd(b));
            });
            System.out.println(ans);
        }
    }
}
