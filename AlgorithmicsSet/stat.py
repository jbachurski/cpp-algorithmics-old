import os
import collections
c = collections.Counter()
for filename in os.listdir():
    if filename in __file__:
        continue
    c[filename[0]] += 1
print(c.most_common(), sum(c.values()))
input()
