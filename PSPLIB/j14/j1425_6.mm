************************************************************************
file with basedata            : md153_.bas
initial value random generator: 2052934327
************************************************************************
projects                      :  1
jobs (incl. supersource/sink ):  16
horizon                       :  110
RESOURCES
  - renewable                 :  2   R
  - nonrenewable              :  2   N
  - doubly constrained        :  0   D
************************************************************************
PROJECT INFORMATION:
pronr.  #jobs rel.date duedate tardcost  MPM-Time
    1     14      0       14        8       14
************************************************************************
PRECEDENCE RELATIONS:
jobnr.    #modes  #successors   successors
   1        1          3           2   3   4
   2        3          3           5   6  10
   3        3          2          12  15
   4        3          3           5   7  14
   5        3          2           8   9
   6        3          3           7   8  12
   7        3          1           9
   8        3          2          11  15
   9        3          2          11  15
  10        3          2          11  14
  11        3          1          13
  12        3          2          13  14
  13        3          1          16
  14        3          1          16
  15        3          1          16
  16        1          0        
************************************************************************
REQUESTS/DURATIONS:
jobnr. mode duration  R 1  R 2  N 1  N 2
------------------------------------------------------------------------
  1      1     0       0    0    0    0
  2      1     3       0    6    7    0
         2     7       8    0    6    0
         3     8       0    5    0    5
  3      1     3       0    6    0    9
         2     5       0    5    0    7
         3     6       0    5    7    0
  4      1     2       0   10    6    0
         2     8       2    0    6    0
         3    10       0    6    4    0
  5      1     1       8    0    0    3
         2     1       8    0    9    0
         3     9       7    0    0    3
  6      1     2       0    6    0    3
         2     4       3    0    8    0
         3     9       0    2    0    2
  7      1     2       7    0    0    9
         2     7       5    0    0    6
         3     8       0    9    7    0
  8      1     6       0    8    0    4
         2     7       4    0    1    0
         3    10       0    5    0    3
  9      1     2       5    0    0    9
         2     7       0    7   10    0
         3    10       0    6    0    5
 10      1     2       0   10    7    0
         2     4       0    7    7    0
         3     6       6    0    7    0
 11      1     1       6    0    0    2
         2     2       5    0    0    2
         3     8       0    5    9    0
 12      1     1       4    0    0    5
         2     4       0    7    4    0
         3     6       4    0    3    0
 13      1     2       0    6    0   10
         2     5       0    4    0    8
         3    10       0    1    0    7
 14      1     3       6    0   10    0
         2     5       5    0    8    0
         3     6       3    0    0    5
 15      1     1       2    0    3    0
         2     3       0    5    0    6
         3     4       0    4    0    5
 16      1     0       0    0    0    0
************************************************************************
RESOURCEAVAILABILITIES:
  R 1  R 2  N 1  N 2
   11   10   88   70
************************************************************************
