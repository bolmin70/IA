# IA

#The Scenario
My client Piotr is a semi-professional cyclist. He attends many racing events and trains very hard in preparation for them. He records his training data by writing it down in a notebook. 
The problem with is that as years went on, more data was added and it got much harder to measure improvements and to make comparisons. The problem here are both the input and the analysis of data.
After his training I talked with Piotr about designing a potential solution1. We agreed that the best solution would be a software that collects training data and allows the user to view it in comparison with his other inputs. 
We decided that Piotr, aside from being my client, will also act as the adviser, since the application features will be tailored to him. The user will be able to see a report of his training results and with that, it will be easier to measure the improvements that he did. 
It will be possible to input the travelled distance, the time the training took, the date, the average speed, the average power and the intensity factor. He said that the program should check if the values are possible to achieve and that they are valid5. 
For example, the software would check if the average speed is below 100 km/h, since anything above that is unattainable. Additionally he asked me to make it so that the software will calculate the user TSS3 and  FTP3. 


#The Rationale for solution
Rationale for the software used
I chose to use C++ as the programming language. I was considering Unity along with C#, but I figured that C++ would be a better fit for the job.
Unity is a game engine and even though it allows to make clean and simple user interfaces, its game making libraries may create additional difficulties that I didn’t account for.
Advantages of using C++
1.	I used it extensively in the past
2.	It is object-oriented allowing me to use the advantages of modularity
3.	It offers great portability, allowing the user to run the same program on different operating systems

Rationale for the product
Piotr told me that he looked for an application like that is the past, however the software he found was either too complicated for him,  it didn’t allow to input all the variables that he wanted to or there were no options for comparing your previous results. 
My solution will solve all of these issues. The application UI will be clear and easy to use, it will input all the data he wants and there will be many comparison options, like comparing the results from last week, month or year.

The Success Criteria
1.	The user can input the following training data: the distance, the time, the date, the average speed, the average power and the intensity factor.
2.	The software calculates the TSS and FTP  from the user inputted data
3.	The software stores the data in a separate database
4.	The software allows to view previous user inputs
5.	The software allows to sort user inputs by date and by performance
6.	The software allows to sort user inputs increasingly or decreasingly
7.	The software prevents the input of invalid data




