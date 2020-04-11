import tkinter as tk
import ctypes as ct
import base64

alg = "AES"
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
    PT = bytes(EPT.get(), encoding="utf8")
    K = bytes(EK.get(), encoding="utf8")
    K = ct.create_string_buffer(K, 176)
    ALG.ke(K)
    CT = b''
    for i in range(0, len(PT), 16):
        t = ct.create_string_buffer(PT[i:i+16], 16)
        ALG.encrypt(t, K)
        CT = CT + base64.b16encode(t.raw)
    ciphertext.set(CT)

def decrypt():
    global ct
    CT = ECT.get()
    CT = base64.b16decode(CT)
    K = bytes(EK.get(), encoding="utf8")
    K = ct.create_string_buffer(K, 176)
    ALG.ke(K)
    PT = b''
    for i in range(0, len(CT), 16):
        t = ct.create_string_buffer(CT[i:i+16], 16)
        ALG.decrypt(t, K)
        PT = PT + t.value
    plaintext.set(str(PT, encoding="utf8"))

BC = tk.Button(FB, text="清空", command=clear)
BC.grid(row=2, column=0, padx=40)
BD = tk.Button(FB, text="解密", command=decrypt)
BD.grid(row=2, column=1, padx=20)
BE = tk.Button(FB, text="加密", command=encrypt)
BE.grid(row=2, column=2, padx=20)

top.mainloop()

