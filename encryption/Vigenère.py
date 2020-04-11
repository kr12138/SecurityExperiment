import tkinter as tk
import ctypes as ct

alg = "Vigenère"
ALG = ct.CDLL(".\\mylib\\" + alg + ".dll")

top = tk.Tk()
top.title(alg)
top.geometry("300x180")
FE = tk.Frame(width=300, height=200)
FE.grid(row=0)
FB = tk.Frame(width=300, height=100)
FB.grid(row=1)

plaintext = tk.StringVar()
ciphertext = tk.StringVar()
key = tk.StringVar()

LPT = tk.Label(FE, text="plaintext")
LPT.grid(row=0, padx=20, pady=10)
EPT = tk.Entry(FE, textvariable=plaintext)
EPT.grid(row=0, column=1)

LCT = tk.Label(FE, text="ciphertext")
LCT.grid(row=1, padx=20, pady=10)
ECT = tk.Entry(FE, textvariable=ciphertext)
ECT.grid(row=1, column=1)

LK = tk.Label(FE, text="key")
LK.grid(row=2, padx=20, pady=10)
EK = tk.Entry(FE, textvariable=key)
EK.grid(row=2, column=1)

def clear():
    plaintext.set("")
    ciphertext.set("")
    key.set("")

def encrypt():
    global ct
    PT = EPT.get()
    CT = ct.c_wchar_p(PT)
    K = EK.get()
    ALG.encrypt(CT, len(PT), K, len(K))
    ciphertext.set(CT.value)

def decrypt():
    global ct
    CT = ECT.get()
    PT = ct.c_wchar_p(CT)
    K = EK.get()
    ALG.decrypt(PT, len(CT), K, len(K))
    plaintext.set(PT.value)

BC = tk.Button(FB, text="清空", command=clear)
BC.grid(row=2, column=0, padx=40)
BD = tk.Button(FB, text="解密", command=decrypt)
BD.grid(row=2, column=1, padx=20)
BE = tk.Button(FB, text="加密", command=encrypt)
BE.grid(row=2, column=2, padx=20)

top.mainloop()

