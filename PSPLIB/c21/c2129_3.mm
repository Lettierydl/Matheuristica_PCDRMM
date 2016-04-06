************************************************************************
file with basedata            : c2129_.bas
initial value random generator: 1187805168
************************************************************************
projects                      :  1
jobs (incl. supersource/sink ):  18
horizon                       :  123
RESOURCES
  - renewable                 :  2   R
  - nonrenewable              :  2   N
  - doubly constrained        :  0   D
************************************************************************
PROJECT INFORMATION:
pronr.  #jobs rel.date duedate tardcost  MPM-Time
    1     16      0       17       10       17
************************************************************************
PRECEDENCE RELATIONS:
jobnr.    #modes  #successors   successors
   1        1          3           2   3   4
   2        3          3           7   8   9
   3        3          3           6   7  11
   4        3          3           5   6   7
   5        3          3          10  11  13
   6        3          2          13  14
   7        3          2          10  12
   8        3          2          12  14
   9        3          3          10  11  12
  10        3          1          14
  11        3          3          15  16  17
  12        3          2          13  15
  13        3          2          16  17
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
  2      1     1       7    6    9    0
         2     3       7    5    0    5
         3     5       4    5    0    3
  3      1     1       2    6    0   10
         2     6       2    4    0    9
         3     6       2    5    2    0
  4      1     2       5    4    0    7
         2     4       3    3    0    6
         3    10       3    3    0    5
  5      1     1       6    9    8    0
         2     2       5    7    0    3
         3    10       3    5    7    0
  6      1     2      10    2    0    9
         2     6       7    2    0    2
         3    10       5    1    4    0
  7      1     9       5    9    0    9
         2     9       5    8    8    0
         3    10       4    7    0    9
  8      1     3       5    4    0    5
         2     6       4    3    0    4
         3     7       2    1    7    0
  9      1     2       5    3    0    8
         2     4       3    3    0    7
         3     5       2    2    0    6
 10      1     1       7    9    7    0
         2     2       6    8    5    0
         3     8       5    6    4    0
 11      1     2       7    7    0    4
         2     2       5    7    8    0
         3     5       4    7    8    0
 12      1     1       7    3    9    0
         2     5       3    3    5    0
         3     9       2    2    0    5
 13      1     2       4    7    0    2
         2     4       3    6    2    0
         3     7       3    4    0    2
 14      1     2       3    7    6    0
         2     3       3    3    5    0
         3     9       3    1    0    1
 15      1     3       3    2    7    0
         2     4       3    1    0    9
         3     8       2    1    0    4
 16      1     3       3    8    6    0
         2     3       3   10    0    3
         3     7       3    8    0    2
 17      1     2       8    5    0    8
         2     5       8    4    0    8
         3     7       7    4    8    0
 18      1     0       0    0    0    0
************************************************************************
RESOURCEAVAILABILITIES:
  R 1  R 2  N 1  N 2
   13   13   91   88
************************************************************************
