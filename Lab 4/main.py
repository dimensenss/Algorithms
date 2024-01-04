""" 
import timeit
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import matplotlib
import sys

sys.setrecursionlimit(10000)

def heapify(arr, n, i):
    largest = i
    l = 2 * i + 1
    r = 2 * i + 2
    if l < n and arr[i] < arr[l]:
        largest = l
    if r < n and arr[largest] < arr[r]:
        largest = r
    if largest != i:
        (arr[i], arr[largest]) = (arr[largest], arr[i])  # swap
        heapify(arr, n, largest)

def heapSort(arr):
    n = len(arr)
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)
    for i in range(n - 1, 0, -1):
        (arr[i], arr[0]) = (arr[0], arr[i])  # swap
        heapify(arr, i, 0)

def insertion(arrayToSort):
    a = arrayToSort.copy()
    for i in range(len(a)):
        v = a[i]
        j = i
        while (a[j-1] > v) and (j > 0):
            a[j] = a[j-1]
            j = j - 1
        a[j] = v
    return a

def qsort(arr):
    if len(arr) <= 1:
        return arr
    else:
        return qsort([x for x in arr[1:] if x < arr[0]])
        + [arr[0]]
        + qsort([x for x in arr[1:] if x >= arr[0]])


res = pd.DataFrame(
    index=['qsort', 'heapSort', 'insertion'],
    columns=np.logspace(1, 4, 4).astype(int),
    dtype=float
)
data = int(input('Chose:\n1 - Ordered array\n2 - Reverse array\n3 - Unordered array\n'))

for j in res.columns:
    if data == 1:
        a = np.arange(j)
    if data == 2:
        a = np.arange(j)
        a = a[::-1]
    if data == 3:
        a = np.random.choice(j, j, replace=False)
    
    for i in res.index:
        if i == 'qsort' and j == 10000 and data == 2:
            #i = 'qsort_'
            a = np.arange(2000)
            a = a[::-1]

        
        stmt = '{}(a)'.format(i)
        setp = 'from __main__ import a, {}'.format(i)
        print('processing [{}]\tarray size: {}'.format(i,j), end='')
        res.at[i, j] = timeit.timeit(stmt, setp, number=50)
        print('\t\ttiming:\t{}'.format(res.at[i, j]))
print(res)
plt.figure()
ax = res.T.plot(loglog=True, style='-o', figsize=(10,8))
ax.set_xlabel('array size')
ax.set_ylabel('time (sec)')
plt.savefig('D:\\Programing\\Algoritms\\result.png')




class DataItem(object):
    __slots__ = ['name', 'age', 'address']
    def __init__(self, name, age, address):
        self.name = name
        self.age = age
        self.address = address
        
         """
        
""" list_a = [1, 10, 100]
list_b = [2, 20, 200]
list_c = [3, 30, 300]

for a in list_a:
    for b in list_b:
        for c in list_c:
            if a + b + c == 600:
                print(a, b, c)
# 100 200 300
 """
from itertools import product

list_a = [1, 10, 100]
list_b = [2, 20, 200]
list_c = [3, 30, 300]

for a, b, c in product(list_a, list_b, list_c):
    if a + b + c == 600:
        print(a, b, c)
# 100 200 300