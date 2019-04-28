#!/bin/bash

echo "=========================="
echo "=======  STARTING  ======="
echo "=========================="
output_path="$HOME/salida_ej2"
echo output_path=$output_path
file_path="$HOME/INICIO.dat"
echo file_path=$file_path
sleep_time=20s
echo sleep_time=$sleep_time

created_files=""

for value in {1..1}
do
  echo
  iteration=$value
  echo ITERATION=$iteration

  file_content="`cat $file_path`" 
  echo file_content=$file_content

  directory="`grep DIRABUS $file_path | cut -d= -f2`"
  echo directory=$directory

  extension="*.txt"
  echo extension=$extension

  output_file="$output_path/$iteration"
  echo OUTPUT_FILE=$output_file
  touch "$output_file"

  find $directory -type f -name $extension | while read txt; do
    echo "$txt" >> "$output_file"
  done

  created_files="$created_files $output_file"
  echo FILES=$created_files
  echo 
  echo "sleeping time..."
  sleep $sleep_time
done

cd $output_path
cat $created_files

echo "=========================="
echo "=======  ALL DONE  ======="
echo "=========================="
