max=$2
t=$1
for((n=1;n<max;n++))
do
  ./geante.exe $t $n
done > geante.dat
