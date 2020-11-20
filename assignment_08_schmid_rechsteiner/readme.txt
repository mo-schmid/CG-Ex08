Computer Grapics - Assignment 08
-------------------------------------------------

Team
	Ralph Rechsteiner
	Moritz Schmid

Part 1:
********
- with the use of the map the lookup to replace the symbols was straight forward.
- reuse of the first function allowed for a simple implementarion of the "expandOnce" function.
- expanding multiple times is just a multiple calling of the expandOnce function.


Part 2:
********
- a switch satement was very helpful to implement the beahaviour for the different symbols.
- by storing all the necessary values (position, direction and state at branches) it was straight forward to generate the line segments. 


Part 3:
********
- Read the exercise description.
- Solve it, I started with figure 6, because it looked very similar to plant_05 -> first guess was directly correct.
- Solved the others with smart try and error, 3, 4 and 5. 3 and 4 were easy, 5 took some iteration to get to the solution.


Part 4:
********
- Pseudocode
- How do I get the probabilities and their expansions?
  -> Use of cout messages, to navigate in iterator based extraction setup.
- How extract element in range vector (stores lower and upper probability border) where the dice probability fits in?
  -> Recap iterator with lambda expressions from slids of C++ course.
- Google how to get index of iterator -> std::distance
- Done.
