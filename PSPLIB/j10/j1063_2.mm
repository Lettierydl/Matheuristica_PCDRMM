************************************************************************
file with basedata            : mm63_.bas
initial value random generator: 894678482
************************************************************************
projects                      :  1
jobs (incl. supersource/sink ):  12
horizon                       :  74
RESOURCES
  - renewable                 :  2   R
  - nonrenewable              :  2   N
  - doubly constrained        :  0   D
************************************************************************
PROJECT INFORMATION:
pronr.  #jobs rel.date duedate tardcost  MPM-Time
    1     10      0       17        6       17
************************************************************************
PRECEDENCE RELATIONS:
jobnr.    #modes  #successors   successors
   1        1          3           2   3   4
   2        3          1           5
   3        3          2           7   8
   4        3          2           9  11
   5        3          1           6
   6        3          3           8   9  10
   7        3          2           9  10
   8        3          1          11
   9        3          1          12
  10        3          1          12
  11        3          1          12
  12        1          0        
************************************************************************
REQUESTS/DURATIONS:
jobnr. mode duration  R 1  R 2  N 1  N 2
------------------------------------------------------------------------
  1      1     0       0    0    0    0
  2      1     3       8    4    9    9
         2     3       5    3    9   10
         3     4       3    2    9    7
  3      1     3       3    6    8    6
         2     4       3    6    6    5
         3     5       1    5    6    5
  4      1     2      10    9    7    5
         2     6      10    9    5    4
         3     9       9    7    2    1
  5      1     6      10    3    4    5
         2     8       9    3    2    5
         3     9       8    1    2    5
  6      1     2       9    6   10    4
         2     8       8    4    9    4
         3     9       8    4    7    3
  7      1     2       9    7    4    7
         2     6       8    5    3    6
         3     7       8    4    2    4
  8      1     1       9    7    3    9
         2     2       8    6    3    9
         3    10       6    5    2    8
  9      1     2       5    6    6    7
         2     4       4    5    6    6
         3     6       4    5    6    5
 10      1     2       5    9    1    4
         2     4       5    9    1    3
         3     6       5    9    1    2
 11      1     5       8   10    7    8
         2     5       8   10    6    9
         3     9       8   10    5    7
 12      1     0       0    0    0    0
************************************************************************
RESOURCEAVAILABILITIES:
  R 1  R 2  N 1  N 2
   21   25   54   60
************************************************************************
