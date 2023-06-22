it is based on direction
​
from start, we can move left or right
so find those and return the max len
​
but one point i missed, we are missing few branches
so the correct way is to traverse all nodes and do bfs, not just l-r-l paths or r-l-r paths, but all
so we need to reset the steps
​
![image](https://user-images.githubusercontent.com/73538974/247852711-0c4175a9-7d67-4aca-87c2-deb28f32e3a1.png)
​
after we reset, we can traverse and do left and right as usual
****