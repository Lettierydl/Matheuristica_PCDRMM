************************************************************************
file with basedata            : md240_.bas
initial value random generator: 1143863858
************************************************************************
projects                      :  1
jobs (incl. supersource/sink ):  18
horizon                       :  137
RESOURCES
  - renewable                 :  2   R
  - nonrenewable              :  2   N
  - doubly constrained        :  0   D
************************************************************************
PROJECT INFORMATION:
pronr.  #jobs rel.date duedate tardcost  MPM-Time
    1     16      0       23       15       23
************************************************************************
PRECEDENCE RELATIONS:
jobnr.    #modes  #successors   successors
   1        1          3           2   3   4
   2        3          3           5   6   8
   3        3          2           7  14
   4        3          3           6   7   9
   5        3          3          10  12  14
   6        3          3          11  13  17
   7        3          3          10  12  15
   8        3          2          10  17
   9        3          3          11  12  13
  10        3          1          13
  11        3          1          14
  12        3          1          17
  13        3          1          16
  14        3          1          15
  15        3          1          18
  16        3          1          18
  17        3          1          18
  18        1          0        
************************************************************************
REQUESTS/DURATIONS:
jobnr. mode duration  R 1  R 2  N 1  N 2
------------------------------------------------------------------------
  1      1     0       0    0    0    0
  2      1     1      10    6    7    9
         2     6      10    4    5    8
         3    10      10    2    3    8
  3      1     3       5    2   10    7
         2     7       4    2    7    3
         3     8       4    1    7    1
  4      1     8       8    3    9    7
         2     8       7    4    7    8
         3    10       5    2    7    7
  5      1     4       7    4   10    9
         2     5       7    4    8    7
         3     7       7    3    7    5
  6      1     5       7    4    9    9
         2     5       6    5    9    9
         3     9       6    1    8    7
  7      1     1       5    8    6    3
         2     3       3    8    5    2
         3     6       2    7    2    2
  8      1     3       4    6    9    9
         2     8       4    5    8    8
         3     9       1    5    7    8
  9      1     3      10    6   10    9
         2     7       9    6    9    9
         3    10       9    3    7    8
 10      1     1       6   10    6    7
         2     4       4    9    6    6
         3     8       3    9    5    4
 11      1     5       5    7   10    6
         2     5       8    8   10    5
         3     9       4    6    8    5
 12      1     2       8    9    4    7
         2     3       6    6    2    5
         3     7       1    1    1    3
 13      1     1       8    8    5    7
         2     9       8    8    4    5
         3    10       7    5    4    4
 14      1     1       9    4    8    4
         2     7       8    2    6    4
         3     8       7    2    6    3
 15      1     4       8    6    8    7
         2     4       9    5    8    7
         3     9       2    4    8    7
 16      1     7       7    4    2    7
         2     8       5    3    2    7
         3    10       5    3    1    4
 17      1     2       6    7   10    2
         2     5       6    7    8    2
         3     7       3    4    8    1
 18      1     0       0    0    0    0
************************************************************************
RESOURCEAVAILABILITIES:
  R 1  R 2  N 1  N 2
   24   23  106   94
************************************************************************
