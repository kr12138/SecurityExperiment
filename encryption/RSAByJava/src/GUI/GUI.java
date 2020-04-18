package GUI;

import alg.MyInt;

import javax.swing.*;
import java.util.Random;

public class GUI {
    private JPanel panel1;
    private JTextArea plainText;
    private JTextArea cipherText;
    private JButton clearButton;
    private JButton encryptButton;
    private JButton decryptButton;
    private JTextField privateKeyP;
    private JTextField privateKeyQ;
    private JTextField publicKeyN;
    private JTextField publicKeyE;
    private JTextField privateKeyD;
    private JButton randomPButton;
    private JButton randomQButton;
    private JButton randomEButton;

    public GUI() {
        clearButton.addActionListener(E -> {
            plainText.setText("");
            cipherText.setText("");
            privateKeyP.setText("");
            privateKeyQ.setText("");
            publicKeyN.setText("");
            publicKeyE.setText("");
            privateKeyD.setText("");
        });
        randomPButton.addActionListener(E -> {
            int bitLen = 100 + new Random().nextInt()%100;
            MyInt p = MyInt.probablePrime(bitLen, new Random());
            privateKeyP.setText(p.toString());
        });
        randomQButton.addActionListener(E -> {
            int bitLen = 100 + new Random().nextInt()%100;
            MyInt q = MyInt.probablePrime(bitLen, new Random());
            privateKeyQ.setText(q.toString());
        });
        randomEButton.addActionListener(E -> {
            MyInt p = new MyInt(privateKeyP.getText());
            MyInt q = new MyInt(privateKeyQ.getText());
            MyInt phiN = p.subtr(1).mult(q.subtr(1));
            MyInt e = new MyInt();
            while (!e.gcd(phiN).equalsTo(1))
                e = MyInt.rand(phiN.bitLength(), phiN);
            publicKeyE.setText(e.toString());
        });
        encryptButton.addActionListener(E -> {
            MyInt p = new MyInt(privateKeyP.getText());
            MyInt q = new MyInt(privateKeyQ.getText());
            MyInt e = new MyInt(publicKeyE.getText());
            MyInt n = p.mult(q);
            publicKeyN.setText(n.toString());
//            MyInt phiN = p.subtr(1).mult(q.subtr(1));
//            MyInt d = e.inv(phiN);
//            privateKeyD.setText(d.toString());
            MyInt pt = new MyInt(plainText.getText());
            MyInt ct = pt.pow(e, n);
            cipherText.setText(ct.toString());
        });
        decryptButton.addActionListener(E -> {
            MyInt p = new MyInt(privateKeyP.getText());
            MyInt q = new MyInt(privateKeyQ.getText());
            MyInt e = new MyInt(publicKeyE.getText());
            MyInt n = p.mult(q);
            MyInt phiN = p.subtr(1).mult(q.subtr(1));
            MyInt d = e.inv(phiN);
            privateKeyD.setText(d.toString());
            MyInt ct = new MyInt(cipherText.getText());
            MyInt pt = ct.pow(d, n);
            plainText.setText(pt.toString());
        });
    }

    public static void main(String[] args) {
        JFrame frame = new JFrame("GUI");
        frame.setContentPane(new GUI().panel1);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setVisible(true);
    }
}
