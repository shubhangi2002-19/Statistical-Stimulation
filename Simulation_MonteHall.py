import random
import numpy as Np
random.seed(1)

Rounds = 10000

Wins_with_no_switch = [0]*Rounds
Wins_with_switch = [0]*Rounds

# Simulating Process
for Process in range(0,Rounds):

	Doors = [i for i in range(1,4)]
	Door_with_Prize = random.randint(1,3)
	Door_chosen_by_user = random.randint(1,3)	


	# Now choose a door which is still close
	Door_chosen_by_host = random.randint(1,3)	
	while(Door_chosen_by_host==Door_chosen_by_user or Door_chosen_by_host==Door_with_Prize):
		Door_chosen_by_host = random.randint(1,3)


	# if previously the door which we choose contains prize
	if Door_chosen_by_user==Door_with_Prize:
		Wins_with_no_switch[Process] = 1 


	# switching door
	# as suppose 1, 3 are chosen already then 6 - (1+3) = 2 is remaining door
	Door_chosen_after_switching = 6 - Door_chosen_by_host - Door_chosen_by_user


	if Door_chosen_after_switching==Door_with_Prize:
		Wins_with_switch[Process] = 1


# print("Wins_with_no_switch : ", Wins_with_no_switch)
# print("Wins_with_switch : ", Wins_with_switch)
# print()

print("Probability : [Wins_with_no_switch] : [ ", Np.mean(Wins_with_no_switch)," ]")
print("Probability : [Wins_with_switch] : [ ", Np.mean(Wins_with_switch)," ]")
