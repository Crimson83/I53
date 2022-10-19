#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Sep 28 13:03:52 2022

@author: vfraselle243
"""
n=input("Entrez une expression : ")
l=[]
fichier=open("test.txt","w")

def Exp():
    return Terme() and Reste1()

def Terme():
    return Fact() and Reste2()

def Fact():
    global l
    if Reconnaitre("NOMBRE"):
        return True
    elif Reconnaitre("("):
        if Exp():
            if Reconnaitre(")"):
                return True
        return False

def Reste1():
    global l
    if Reconnaitre("+"):
        temp='+'
        if Terme():
            l+=[temp]
            return Reste1()
    elif Reconnaitre("-"):
        temp='-'
        if Terme():
            l+=[temp]
            return Reste1()
    else:
        return True

def Reste2():
    global l
    if Reconnaitre("*"):
        temp='*'
        if Terme():
            l+=[temp]
            return Reste1()
    elif Reconnaitre("/"):
        temp='/'
        if Terme():
            l+=[temp]
            return Reste1()
    else:
        return True

def Reconnaitre(a):
    global unilex,i,l
    if len(unilex)<=i:
        return False
    if unilex[i][0]==a:
        j=i+1
        tmp=str(unilex[i][1])
        while(j<len(unilex))and(unilex[j][1].isnumeric()):
            tmp+=str(unilex[j][1])
            j+=1
        l+=[tmp]
        i=j
        return True
    elif (str(unilex[i][1]) in a):
        i+=1
        return True
    else:
        return False
    
def Parser(s):
    global unilex,i
    unilex=s
    i=0
    return Exp()

def analex(s):
    l=[]
    i=0
    while i<(len(s)):
        if s[i].isnumeric():
            k=i+1
            if k<len(s) and s[k].isnumeric():
                while k<len(s) and s[k].isnumeric():
                    k+=1
            l+=[("NOMBRE",int(s[i:k]))]
            i=k
        elif s[i] in ["+","-","*","/"]:
            l+=[("OP",s[i])]
            i+=1
        elif s[i]=='(':
            l+=[("PAR_OUV",s[i])]
            i+=1
        elif s[i]==')':
            l+=[("PAR_FER",s[i])]
            i+=1
        elif s[i]==" ":
            i+=1
        else:
            print("Erreur n'importe nawak")
            break
    return l

if(Parser(analex(n))):
    print("Chaine Valide")
else:
    print("Erreur Syntaxique :",unilex[i][1])
print(l)