************************************************************************
file with basedata            : md282_.bas
initial value random generator: 8207
************************************************************************
projects                      :  1
jobs (incl. supersource/sink ):  20
horizon                       :  135
RESOURCES
  - renewable                 :  2   R
  - nonrenewable              :  2   N
  - doubly constrained        :  0   D
************************************************************************
PROJECT INFORMATION:
pronr.  #jobs rel.date duedate tardcost  MPM-Time
    1     18      0       19        4       19
************************************************************************
PRECEDENCE RELATIONS:
jobnr.    #modes  #successors   successors
   1        1          3           2   3   4
   2        3          2           8  11
   3        3          2           7  11
   4        3          3           5  10  11
   5        3          3           6   8  19
   6        3          2           9  12
   7        3          2           9  10
   8        3          3          13  14  18
   9        3          2          14  18
  10        3          3          15  18  19
  11        3          3          12  13  14
  12        3          1          15
  13        3          1          17
  14        3          1          16
  15        3          1          16
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
  2      1     1       7    0    7    0
         2     5       6    0    0    5
         3    10       0    2    0    4
  3      1     8       0    5   10    0
         2     8       6    0    0    7
         3     9       0    5    0    5
  4      1     2       6    0    0    7
         2     2       0    9    0    6
         3     3       0    9    6    0
  5      1     4       4    0    0    9
         2     4       5    0    0    5
         3     6       2    0   10    0
  6      1     1       0    7    0    6
         2     5      10    0    4    0
         3     6       0    2    0    1
  7      1     2       3    0    0    3
         2     7       2    0    8    0
         3     8       1    0    0    2
  8      1     4       2    0    7    0
         2     6       0    6    7    0
         3    10       2    0    6    0
  9      1     1       0    2    0    7
         2     9       8    0    0    4
         3     9       8    0    9    0
 10      1     4       9    0    9    0
         2     5       7    0    6    0
         3     8       0    9    5    0
 11      1     1       7    0    8    0
         2     6       0    8    6    0
         3     8       0    5    0   10
 12      1     2       5    0    9    0
         2     7       0    7    8    0
         3     8       0    4    0    8
 13      1     2       0    4    6    0
         2     5       0    4    0    5
         3     8       4    0    0    3
 14      1     1       9    0    0    3
         2     6       4    0    4    0
         3     9       3    0    0    3
 15      1     1       0    6    0    7
         2     5       6    0    0    4
         3     7       4    0    5    0
 16      1     1       0    5    0    4
         2     4       2    0    6    0
         3     4       2    0    0    4
 17      1     3       0    6    0    9
         2     4       0    5    8    0
         3     7      10    0    7    0
 18      1     1       9    0    9    0
         2     7       5    0    3    0
         3     7       5    0    0    6
 19      1     1       0    7    0    4
         2     7       0    4    0    4
         3     8       2    0    0    4
 20      1     0       0    0    0    0
************************************************************************
RESOURCEAVAILABILITIES:
  R 1  R 2  N 1  N 2
   16   13  125  100
************************************************************************
