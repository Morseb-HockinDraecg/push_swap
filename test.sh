i=0
while ((i<10));do

 cat  "results/$i""_in" | ./launch_test.sh;
 ((i+=1))
done
