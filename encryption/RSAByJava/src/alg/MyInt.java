package alg;

import java.math.BigInteger;
import java.util.Arrays;
import java.util.Random;

public class MyInt {
    private BigInteger i;
    public MyInt() {
        i = BigInteger.ZERO;
    }
    public MyInt(String s) {
        i = new BigInteger(s);
    }
    public MyInt(BigInteger b) {
        i = b;
    }
    public MyInt(byte[] x) {
        byte[] b = Arrays.copyOf(x, x.length+1);
        this.i = new BigInteger(b);
    }
    public byte[] toBytes() {
        return this.i.toByteArray();
    }
    public String toString() {
        return i.toString();
    }
    public static MyInt of(int i) {
        return new MyInt(String.valueOf(i));
    }
    public static MyInt rand(int bitLength, MyInt mod){
        return new MyInt(new BigInteger(bitLength, new Random()).mod(mod.i));
    }
    public static MyInt probablePrime(int bitLength, Random rnd) {
        return new MyInt(BigInteger.probablePrime(bitLength, rnd));
    }
    public int bitLength() {
        return i.bitLength();
    }
    public Boolean equalsTo(int x) {
        return i.equals(BigInteger.valueOf(x));
    }
    public MyInt mult(MyInt x) {
        return new MyInt(i.multiply(x.i));
//        return (MyInt) this.multiply((BigInteger) x);
    }
    public MyInt subtr(int x) {
        return new MyInt(i.subtract(BigInteger.valueOf(x)));
    }
    public MyInt subtr(MyInt x) {
//        return new MyInt(this.subtract(new BigInteger(x.toString())));
        return new MyInt(i.subtract(x.i));
    }
    public MyInt mod(MyInt x) {
        return new MyInt(i.mod(x.i));
    }
    public MyInt gcd(MyInt x) {
        return new MyInt(i.gcd(x.i));
    }
    public MyInt pow(MyInt n, MyInt p) {
        return new MyInt(RSA.pow(i, n.i, p.i));
    }
    public MyInt inv(MyInt p) {
        BigInteger[] d = RSA.exgcd(i, p.i);
        if (!d[2].equals(BigInteger.ONE)) return new MyInt("-1");
        return new MyInt((d[0].mod(p.i).add(p.i)).mod(p.i));
    }
}
