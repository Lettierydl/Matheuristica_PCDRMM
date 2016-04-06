************************************************************************
file with basedata            : md150_.bas
initial value random generator: 9671
************************************************************************
projects                      :  1
jobs (incl. supersource/sink ):  16
horizon                       :  84
RESOURCES
  - renewable                 :  2   R
  - nonrenewable              :  2   N
  - doubly constrained        :  0   D
************************************************************************
PROJECT INFORMATION:
pronr.  #jobs rel.date duedate tardcost  MPM-Time
    1     14      0       20        6       20
************************************************************************
PRECEDENCE RELATIONS:
jobnr.    #modes  #successors   successors
   1        1          3           2   3   4
   2        3          3           5   6  12
   3        3          2           7  10
   4        3          3           5   8  15
   5        3          2          11  14
   6        3          2           7  11
   7        3          2           9  14
   8        3          2          11  12
   9        3          2          13  15
  10        3          3          12  13  15
  11        3          1          13
  12        3          1          14
  13        3          1          16
  14        3          1          16
  15        3          1          16
  16        1          0        
************************************************************************
REQUESTS/DURATIONS:
jobnr. mode duration  R 1  R 2  N 1  N 2
------------------------------------------------------------------------
  1      1     0       0    0    0    0
  2      1     4       9    3    7    0
         2     5       7    2    2    0
         3     5       7    2    0    5
  3      1     3      10    8    0    3
         2     3      10    9    3    0
         3     4       7    7    0    2
  4      1     5      10   10    6    0
         2     7       8    9    6    0
         3     8       6    8    3    0
  5      1     5       3    3    7    0
         2     6       3    2    0    5
         3     8       2    1    4    0
  6      1     3       6    8    0    6
         2     3       6    8    2    0
         3    10       5    8    0    5
  7      1     1       9    8    0    6
         2     2       9    5    0    5
         3     3       8    2    6    0
  8      1     1       7    4    0    4
         2     2       6    4    0    2
         3     3       6    4    8    0
  9      1     3      10    9    0    6
         2     3      10    9    7    0
         3     4      10    9    3    0
 10      1     2       4    2    0    4
         2     2       5    3    5    0
         3     3       3    1    0    6
 11      1     8      10    4    0    8
         2     9       6    4    0    8
         3    10       2    3    0    6
 12      1     1       8    9    8    0
         2     4       7    9    0    8
         3     6       4    8    0    6
 13      1     2       6    2    0    6
         2     6       6    2    5    0
         3     7       4    1    0    6
 14      1     2       7    7    9    0
         2     3       7    6    0   10
         3     3       6    5    9    0
 15      1     3       7    9    7    0
         2     8       7    8    0    7
         3    10       5    7    0    1
 16      1     0       0    0    0    0
************************************************************************
RESOURCEAVAILABILITIES:
  R 1  R 2  N 1  N 2
   20   16   61   62
************************************************************************
