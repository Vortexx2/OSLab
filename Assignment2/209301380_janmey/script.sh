echo The name of th script is $0
echo The first argument is $1
echo A list of all the arguments is $*
echo This script places the date into a temp file
echo Called $1.$$
date > $1.$$
ls $1.$$
rm $1.$$
