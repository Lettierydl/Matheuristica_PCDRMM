************************************************************************
file with basedata            : c2117_.bas
initial value random generator: 1289322571
************************************************************************
projects                      :  1
jobs (incl. supersource/sink ):  18
horizon                       :  119
RESOURCES
  - renewable                 :  2   R
  - nonrenewable              :  2   N
  - doubly constrained        :  0   D
************************************************************************
PROJECT INFORMATION:
pronr.  #jobs rel.date duedate tardcost  MPM-Time
    1     16      0       19       10       19
************************************************************************
PRECEDENCE RELATIONS:
jobnr.    #modes  #successors   successors
   1        1          3           2   3   4
   2        3          3          11  13  14
   3        3          3           6   7  13
   4        3          3           5   6   7
   5        3          3           8  10  13
   6        3          3           8   9  10
   7        3          3           9  10  11
   8        3          3          11  12  14
   9        3          2          12  16
  10        3          3          12  15  16
  11        3          1          17
  12        3          1          17
  13        3          1          15
  14        3          3          15  16  17
  15        3          1          18
  16        3          1          18
  17        3          1          18
  18        1          0        
************************************************************************
REQUESTS/DURATIONS:
jobnr. mode duration  R 1  R 2  N 1  N 2
------------------------------------------------------------------------
  1      1     0       0    0    0    0
  2      1     2       0    3    8    0
         2     5       5    0    0    5
         3     7       4    0    7    0
  3      1     3       0   10    0    6
         2     5       0   10    5    0
         3     5       1    0    5    0
  4      1     2       9    0    0    8
         2     3       8    0    0    8
         3     5       8    0    0    7
  5      1     2       0    6    0    7
         2     6       0    4    9    0
         3    10       3    0    4    0
  6      1     3       5    0    8    0
         2     6       4    0    8    0
         3     8       4    0    0    8
  7      1     4       2    0    0    6
         2     7       1    0    0    5
         3    10       1    0    4    0
  8      1     2       7    0    5    0
         2     6       1    0    0    2
         3     9       0    1    4    0
  9      1     4       0    7    0    8
         2     5       0    4    7    0
         3     9       6    0    3    0
 10      1     2       0    4    0    6
         2     2       8    0    0    6
         3     3       7    0    0    5
 11      1     1       7    0    4    0
         2     5       0   10    0    5
         3     9       0    8    0    5
 12      1     5       6    0    6    0
         2     6       6    0    0    3
         3     6       0    8    5    0
 13      1     2       0    6    0    8
         2     2       8    0    0    9
         3     6       0    6    6    0
 14      1     2       0    6    4    0
         2     3       0    6    3    0
         3     8       0    5    0    2
 15      1     6       8    0    0    8
         2     8       6    0    8    0
         3     9       0    1    0    7
 16      1     5       7    0    0    9
         2     6       7    0    0    7
         3    10       7    0    0    3
 17      1     3       0    8    0    4
         2     4       4    0    0    4
         3     5       3    0    0    3
 18      1     0       0    0    0    0
************************************************************************
RESOURCEAVAILABILITIES:
  R 1  R 2  N 1  N 2
   13   10   56   77
************************************************************************
