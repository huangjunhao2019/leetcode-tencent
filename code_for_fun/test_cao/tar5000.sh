#!/bin/bash
i=0
start=`date +%s`
tar -zcvf output.tar.gz output/
end=`date +%s`
time=`echo $start $end | awk '{print $2-$1}'`
echo $time
