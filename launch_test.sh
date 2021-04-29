if [ $# != 0 ]; then
	ARG=$@; ./bin/push_swap $ARG | ./bin/checker $ARG
else
	ARG="1 63 3 87 23"; ./bin/push_swap $ARG | ./bin/checker $ARG
fi
