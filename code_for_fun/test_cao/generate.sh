#!/bin/bash
i=0
path="./output/test"
start=`date +%s`
for((i=0;i<5000;i++))
do
	subPath="$i"
	dd if=/dev/zero of=${path}${subPath} bs=1k count=1
done
end=`date +%s`
time=`echo $start $end | awk '{print $2-$1}'`
echo $time
