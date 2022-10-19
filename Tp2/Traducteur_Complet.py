#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Oct  5 13:56:02 2022

@author: vfraselle243
"""
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
    return l

print(analex(input("Entrez une chaine valide: ")))