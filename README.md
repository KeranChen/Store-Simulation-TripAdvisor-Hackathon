# Store-Simulation-TripAdvisor-Hackathon
This is a TripAdvisor 2016 Hackathon project, that simulates the retrieval and packing of orders using 2 different methods, and print the total time needed.

Title: Nozama Store
Author: Kaiyun Chen

Purpose: 
In this project,I simulated the operations of an order processing facility
for a top online retailer called Nozama Online.
The warehouse facility has two main functions: retrieving an order and 
packaging an order. 
The warehouse has one retrieval unit, and some positive (nonzero) number 
of packaging units. 
In the simulation, I will use 2 different method to distribute orders, after
they finish being fetched, to different Packing Units--- Round Robin and 
Shortest Time

Ack:
I finished it myself

Files:
testNozama.cpp: the main functions that runs the whole simulation
Nozama.cpp: implementation of Nozama
Nozama.h: the Nozama stores. Contains all the tools we need for this simulation
Fetch.cpp: implementation of Fetch
Fetch.h: The feaching Unit 
Order.h: struct of an order
Orderqueue.cpp: implementation of Orderqueue
Orderqueue.h: a queue that stores orders
Packer.cpp: implementation of packer
Packer.h: a Packing Unit
PackerManager.cpp: implementation of PackerManager
PackerManager.h: the arrays of PackingUnits
Parser.cpp: implentation for Parser
Parser.h: the parser that reads in all the input
Statistitian.cpp: implementation of statistitian
Statistitian.h: to manage and provide the result
Time.cpp: implementation of time
Time.h: a class that represents time
Makefile: to complie the program
README: documentation


How to complie and run
I have problems with my Makefile
but people can complie and run my program like this

$-Wall -Wextra testNozama.cpp Nozama.cpp Orderqueue.cpp Parser.cpp Time.cpp \
    Fetch.cpp PackerManager.cpp Packer.cpp Statistitian.cpp
$./a.out input.txt 4 ROUND_ROBIN

Data Structure and Algorithm:
1 Orderqueue:
I used a queue structure to store all the orders, in 
shelves (the place where I put all the input orders which got passed in from 
        parser, before they got loaded into fetcher)
fetcher (the fetching unit. Orders should be waiting in line to be processed
         after they arrive)
Packer (in every packing unit, Orders are also waiting in line to be processed)
Records (after orders got processed and unloaded from Packer, they got pickedup 
        by a Statistitian, to update the data and later to complete the report)

The reason why I choose to use queue, is that queue is First Come First Serve
logic.In all of the above senariors, the orders should all obey this order tobe 
processed

Also, I used Double LinkedList to implement the queue, instead of sequence.
Becasue
I don't want to worry about the capacities of the queue too much here.

2. The over all structure of this Simulation

                  Input.txt 
                     |  
                     |                    
            shelves (an Orderqueue)    //read in all the orders from input file,
                     |                  // and store them in shelves 
 The Loop            |
       ---------------------------------- 
                     |                         
                  Fetcher       //check wehter we need to load any orders from
                     |           //shelves and process the topOrder on Fetcher 
                     |
                PackerManager 
                     |            //check wehter we can load any orders from 
         Packer1, Packer2, Packer3   //fetchers, if yes, distribute the order to
                     |            //the right Packers (different method)
                     |
                Statistitian       //check whether any orders is completed
                     |              //load the completed orders into records
        ----------------------------------     //update the stats
                     |
   Statistitian Produces the resulting report 

7.Test

I used different inputs to test the program
1.Empty input.txt ----> This will be finined in 1 minutes
2. only 1 order with different method
3. some regular orders with different method 
4. orders with Empty orders in it 
