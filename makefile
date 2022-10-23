lab1: 
	cd labs/lab1 && make;
	if [ ! -d build ];  then mkdir build; fi
	mv labs/lab1/lab1 build;
	