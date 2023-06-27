condition : no extra space , no modification
time not specified
since no time, we can sort and find -> time consuming
​
let the given array be:
​
![image](https://user-images.githubusercontent.com/73538974/249144726-879ea45c-9228-41be-9ddc-57c0b83f5e4b.png)
​
the idea is similar to linked list cycle, to be precise where the looping exists - [here](https://leetcode.com/problems/linked-list-cycle-ii/)
​
so we can use the tortoise hare approach and find the looping point
​
in order to do that, we need to 2 loops -> 1 to detect the loop and second to traverse the loop
​
![image](https://user-images.githubusercontent.com/73538974/249145421-d42e504b-3280-47d1-b85b-2a4ab8bd725a.png)
​
![image](https://user-images.githubusercontent.com/73538974/249145502-fc6e9658-f453-4779-ba95-202953129573.png)
​
we need to also understand why we are moving from the start, see this diagram:
​
![image](https://user-images.githubusercontent.com/73538974/249145704-92f8f958-3cbb-43ce-bb92-72a2a5bff0a6.png)
​
so definitely it will meet at the loop starting point
​
​