#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Sep 21 12:58:26 2022

@author: vfraselle243
"""
import dis
import time
def testcondi(a):
    for i in range(a):
        if(i%2==0):
            print("multiple 2")
        elif(i%3==0):
            print("multiple 3")
        else:
            print("flémingite aigüe")

def bouclewhile(a):
    i=0
    while(i<a):
        i+=1
def bouclefor(a):
    bidon=0
    for i in range(a):
        bidon+=1
def listes():
    l1=[]
    for i in range(10):
        l1=l1+[i]
    l2=[]
    for i in range(10):
        l2+=[i]
    l3=[]
    for i in range(10):
        l3.append(i)
    l4=[i for i in range(10)]
    
dis.dis(listes)