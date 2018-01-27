import java.math.BigInteger;
import java.util.*;

public class Main{
    public static void main(String[] args){
        BigInteger a;
        Scanner in=new Scanner(System.in);
        while (in.hasNextBigInteger() && !(a=in.nextBigInteger()).equals(BigInteger.ZERO)){
            while (a.toString().length()!=1){
                BigInteger b=a;
                a=BigInteger.ZERO;
                for (char t:b.toString().toCharArray())
                    a=a.add(BigInteger.valueOf(t-'0'));
            }
            System.out.println(a);
        }
    }
}