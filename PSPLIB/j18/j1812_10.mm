************************************************************************
file with basedata            : md268_.bas
initial value random generator: 624479474
************************************************************************
projects                      :  1
jobs (incl. supersource/sink ):  20
horizon                       :  140
RESOURCES
  - renewable                 :  2   R
  - nonrenewable              :  2   N
  - doubly constrained        :  0   D
************************************************************************
PROJECT INFORMATION:
pronr.  #jobs rel.date duedate tardcost  MPM-Time
    1     18      0       23        2       23
************************************************************************
PRECEDENCE RELATIONS:
jobnr.    #modes  #successors   successors
   1        1          3           2   3   4
   2        3          3           5   9  15
   3        3          2           7  15
   4        3          3           8  12  19
   5        3          3           6   7  10
   6        3          1          11
   7        3          2          17  18
   8        3          3           9  11  13
   9        3          2          14  17
  10        3          3          11  14  19
  11        3          1          18
  12        3          2          16  17
  13        3          2          14  15
  14        3          1          16
  15        3          1          16
  16        3          1          18
  17        3          1          20
  18        3          1          20
  19        3          1          20
  20        1          0        
************************************************************************
REQUESTS/DURATIONS:
jobnr. mode duration  R 1  R 2  N 1  N 2
------------------------------------------------------------------------
  1      1     0       0    0    0    0
  2      1     1       5    0    0    6
         2     3       5    0    3    0
         3     4       4    0    0    5
  3      1     3       0    7    4    0
         2     4       0    6    0    6
         3     9       0    6    0    4
  4      1     2      10    0    0    4
         2     3       0    5    0    4
         3     4       0    4    4    0
  5      1     2       0    5    0    9
         2     4       7    0    6    0
         3     8       0    5    0    8
  6      1     8       5    0    6    0
         2     9       0    5    4    0
         3     9       5    0    0    6
  7      1     6       0    8    8    0
         2     6      10    0    7    0
         3     7       0    8    0   10
  8      1     5       0    5    0    7
         2     6       9    0    0    7
         3    10       0    5    5    0
  9      1     2       0    7    0    3
         2     4       0    6    9    0
         3     9       6    0    5    0
 10      1     4       7    0    5    0
         2    10       5    0    0    6
         3    10       6    0    0    4
 11      1     6      10    0    9    0
         2     9       7    0    8    0
         3    10       0   10    0    6
 12      1     1       1    0    6    0
         2     3       0    2    0    6
         3     6       0    2    5    0
 13      1     1       5    0    0    5
         2     3       0    5    0    5
         3     4       0    3    4    0
 14      1     5       9    0    9    0
         2     7       8    0    0    7
         3    10       0    7    0    7
 15      1     3      10    0    5    0
         2     5       9    0    0    3
         3    10       0    1    0    3
 16      1     2       8    0    2    0
         2     3       6    0    0    5
         3     5       0    7    1    0
 17      1     3       0    8    8    0
         2     5       7    0    0    7
         3     7       0    5    7    0
 18      1     6       4    0    0    6
         2     6       0    4    0    9
         3     9       6    0    0    3
 19      1     5       0    8    6    0
         2     7       0    5    4    0
         3     9       0    4    0    9
 20      1     0       0    0    0    0
************************************************************************
RESOURCEAVAILABILITIES:
  R 1  R 2  N 1  N 2
   33   33   50   59
************************************************************************
