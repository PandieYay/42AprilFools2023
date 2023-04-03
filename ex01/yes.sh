while :
do
  rev yes 2>&1 | awk -F ' ' '{ print $2 }' | cut -c-3
done