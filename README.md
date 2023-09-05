<h1 align=center>
	<b>42cursus</b>
</h1>

<div align=center>
	<h2>
		<i>Push Swap</i>
	</h2>
	<img src="https://github.com/GiovannaCoqueiro/42cursus-push-swap/assets/115947494/6124a648-a0e1-40fa-a498-5af2e450b55d" alt=push_swap badge/>
	<p align=center>
    		Inside this repository, you can see all the code that has been created for the Push Swap project, including the mandatory part and the bonus part.
	</p>
</div>

---

<div align=center>
	<h2>
		Final score
	</h2>
	<img src="https://github.com/GiovannaCoqueiro/42cursus-so-long/assets/115947494/fabaeaf5-3b12-46fc-af5c-104c03b28526" alt=push_swap grade/>
</div>

---

<h3 align=left>
    Mandatory
</h3>
<p>
  Write a program that sorts in a ascending order a given list of numbers using predefined movements.
</p>
<p>
  At the beginning you have two stacks (A and B) to use. Stack A must be filled with the given list of numbers and stack B must be empty.
</p>

| Movement | How it works |
| :---: | :---: |
| pa | Take the first element at the top of B and put it at the top of A. Do nothing if B is empty. |
| pb | Take the first element at the top of A and put it at the top of B. Do nothing if A is empty. |
| sa | Swap the first 2 elements at the top of stack A. Do nothing if there is only one or no elements. |
| sb | Swap the first 2 elements at the top of stack B. Do nothing if there is only one or no elements. |
| ss | sa and sb at the same time. |
| ra | Shift up all elements of stack A by 1. The first element becomes the last one. |
| rb | Shift up all elements of stack B by 1. The first element becomes the last one. |
| rr | ra and rb at the same time. |
| rra | Shift down all elements of stack A by 1. The last element becomes the first one. |
| rrb | Shift down all elements of stack B by 1. The last element becomes the first one. |
| rrr | rra and rrb at the same time. |

you can run it with:
```sh
  $> ./push_swap <list_of_numbers>
```

<p>
  It must display the list of instructions used to sort the list of numbers.
</p>

---

<h3 align=left>
    Bonus
</h3>
<p>
	Write a checker program to verify if a unsorted list can be sorted with a given list of move instructions.
</p>
  you can run it with:
```sh
  $> ./checker <list_of_numbers>
```
<p>
  And then you'll have to type the list of move instructions you want the program to execute to sort the numbers,. The movemments are only separated by a new line. Pressing "Ctrl+D" finishes the list of instructions. If the list of numbers passed can be sorted with those instructions it will display "OK", if not, "KO". It can also display "Error" in case you type a nonexistent instruction or a invalid list of number.
</p>

---

<h2>
    Instructions to use
</h2>
Clone this repository in you local computer using a terminal:
<ul>
	<li>$> git clone git@github.com:GiovannaCoqueiro/42cursus-push-swap.git [repository_local]</li>
</ul>

After cloning the project in your local reposiory you can run some commands you can find in Makefile:
<ul>
	<li>$> <b>make all:</b> or just <b>make</b> compiles the project</li>
	<li>$> <b>make clean:</b> deletes the object files created during compilation</li>
	<li>$> <b>make fclean:</b> executes the <b>clean</b> command and also deletes the binary created</li>
	<li>$> <b>make re:</b> executes the <b>fclean</b> command followed by the <b>all</b> command</li>
	<li>$> <b>make bonus:</b> compiles the project</li>
	<li>$> <b>make re:</b> executes the <b>fclean</b> command followed by the <b>rebonus</b> command</li>
</ul>
