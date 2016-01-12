************************************************************************
file with basedata            : md318_.bas
initial value random generator: 1057183310
************************************************************************
projects                      :  1
jobs (incl. supersource/sink ):  20
horizon                       :  131
RESOURCES
  - renewable                 :  2   R
  - nonrenewable              :  2   N
  - doubly constrained        :  0   D
************************************************************************
PROJECT INFORMATION:
pronr.  #jobs rel.date duedate tardcost  MPM-Time
    1     18      0       24       10       24
************************************************************************
PRECEDENCE RELATIONS:
jobnr.    #modes  #successors   successors
   1        1          3           2   3   4
   2        3          2           8  14
   3        3          3           5   8   9
   4        3          3           5   6  10
   5        3          1          18
   6        3          3           7   9  16
   7        3          1          15
   8        3          3          11  12  13
   9        3          2          13  18
  10        3          2          11  14
  11        3          1          19
  12        3          3          15  16  19
  13        3          2          17  19
  14        3          1          16
  15        3          2          17  18
  16        3          1          17
  17        3          1          20
  18        3          1          20
  19        3          1          20
  20        1          0        
************************************************************************
REQUESTS/DURATIONS:
jobnr. mode duration  R 1  R 2  N 1  N 2
------------------------------------------------------------------------
  1      1     0       0    0    0    0
  2      1     5       3   10    8    8
         2     6       3    5    6    7
         3     8       2    3    5    7
  3      1     1       8    9    6    5
         2     3       6    8    4    4
         3     5       6    7    1    3
  4      1     4       7    9    6    8
         2     7       5    7    5    8
         3    10       3    4    5    3
  5      1     3       9    8    8    5
         2     4       8    7    7    5
         3    10       8    7    5    1
  6      1     2       3    8    6   10
         2     3       1    5    5   10
         3     3       2    6    3   10
  7      1     1       8    8    5    3
         2     1      10    7    4    4
         3     6       5    7    3    2
  8      1     5       6    5    7    4
         2     6       5    4    6    4
         3     8       2    4    6    4
  9      1     3       7    6    8    7
         2     3       8    4    7    8
         3     7       6    3    7    4
 10      1     2       8    6   10    7
         2     8       6    5    8    6
         3     9       5    5    3    6
 11      1     3       7    3    8    8
         2     4       4    1    7    4
         3     4       5    1    5    3
 12      1     4       8   10    5    7
         2     4       9    6    5    8
         3     6       7    4    1    4
 13      1     4       9    6   10    7
         2     7       8    6   10    7
         3     9       7    3   10    6
 14      1     3       6   10    5    5
         2     3       8   10    8    4
         3     4       4    6    5    3
 15      1     3       6    9    7    6
         2     6       4    7    7    5
         3     9       3    3    2    4
 16      1     8       8    6    5    9
         2     8       7    6    5   10
         3     9       7    6    5    6
 17      1     2       8    6    9    7
         2     5       7    4    9    5
         3     9       4    2    8    3
 18      1     1       2    2    4   10
         2     6       2    1    3    8
         3     8       1    1    3    5
 19      1     3       8   10    4    7
         2     6       7   10    4    5
         3     7       7   10    3    1
 20      1     0       0    0    0    0
************************************************************************
RESOURCEAVAILABILITIES:
  R 1  R 2  N 1  N 2
   25   24  124  127
************************************************************************
