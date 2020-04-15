package GUI;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class GUI {
    private JPanel panel1;
    private JTextField plainText;
    private JTextField key;
    private JTextField cipherText;
    private JButton clearButton;
    private JButton encryptButton;
    private JButton decryptButton;

    public GUI() {
        clearButton.addActionListener(e -> {
            plainText.setText("");
            key.setText("");
            cipherText.setText("");
        });
        encryptButton.addActionListener(e -> {
            String p = plainText.getText();
            String k = key.getText();
            String c = p + k;
            cipherText.setText(c);
        });
        decryptButton.addActionListener(e -> {
            String c = cipherText.getText();
            String k = key.getText();
            String p = c + k;
            plainText.setText(p);
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
