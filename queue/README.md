# Queue

## Round-robin Scheduling

This is exmaple implementation of queue and simulates Round-robin scheduling.

As the initial input, it requires number of input and quantum.

Quantum is the limit of time of one process.

If a process takes more time than value of quantum, the remained process will be put to the back of the process list.

After the initial input, process name and the required processing time follow it.

Output will show the order of how the inputs are processed and when they are finished.

```bash
$ g++ round_robin_scheduling.cpp
$ ./a.out
Input:
5 100 # number of input, quantum
p1 150
p2 80
p3 200
p4 350
p5 20
Output:
p2 180
p5 400
p1 450
p3 550
p4 800
```

It is challenging for this code to recognize whether queue is empty.

Both of when queue is empty and full, the start and end pointer are at the same position.

## Animal Shelter

It is implementation of animal shelter which can accommodate only dogs and cats.
And this shelter has first in, first out policy, so there are three options when extracting animals from it.

- extract "dog"
- extract "cat"
- extract "any"

When "any" specified, an animal which was pushed earlier than another is extracted.

Therefore, this shelter is represented with queue.
It can be specified enqueue or dequeue like below.

```bash
$ g++ animal_shelter.cpp
$ ./a.out
# first input is number of command
8
# following inputs are commands, commands are enqueue or dequeue
# command, species, name
enqueue cat tama
enqueue dog pochi
enqueue dog shiro
dequeue cat
tama # result of dequeue is printed out
enqueue cat mike
dequeue dog
pochi
dequeue any
shiro
dequeue cat
mike
```
