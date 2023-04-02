while :
do
  rev yes 2>&1 | awk -F ' ' '{ print $4 }' | cut -c-3
done