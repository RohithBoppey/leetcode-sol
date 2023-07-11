12345 and k == 2
imagine we are somehow rotating the first k nodes
then the previous is being returned, and the remaining nodes should be combined with the head->next

![image](https://user-images.githubusercontent.com/73538974/252662184-5e0c52a2-55dd-41c4-be2e-5c742036d2a9.png)
![image](https://user-images.githubusercontent.com/73538974/252662299-3aa2109c-6dc8-4a7c-b914-27941f9ef787.png)

and the call should be for next only when it is not null​
