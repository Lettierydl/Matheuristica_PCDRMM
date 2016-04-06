************************************************************************
file with basedata            : md378_.bas
initial value random generator: 173125229
************************************************************************
projects                      :  1
jobs (incl. supersource/sink ):  22
horizon                       :  163
RESOURCES
  - renewable                 :  2   R
  - nonrenewable              :  2   N
  - doubly constrained        :  0   D
************************************************************************
PROJECT INFORMATION:
pronr.  #jobs rel.date duedate tardcost  MPM-Time
    1     20      0       27        8       27
************************************************************************
PRECEDENCE RELATIONS:
jobnr.    #modes  #successors   successors
   1        1          3           2   3   4
   2        3          3           5   8  13
   3        3          3           9  10  14
   4        3          1          12
   5        3          3           6   7  11
   6        3          3           9  12  17
   7        3          1          21
   8        3          1          15
   9        3          1          15
  10        3          2          11  13
  11        3          2          18  19
  12        3          3          18  19  20
  13        3          3          15  17  21
  14        3          3          16  17  18
  15        3          1          16
  16        3          1          20
  17        3          2          19  20
  18        3          1          21
  19        3          1          22
  20        3          1          22
  21        3          1          22
  22        1          0        
************************************************************************
REQUESTS/DURATIONS:
jobnr. mode duration  R 1  R 2  N 1  N 2
------------------------------------------------------------------------
  1      1     0       0    0    0    0
  2      1     6       9    0    8    9
         2     7       6    0    3    7
         3     9       4    0    1    5
  3      1     4       8    0    7    8
         2     6       0    8    7    5
         3     9       8    0    7    4
  4      1     3       0    4    8    6
         2     3       8    0    7    6
         3     9       8    0    5    6
  5      1     1       0    5    9    5
         2     7       0    5    8    5
         3    10       0    4    7    5
  6      1     3       0    8    9    6
         2     3       2    0    6    6
         3     7       1    0    5    6
  7      1     1       5    0   10    3
         2     3       5    0    8    2
         3    10       5    0    5    1
  8      1     2       8    0    3    5
         2     7       5    0    3    4
         3     9       5    0    2    4
  9      1     6       0    3    2    3
         2     6       8    0    2    3
         3    10       0    3    1    3
 10      1     1       0    4   10   10
         2     4       4    0   10    9
         3     7       0    3    9    9
 11      1     2       4    0    4    5
         2     5       0    9    2    5
         3     5       3    0    1    5
 12      1     3       0    3    5    8
         2     5       6    0    5    8
         3     6       4    0    4    8
 13      1     3       7    0    3    6
         2     3       0    6    4    5
         3     7       0    5    1    2
 14      1     2       0    6    6    6
         2     3       4    0    3    4
         3     4       0    6    3    3
 15      1     1       0    1    7   10
         2     7       0    1    7    8
         3     8       0    1    7    7
 16      1     6       6    0    2    7
         2     8       0    7    2    6
         3    10       0    4    2    4
 17      1     3       8    0    6    8
         2     6       0    6    4    8
         3     9       0    5    2    8
 18      1     2       5    0    8    5
         2     4       0    7    8    5
         3    10       0    6    8    5
 19      1     2       0    7    2    4
         2     9       0    6    1    4
         3    10       9    0    1    1
 20      1     4       8    0    7    5
         2     6       0    8    7    5
         3     7       8    0    4    5
 21      1     4       0    2    8    8
         2     6       0    1    6    7
         3     7       0    1    5    7
 22      1     0       0    0    0    0
************************************************************************
RESOURCEAVAILABILITIES:
  R 1  R 2  N 1  N 2
   15   17  125  127
************************************************************************
