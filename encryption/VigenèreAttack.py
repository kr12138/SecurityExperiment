import math
import tkinter as tk
import ctypes as ct

atk = "VigenèreAttack"
ATK = ct.CDLL(".\\mylib\\" + atk + ".dll")
alg = "Vigenère"
ALG = ct.CDLL(".\\mylib\\" + alg + ".dll")

ATK.getCI.restype = ct.c_double

top = tk.Tk()
top.title(atk)
top.geometry("400x320")
FE = tk.Frame(top, width=400, height=200)
FE.grid(row=0)
FB = tk.Frame(top, width=400, height=300)
FB.grid(row=1)

ciphertext = tk.StringVar()

LCT = tk.Label(FE, text="ciphertext")
LCT.grid(row=0, padx=20, pady=10)
ECT = tk.Entry(FE, textvariable=ciphertext)
ECT.grid(row=0, column=1)


LK = tk.Label(FB, text="results:")
LK.grid(row=0, padx=20, pady=10)
LB = tk.Listbox(FB, width=50)
LB.grid(row=1, padx=20)

def clear():
    global ciphertext
    ciphertext = ""
    LB.delete(0, LB.size())


def decrypt():
    global ct
    CT = ECT.get()
    slen = len(CT)
    # print(CT, slen)
    lst = list()
    c = (ct.c_int * (slen*2))()  # 记录大小写的数组
    t = ct.c_wchar_p('a' * slen)  # 转换成c语言的小写字母的数组
    ATK.init(CT, slen, t, c)
    # for i in range(0, len(c)):
    #     print(c[i], end=" ")
    # print(t.value)
    for klen in range(1, slen):
        if klen > math.sqrt(slen):
            break
        k = ""
        for I in range(0, klen):
            k += chr(ATK.getK(t, c, slen, klen, I))
        # lst.append([k, ct.c_double(ATK.getCI(t, slen, klen))])
        ci = ATK.getCI(t, c, slen, klen)
        PT = ct.c_wchar_p(CT)
        ALG.decrypt(PT, len(CT), k, len(k))
        # print(k)
        print(ci)
        # print(PT.value)
        lst.append((k, ci, PT.value))
        lst.sort(key=lambda x:abs(x[1]-0.065))
        if len(lst) > 5:
            del lst[5]
        # LB.insert("end", " possible key: "+k)
        # LB.insert("end", " coincidence index: "+str(ci))
        # LB.insert("end", "plaintext: "+PT.value)
    LB.delete(0, LB.size())
    for t in lst:
        LB.insert("end", "  possible key: "+t[0])
        LB.insert("end", " coincidence index: "+str(t[1]))
        LB.insert("end", "plaintext: "+t[2])
        LB.insert("end", "")
    # print(" dec fin.")


BC = tk.Button(FE, text="清空", command=clear)
BC.grid(row=1, column=0, padx=20)
BD = tk.Button(FE, text="解密", command=decrypt)
BD.grid(row=1, column=1, padx=20)


top.mainloop()



