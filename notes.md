# Philo

Each philo will be a node a circular chained list.

The main monitor will check in loop the chained list.

The philo will have a structure that contain :

pointers to forks

last time he ate.
	Init to the time when the philo is launched

How many dish he ate.

pid or thread ptr.

array of four functions pointers to call in loop (life cycle)
	take, eat, sleep, think.

