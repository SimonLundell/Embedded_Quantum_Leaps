In embedded C, it is common to use macros to define things, this improves readability.

KEYWORD: 
	- volatile : This tells the compiler that the content of the address/variable might change even though it might seem it wont on compile time.
	e.g Address mapped to physical switches that will change the content if you press them.
	Declaring a variable volatile will force the compiler to skip optimization.
