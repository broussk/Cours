#!/bin/bash

fact (){
 val=$1
 temp=1

 while [ $val != 1 ]
 do
	 temp=$((temp * val))
	 val=$((val - 1))
 done

 printf "$temp \n"
}

fact $1
