************************************************************************
file with basedata            : c2152_.bas
initial value random generator: 1410975646
************************************************************************
projects                      :  1
jobs (incl. supersource/sink ):  18
horizon                       :  124
RESOURCES
  - renewable                 :  2   R
  - nonrenewable              :  2   N
  - doubly constrained        :  0   D
************************************************************************
PROJECT INFORMATION:
pronr.  #jobs rel.date duedate tardcost  MPM-Time
    1     16      0       17        9       17
************************************************************************
PRECEDENCE RELATIONS:
jobnr.    #modes  #successors   successors
   1        1          3           2   3   4
   2        3          3           5   6   7
   3        3          3           5   9  11
   4        3          3          10  12  14
   5        3          2          14  16
   6        3          3           9  10  12
   7        3          3           8  10  14
   8        3          3           9  11  12
   9        3          3          13  15  16
  10        3          3          11  13  15
  11        3          2          16  17
  12        3          1          13
  13        3          1          17
  14        3          2          15  17
  15        3          1          18
  16        3          1          18
  17        3          1          18
  18        1          0        
************************************************************************
REQUESTS/DURATIONS:
jobnr. mode duration  R 1  R 2  N 1  N 2
------------------------------------------------------------------------
  1      1     0       0    0    0    0
  2      1     1       7    0   10    3
         2     5       7    0    8    3
         3     7       0    2    5    2
  3      1     1       0    5    7    8
         2     2       8    0    6    6
         3    10       5    0    5    3
  4      1     3       0   10    5    8
         2     5       8    0    4    7
         3     8       7    0    4    6
  5      1     3       3    0    2    5
         2     5       2    0    2    5
         3     6       2    0    2    4
  6      1     3       0   10   10    4
         2     4       0   10    7    4
         3    10       0    9    4    4
  7      1     3       0    7    6    2
         2     3       5    0    6    2
         3    10       5    0    4    1
  8      1     3       0    7    9    7
         2     5       8    0    8    4
         3     9       4    0    6    3
  9      1     1       0    1    9    9
         2     1       0    2    8    5
         3     3       4    0    6    1
 10      1     2       8    0    5    7
         2     9       0    4    5    4
         3    10       0    4    4    4
 11      1     7       0    9   10    9
         2     9       0    7    7    6
         3    10       0    6    6    6
 12      1     1       0    8    8   10
         2     3       0    8    5    9
         3     6       0    6    3    7
 13      1     2       6    0   10    2
         2     6       5    0   10    2
         3     8       3    0    9    2
 14      1     7       0   10    5    8
         2     8       0    7    4    5
         3     9       0    4    4    1
 15      1     2       0    8    6    6
         2     4       0    4    3    6
         3     4       4    0    5    5
 16      1     3       6    0    3    7
         2     3       0   10    3    6
         3     4       0   10    3    3
 17      1     1       0    7    7    8
         2     9       4    0    6    8
         3    10       0    6    5    7
 18      1     0       0    0    0    0
************************************************************************
RESOURCEAVAILABILITIES:
  R 1  R 2  N 1  N 2
   23   24  102   92
************************************************************************
