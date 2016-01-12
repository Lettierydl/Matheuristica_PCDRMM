************************************************************************
file with basedata            : md74_.bas
initial value random generator: 1291680253
************************************************************************
projects                      :  1
jobs (incl. supersource/sink ):  14
horizon                       :  94
RESOURCES
  - renewable                 :  2   R
  - nonrenewable              :  2   N
  - doubly constrained        :  0   D
************************************************************************
PROJECT INFORMATION:
pronr.  #jobs rel.date duedate tardcost  MPM-Time
    1     12      0       20        8       20
************************************************************************
PRECEDENCE RELATIONS:
jobnr.    #modes  #successors   successors
   1        1          3           2   3   4
   2        3          3           8   9  10
   3        3          3           5   6   9
   4        3          2          11  12
   5        3          2           7  10
   6        3          2           8  10
   7        3          2           8  13
   8        3          1          12
   9        3          3          11  12  13
  10        3          2          11  13
  11        3          1          14
  12        3          1          14
  13        3          1          14
  14        1          0        
************************************************************************
REQUESTS/DURATIONS:
jobnr. mode duration  R 1  R 2  N 1  N 2
------------------------------------------------------------------------
  1      1     0       0    0    0    0
  2      1     3       0    5    0    4
         2     4       0    3    3    0
         3     4       7    0    3    0
  3      1     5       0    6    4    0
         2     6       8    0    3    0
         3     9       7    0    3    0
  4      1     2       5    0    0    6
         2     3       0    5    2    0
         3     8       3    0    0    6
  5      1     2       8    0    0    9
         2     3       0    4    3    0
         3     9       0    4    0    3
  6      1     3       0    5    0    8
         2     8       0    4    7    0
         3    10       0    3    2    0
  7      1     5       0    7   10    0
         2     6       3    0    0    2
         3     7       2    0    6    0
  8      1     1       8    0    0    3
         2     3       5    0    4    0
         3     8       2    0    3    0
  9      1     3       3    0    0    2
         2     5       0   10    3    0
         3     9       0    9    0    2
 10      1     3       1    0    0    8
         2     3       0    4    0    7
         3     7       0    3    0    6
 11      1     5       8    0    0    8
         2     6       0    7    0    5
         3     7       0    7    6    0
 12      1     7       7    0    0    8
         2     9       0    5    9    0
         3     9       4    0    9    0
 13      1     1       2    0   10    0
         2     1       0    7    9    0
         3     7       0    7    8    0
 14      1     0       0    0    0    0
************************************************************************
RESOURCEAVAILABILITIES:
  R 1  R 2  N 1  N 2
   11   12   36   32
************************************************************************
