i=0
while ((i<10));do

 cat  "results/$i""_in" | ./go.sh;
 ((i+=1))
done
