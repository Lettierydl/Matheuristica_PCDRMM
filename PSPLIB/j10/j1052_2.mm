************************************************************************
file with basedata            : mm52_.bas
initial value random generator: 2026569778
************************************************************************
projects                      :  1
jobs (incl. supersource/sink ):  12
horizon                       :  68
RESOURCES
  - renewable                 :  2   R
  - nonrenewable              :  2   N
  - doubly constrained        :  0   D
************************************************************************
PROJECT INFORMATION:
pronr.  #jobs rel.date duedate tardcost  MPM-Time
    1     10      0       18        0       18
************************************************************************
PRECEDENCE RELATIONS:
jobnr.    #modes  #successors   successors
   1        1          3           2   3   4
   2        3          2           6   9
   3        3          2           6   9
   4        3          3           5  10  11
   5        3          1           9
   6        3          2           7  11
   7        3          1           8
   8        3          1          10
   9        3          1          12
  10        3          1          12
  11        3          1          12
  12        1          0        
************************************************************************
REQUESTS/DURATIONS:
jobnr. mode duration  R 1  R 2  N 1  N 2
------------------------------------------------------------------------
  1      1     0       0    0    0    0
  2      1     4       9    5    8    0
         2     6       6    4    6    0
         3     7       4    4    4    0
  3      1     4       7    6    0    9
         2     9       5    5    0    6
         3    10       5    5    6    0
  4      1     3       9    5    7    0
         2     3       9    6    0    3
         3     6       5    4    7    0
  5      1     3       7    5    0    7
         2     5       6    4    3    0
         3     6       5    4    0    7
  6      1     5       7    9    9    0
         2     6       6    8    0    9
         3     9       6    8    6    0
  7      1     3       5    5    0   10
         2     3       6    4    9    0
         3     4       2    2    9    0
  8      1     1       5    6    0    3
         2     1       5    4    9    0
         3     2       4    2    0    3
  9      1     1       8    4    0    4
         2     6       8    4    2    0
         3     8       8    3    0    3
 10      1     5       4    5    0    6
         2     6       3    3    4    0
         3     9       3    2    0    3
 11      1     3       3    7    6    0
         2     5       3    7    0    8
         3     7       3    7    3    0
 12      1     0       0    0    0    0
************************************************************************
RESOURCEAVAILABILITIES:
  R 1  R 2  N 1  N 2
   20   14   63   59
************************************************************************
