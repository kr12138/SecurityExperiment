package alg;

import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

public class RSA {
    /*
    static long[] exgcd(long a, long b) {
        if (b == 0) return new long[]{1, 0, a};
        // b == 0  =>  1 * a  +  0 * b  ==  a
        long[] d = exgcd(b, a%b);
        // d[0] * b  +  d[1] * a%b  ==  d[2]
        long z = d[0];
        d[0] = d[1];
        d[1] = z - d[1]*a/b;
        // d[1] * a  +  d[0] * b  -  d[1]*a/b * b  ==  d[2]
        return d;
    }
     */

    static BigInteger[] exgcd(BigInteger a, BigInteger b) {
        if (b.equals(BigInteger.ZERO)) return new BigInteger[]
                {BigInteger.ONE, BigInteger.ZERO, a};
        // b == 0  =>  1 * a  +  0 * b  ==  a
        BigInteger[] d = exgcd(b, a.mod(b));
        // d[0] * b  +  d[1] * a%b  ==  d[2]
        BigInteger z = d[0];
        d[0] = d[1];
        d[1] = z.subtract(d[1].multiply(a.divide(b)));
        // d[1] * a  +  d[0] * b  -  d[1]*a/b * b  ==  d[2]
        return d;
    }

    /*
    static BigInteger inv(BigInteger a, BigInteger b) {
        BigInteger[] d = exgcd(a, b);
        if (!d[2].equals(BigInteger.ONE)) return BigInteger.valueOf(-1);
        return (d[0].mod(b).add(b)).mod(b);
    }
     */

    static BigInteger pow(BigInteger a, BigInteger n, BigInteger p) {
        BigInteger r = BigInteger.ONE;
        while (!n.equals(BigInteger.ZERO)) {
            if (n.and(BigInteger.ONE).equals(BigInteger.ONE))
                r = r.multiply(a).mod(p);
            a = a.multiply(a).mod(p);
            n = n.shiftRight(1);
        }
        return r;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        PrintStream o = System.out;
        BigInteger p = BigInteger.valueOf(7);
        int a = sc.nextInt();
        o.println(Arrays.toString(exgcd(BigInteger.valueOf(a), p)));
    }

}
