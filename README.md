# skia-test

## Introduction

This tests https://bugs.chromium.org/p/skia/issues/detail?id=13894

The expectation, that at some value, the RTL should have offset of 4, however it seems that the maximum is 3.

It seems to originate from `globalClusterIndex` in Run.h.

## Linux results

### LTR

### RTL


## Windows results

It is noted that on Flutter, the values are something like:

```
[TextBox.fromLTRBD(0.2, -0.4, 25.0, 16.0, TextDirection.rtl)]
-40: TextPosition(offset: 3, affinity: TextAffinity.downstream)
-30: TextPosition(offset: 3, affinity: TextAffinity.downstream)
-20: TextPosition(offset: 3, affinity: TextAffinity.downstream)
-10: TextPosition(offset: 3, affinity: TextAffinity.downstream)
0: TextPosition(offset: 3, affinity: TextAffinity.downstream)
10: TextPosition(offset: 2, affinity: TextAffinity.downstream)
20: TextPosition(offset: 1, affinity: TextAffinity.upstream)
30: TextPosition(offset: 0, affinity: TextAffinity.downstream)
40: TextPosition(offset: 0, affinity: TextAffinity.downstream)
```

### LTR
```
left: 0.5
top: -0.21
right: 45.84
bottom: 31
-100: 0
-90: 0
-80: 0
-70: 0
-60: 0
-50: 0
-40: 0
-30: 0
-20: 0
-10: 0
0: 0
10: 1
20: 1
30: 2
40: 3
50: 3
60: 4
70: 4
80: 4
90: 4
```
### RTL

```
left: 862.42  # what are those very big values, is it because of the font?
top: -0.21
right: 900    # what are those very big values, is it because of the font?
bottom: 31
-100: 3
-90: 3
-80: 3
-70: 3
-60: 3
-50: 3
-40: 3
-30: 3
-20: 3
-10: 3
0: 3
10: 3
20: 3
30: 3
40: 3
50: 3
60: 3
70: 3
80: 3
90: 3
```
